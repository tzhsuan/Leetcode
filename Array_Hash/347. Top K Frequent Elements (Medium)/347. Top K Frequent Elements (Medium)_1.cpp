class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> tpk;
            for(int num: nums){
                tpk[num]++;
            }
            vector<pair<int,int>> sortk;
            for(const auto &a : tpk){
                sortk.push_back({a.second,a.first}); //sort first of pair
            }
            sort(sortk.rbegin(),sortk.rend()); //descending order
            vector<int> ans;
            for(int i=0;i<k;i++){
                ans.push_back({sortk[i].second});
            }
            return ans;
        }
    };