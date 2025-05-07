class Solution {
    public:
        bool isPalindrome(string s) {
            int i=0,j=s.size()-1;
            while(j>i){
                s[i] = tolower(s[i]);
                s[j] = tolower(s[j]);
                if(!((s[i]<='z' && s[i]>='a') || (s[i]<='9'&& s[i]>='0'))){
                    i++;
                    continue;
                }
                if(!((s[j]<='z' && s[j]>='a') || (s[j]<='9'&& s[j]>='0'))){
                    j--;
                    continue;
                }
                if(s[i++]!=s[j--]) return false;
            }
            return true;
        }
    };