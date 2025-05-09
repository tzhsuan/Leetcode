class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int ans=0,tmplast=0,r=0;
            unordered_map<char,int> check;
            while(r<s.size()){
                if(check.find(s[r]) != check.end()){
                    tmplast = (tmplast>check[s[r]]+1)?tmplast:check[s[r]]+1;
                }
                check[s[r]] = r;
                ans = (ans>r-tmplast+1)?ans:r-tmplast+1;
                r++;
            }
            return ans;
        }
    };