class Solution {
    public:
        bool isPalindrome(string s) {
            int i=0,j=s.size()-1;
            while(j>i){
                s[i] = tolower(s[i]);
                s[j] = tolower(s[j]);
                if(!check_alphanum(s[i])){
                    i++;
                    continue;
                }
                if(!check_alphanum(s[j])){
                    j--;
                    continue;
                }
                if(s[i++]!=s[j--]) return false;
            }
            return true;
        }
        bool check_alphanum(char c){
            if((c<='z' && c>='a') || (c<='9'&& c>='0'))
                return true;
            else
                return false;
        }
    };
    