class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int btor = 0;
        for(int i=0;i<n;i++){
             btor = (btor|nums[i]);

        }
        // cout<<btor;
        return f(n-1,btor,0,nums);
    }
    int f(int i,int b,int s,vector<int>& nums){
        if(i<0){
            if(s==b){
                return 1;
            }
            else{
                return 0;
            }
        }
        int nottake = 0+f(i-1,b,s,nums);
        int take = f(i-1,b,s|nums[i],nums);
        return  nottake+take;
    }
};