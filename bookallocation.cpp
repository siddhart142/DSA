bool isPossible(vector<int> &A,int B,int pos){
    int stu=1,pages=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]>pos) return false;
        if(pages+A[i]>pos)
        {
            stu++;
            pages=A[i]; 
        }
        else
            pages+=A[i];
    }
    //cout<<stu<<" ";
    if(stu>B)
        return false;
    return true;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1; 
    int low = A[0]; 
    int high = 0;
    for(int i = 0;i<A.size();i++) {
        high = high + A[i]; 
        low = min(low, A[i]); 
    }
    int res = -1; 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        //cout << low << " " << high << " " << mid << endl; 
        if(isPossible(A, B , mid)) {
            res = mid; 
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }
    // return res -> this is also correct
    return res; 
}