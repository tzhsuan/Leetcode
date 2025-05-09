class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int ans=0,tmp=0,tmplast=0;
            unordered_map<char,int> check;
            for(int i=0;i<s.size();i++){
                if(check.find(s[i]) == check.end()){
                    tmp += 1;
                }
                else{
                    if(tmplast<=check[s[i]]){
                        ans = (ans > tmp) ? ans : tmp;
                        tmplast = check[s[i]]+1;
                        tmp = i-tmplast+1;
                    }
                    else tmp+=1;
                } 
                check[s[i]] = i;
            }
            return (tmp>ans)?tmp:ans;
        }
    };