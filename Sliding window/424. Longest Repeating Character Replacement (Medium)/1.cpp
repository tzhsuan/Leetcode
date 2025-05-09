class Solution {
    public:
        int characterReplacement(string s, int k) {
            int ans=0;
            unordered_set<char> check(s.begin(),s.end());
            for(char c: check){
                int l=0, count=0;
                for(int r=0;r<s.size();r++){
                    if(s[r] == c){
                        count++;
                    }
                    while(r-l+1 - count > k){
                        if(s[l] == c){
                            count--;
                        }
                        l++;
                    }
                    ans = (ans > r-l+1) ? ans : r-l+1;
                }
            }
            return ans;
        }
    };