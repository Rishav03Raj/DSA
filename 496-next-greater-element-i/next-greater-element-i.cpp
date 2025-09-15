class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i:nums1){
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==i){
                    while(j<nums2.size() && nums2[j]<=i){
                        j++;
                    }
                    if(j==nums2.size()){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(nums2[j]);
                    }
                }
                else continue;
            }
        }
        return ans;
    }
};