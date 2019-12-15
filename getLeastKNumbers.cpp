void GetLeastKNumbers(int* input,int n ,int* output, int k){
    if(input)
    int start = 0; end = n-1;
    int index = 0;
    index = Partiton( intput, start, end);
    while(index != k - 1){
        if(index > k-1)
            index = Partiton(input, start, index - 1);
        
        else: 
            index = Partition(input, index+1, end);
    }
    for(int i = 0; i < k; i++){
        output[i] = intput[i];
    }
}