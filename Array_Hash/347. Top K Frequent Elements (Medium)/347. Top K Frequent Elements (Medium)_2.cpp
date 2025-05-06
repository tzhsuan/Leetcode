class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> tpk;
            for(int num: nums){
                tpk[num]++;
            }
            vector<vector<int>> sortk(nums.size()+1);
            for(const auto &a : tpk){
                sortk[a.second].push_back(a.first);
                //cout << a.second << ": " << a.first<<endl;
            }
            vector<int> ans;
            int s = nums.size();
            while(k>0){
                if(!sortk[s].empty()){
                    for(int tmp: sortk[s]){
                        ans.push_back(tmp);
                        k--;    
                    }
                }
                s--;
            }
            return ans;
        }
    };