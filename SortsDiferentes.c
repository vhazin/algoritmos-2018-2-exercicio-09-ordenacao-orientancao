#include <stdio.h>
#include <time.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n){
	int i, j, min_id;
	for (i = 0; i < n-1; i++){
		min_id = i;
		for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_id]){
                min_id = j;
            }
		}
        swap(&arr[min_id], &arr[i]);
	}
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n){
int i, j;
 for (i = 0; i < n-1; i++)
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]){
		largest = l;
    }
    if (r < n && arr[r] > arr[largest]){
		largest = r;
    }
    if (largest != i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}
	for (int i=n-1; i>=0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){
	if (l < r){
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int partition (int arr[], int low, int high){
    int j;
    int i = (low - 1);
    for (j = low; j <= high- 1; j++){
        if (arr[j] <= arr[high]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if (low < high){
		int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size){
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int randomizedPartition (int arr[], int low, int high){
    int i = rand() % (high + 1 - low) + low;
    swap(&arr[low], &arr[i]);
    return partition(arr,low,high);
}

void randomQuickSort(int arr[], int low, int high){
	if (low < high){
		int pi = randomizedPartition(arr, low, high);
        randomQuickSort(arr, low, pi - 1);
		randomQuickSort(arr, pi + 1, high);
	}
}


int main(){
   	int n , x;
   	printf("quantos numeros?\n-> ");
   	scanf("%d",&n);
    int arr[n];
    int base[n];
    for (x=0;x<n;x++){
        arr[x] = rand();
    }
    int temp;
    for (temp = 0;temp<n;temp++){
        base[temp]=arr[temp];
    }
    printf("array inicial\n->");
    printArray(base,n);
    double time_selection=0.0;
   	printf("Selection Sorted array: \n");
    clock_t begin = clock();
	selectionSort(arr, n);
    clock_t end = clock();
	//printArray(arr, n);
    time_selection +=(double)(end - begin)/CLOCKS_PER_SEC;

    for (temp = 0;temp<n;temp++){
        arr[temp]=base[temp];
    }

    double time_insertion=0.0;
    printf("Insertion Sorted array: \n");
    begin = clock();
	insertionSort(arr, n);
    end = clock();
	//printArray(arr, n);
    time_insertion +=(double)(end - begin)/CLOCKS_PER_SEC;

    for (temp = 0;temp<n;temp++){
        arr[temp]=base[temp];
    }

    double time_bubble=0.0;
    printf("Bubble Sorted array: \n");
    begin = clock();
	bubbleSort(arr, n);
    end = clock();
	//printArray(arr, n);
    time_bubble +=(double)(end - begin)/CLOCKS_PER_SEC;

    for (temp = 0;temp<n;temp++){
        arr[temp]=base[temp];
    }

    double time_heapy=0.0;
    printf("Heap Sorted array: \n");
    begin = clock();
	heapSort(arr, n);
    end = clock();
	//printArray(arr, n);
    time_heapy +=(double)(end - begin)/CLOCKS_PER_SEC;

    for (temp = 0;temp<n;temp++){
        arr[temp]=base[temp];
    }

    double time_merge=0.0;
    printf("Merge Sorted array: \n");
    begin = clock();
	mergeSort(arr,0, n);
    end = clock();
	//printArray(arr, n);
    time_merge +=(double)(end - begin)/CLOCKS_PER_SEC;

    for (temp = 0;temp<n;temp++){
        arr[temp]=base[temp];
    }

    double time_quick=0.0;
    printf("Quick Sorted array pivot = ultimo elemento: \n");
    begin = clock();
	quickSort(arr,0, n-1);
    end = clock();
	//printArray(arr, n);
    time_quick +=(double)(end - begin)/CLOCKS_PER_SEC;


   for (temp = 0;temp<n;temp++){
        arr[temp]=base[temp];
    }

    double time_quickRandom=0.0;
    printf("Quick Sorted array pivot = elatorio: \n");
    begin = clock();
	randomQuickSort(arr,0, n-1);
    end = clock();
	//printArray(arr, n);
    time_quickRandom +=(double)(end - begin)/CLOCKS_PER_SEC;

    printArray(arr, n);
    printf("Tempo gasto para %d numeros\n",n);
    printf("Tempo gasto para Selection Sort = %f segundos\n",time_selection);
    printf("Tempo gasto para Insertion Sort = %f segundos\n",time_insertion);
    printf("Tempo gasto para Bubble Sort = %f segundos\n",time_bubble);
    printf("Tempo gasto para Heap Sort = %f segundos\n",time_heapy);
    printf("Tempo gasto para Merge Sort = %f segundos\n",time_merge);
    printf("Tempo gasto para Quick Sort ultimo elemento = %f segundos\n",time_quick);
    printf("Tempo gasto para Quick Sort pivo random = %f segundos\n",time_quickRandom);

	return 0;
}
