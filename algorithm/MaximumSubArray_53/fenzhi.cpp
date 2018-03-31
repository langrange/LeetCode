class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        int n = nums.size();
        
        if(n == 0)
        return 0;
        
        if(n == 1)
        return nums[0];
        
        return maxSubArray_help(nums,0,n-1);
    }
    
    int maxSubArray_help(vector<int>& nums,int begin,int end){
    
        if(begin == end)
        return nums[end];
        int mid = (begin + end)>>1;
        /**左边子数组的最大值子数组值*/
        int max_left = maxSubArray_help(nums,begin,mid);
        /**右边子数组的最大值子数组值*/
        int max_right = maxSubArray_help(nums,mid + 1,end);
        /**跨越中点的最大值子数组值*/
        int max_cross = maxCrossMid(nums,begin,mid,end);
        return max(max(max_left,max_right),max_cross);
        
    }
    /*maxCrossMid函数的时间复杂度实际为O(n)*/
    int maxCrossMid(vector<int>& nums,int begin,int mid ,int end){
        int left_max = 0x80000001;//最小的32位整数
        int right_max = 0x80000001;
        int sum = 0;
        /*计算以mid结尾的最大的子数组和，左边子数组*/
        for(int i = mid ;i>=begin;--i){
            sum += nums[i];
            if(sum > left_max)
                left_max = sum;
        }
        sum = 0;
    /*计算以mid+1开始的最大的子数组和，右边子数组*/
        for(int i=mid+1;i<=end;++i){
            sum += nums[i];
            if(sum > right_max)
                right_max = sum;
        }
        return left_max + right_max;
    }
};  int maxSubArray(vector<int>& nums) {
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