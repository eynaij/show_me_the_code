int Partition(int a[], int low, int high){
    int pivot = a[low];
    while(low < high){
        while(low < high && a[high]>pivot) high--;
        a[low] = a[high];
        while(low < high && a[low]<pivot) low++;        
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quick-sort (int a[], int low, int high){
    int index = 0;
    if(low < high){
        index = Partition(a, low, high);
        quick-sort(a, low, index-1);
        quick-sort(a, index+1, high);
    }
}