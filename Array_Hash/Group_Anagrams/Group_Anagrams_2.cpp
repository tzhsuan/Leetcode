class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> set;
            for(const auto &s : strs){
                int key[26] = {0};
                for(const auto c : s){
                    key[c-'a'] += 1; 
                }
                char kkey[26]={};
                for(int i=0;i<26;i++){
                    kkey[i]='a'+key[i]; //notice int->char
                }
                set[kkey].push_back(s);
            }
            vector<vector<string>> ans;
            for(const auto &s: set){
                ans.push_back(s.second); //unordered_map value->.second
            }
            return ans;
        }
    };