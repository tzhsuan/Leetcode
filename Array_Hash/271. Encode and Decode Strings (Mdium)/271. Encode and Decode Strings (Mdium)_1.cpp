class Solution {
    public:
    
        string encode(vector<string>& strs) {
            string s;
            for(string &tmp : strs){
                int num;
                if(tmp.size()<10) num = 1;
                else if(100>tmp.size() && tmp.size()>=10) num=2;
                else num=3;
                s+= to_string(num) + to_string(tmp.size()) + tmp;
            }
            return s;
        }
    
        vector<string> decode(string s) {
            vector<string> ans;
            int size = s.size(),i=0;
            while(i<size){
                int dnum = s[i++] - '0'; //num of digits
                int num = 0;         //num of slice
                while(dnum-->0) num += (s[i++]-'0')*pow(10,dnum);
                ans.push_back(s.substr(i,num));
                i+=num;
            }
            return ans;
        }
    };