class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            for(int i=0;i<nums.size()-2;i++){
                int j=i+1,k=nums.size()-1;
                if(nums[i]>0) break;
                if(i>0 && nums[i] == nums[i-1]) continue;
                while(j<k){
                    if(nums[i]+nums[j]+nums[k]>0) k--;
                    else if(nums[i]+nums[j]+nums[k]<0) j++;
                    else {
                        ans.push_back({nums[i],nums[j++],nums[k--]});
                        while(nums[j] == nums[j-1] && j<k) j++;
                    }
                }
            }
            return ans;
        }
    };