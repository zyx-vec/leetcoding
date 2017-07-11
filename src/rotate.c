void rotate(int nums[], int n, int k) {
    if (n < 2 || k % n == 0){
        return ;
    }
    k = k % n;
    int indexOfBackup = n-1;
    int i = indexOfBackup;
    int backup = nums[indexOfBackup];
    for(int count = 1; count  <=n ; count++){
        if(indexOfBackup == (i-k+n) % n){
            nums[i] = backup;
            i--;
            indexOfBackup = i;
            backup=nums[indexOfBackup];  
        }else{
            nums[i] = nums[(i-k+n) % n];
            i = (i-k+n)%n;
        }
    }
}