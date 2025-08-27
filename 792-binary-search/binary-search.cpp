class Solution {
private:
    int src(int low,int high,int target,vector<int>& nums){
        if(low>high){
            return -1;
        }
        int mid = low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if( nums[mid]<target){
            return src(mid+1,high,target,nums);
        }
        return src(low,mid-1,target,nums);
    }

public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        // int mid = (low+high)/2;
        return src(low,high,target,nums);
        // if(nums[mid]==target){
        //     return mid;
        // }
        // else if( nums[mid]>target){
        //     return src(mid+1,high,target,nums);
        // }
        // return src(low,mid-1,target,nums);
    }
};