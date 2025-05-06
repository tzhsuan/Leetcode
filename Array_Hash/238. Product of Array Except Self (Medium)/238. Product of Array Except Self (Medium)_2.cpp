class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> pre(nums.size()+1,1);
            vector<int> post(nums.size()+1,1);
            vector<int> ans(nums.size(),1);
            for(int i=1; i<nums.size();i++){
                pre[i] = nums[i-1]* pre[i-1]; // 0,1,..,n-1,0
            }
            for(int i=nums.size()-1; i>=0;i--){
                ans[i] = pre[i]* post[i+1]; // 0,n-1,...,1,0
                post[i] = nums[i]*post[i+1];
            }
            return ans;
        }
    };