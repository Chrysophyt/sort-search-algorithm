#include <iostream>
#include <string>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, int arrSize){ //semua array pass by pointer / adress

    for (int i = 0; i < arrSize-1; i++) { //don't need to check last array so (arrSize - 1)
        //Get current index "i" as the lowest value currently
        int currentMinimumIndex = i;

        for (int j = i+1; j < arrSize; j++) {
            /* if this element is less, then it is the new minimum */
            if (arr[j] < arr[currentMinimumIndex]) {
                //found new minimum, overwrite current minimum
                currentMinimumIndex = j;
            }
        }

        if (currentMinimumIndex != i) {
            swap(arr[i], arr[currentMinimumIndex]);
        }
    }
}

void insertionSort(int *arr, int arrSize){
    int i, key, j;  
    for (i = 1; i < arrSize; i++) {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;
    }  
}

void bubbleSort(int arr[], int n) {  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(arr[j], arr[j+1]);
}  


//----------------Merge Sort-------------------------
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 


//----------------Quick Sort-------------------------
int partition (int arr[], int low, int high) {  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++) {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot) {  
            i++; // increment index of smaller element  
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

void printArray(int arr[], int arrSize, std::string message) {
    std::cout<<"\n" + message + "\n";

    for(int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout<<'\n';

}

int binarySearch(int *arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

int main() {
    int *dynArr = new int[10]; // -> dynArr[10]

    // *(arr) = *(arr + 0) = arr[0] ~ arr[]
    // *(arr + n-1) = arr[n-1]

    int arr[] = {0, 4, 2, 10, -4, 12, 5, 8, -9, 20};
    int n = sizeof(arr)/ sizeof(int); // n = 10

    //----------Sorting Example------------------
    printArray(arr, n, "Sebelum Sorting : ");
    //insertionSort(arr, n);
    //selectionSort(arr, n);
    //bubbleSort(arr, n);
    //mergeSort(arr, 0, n-1);
    quickSort(arr, 0, n-1);
    printArray(arr, n, "Setelah Sorting : ");

    std::cout << "12 ada di Index ke : "<<binarySearch(arr, 0, n-1, 12);
}