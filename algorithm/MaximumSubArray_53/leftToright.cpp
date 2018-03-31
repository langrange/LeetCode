  int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        vector<int> sum(n,0);
        sum[0] = nums[0];
        int max_sum = nums[0];
        for(int i=1;i<n;++i){
            /*以nums[i]结尾的最大子数组*/
            sum[i] = max(sum[i-1] + nums[i],nums[i]);
            /*到i为止的最大子数组*/
            max_sum = max(max_sum , sum[i]);
        }
        /*返回到n-1为止的最大子数组，也就是整个数组的最大子数组*/
        return max_sum;
}