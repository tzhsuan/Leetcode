class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            unordered_map <string,int> check;
            for(int i=0;i<nums.size()-2;i++){
                int j=i+1,k=nums.size()-1;
                while(j<k){
                    if(nums[i]+nums[j]+nums[k]>0) k--;
                    else if(nums[i]+nums[j]+nums[k]<0) j++;
                    else {
                        string s = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
                        if(check.find(s)!=check.end()){
                            j++;
                            continue;
                        }
                        check[s]=1;
                        ans.push_back({nums[i],nums[j++],nums[k]});
                    }
                }
            }
            return ans;
        }
    };