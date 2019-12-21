vector<int> two_sum(int target, int a[],int length){
    unordered_map <int, int> m;
    vector<int> res;
    for(int i;i<length;i++) m[a[i]] = i;
    for(int i;i<length;i++){
        int t = target - a[i];
        if(m.count(t) && m[t]!= i){
            res.push_back(i);
            res.push_back(m[t]);
            break;
        }
    }
    return res;
}

int FindDuplicate(vector<int>& nums){
    int low = 1, high=nums.size()-1;
    while(low<high){
        int mid = low+(high - low) * 0.5;
        int cnt = 0;
        for(auto a:nums){
            if(a<=mid) ++cnt;
        }
        if(cnt<=mid) low = mid+1;
        else high = mid;
    }
    return low;
}