class Solution {
    public:
        int characterReplacement(string s, int k) {
            int ans=0,l=0,maxw=0;
            unordered_map<char,int> check;
            for(int r=0;r<s.size();r++){
                check[s[r]]++;
                maxw = (maxw > check[s[r]]) ? maxw :check[s[r]]; //max windows
                while(r-l+1 - maxw > k){ // only larger than the max window then do
                    check[s[l]]--;
                    l++;
                }
                ans = (ans>r-l+1)? ans : r-l+1;
            }
            return ans;
        }
    };
    