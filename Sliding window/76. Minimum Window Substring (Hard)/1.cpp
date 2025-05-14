class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> check, target;

        if(t.size()==0) return t;
        pair<int ,int> pos = {0,0};
        for(char c:t) check[c] = 0,target[c]++;
        
        int maxf=INT_MAX,l=0,flag=1;
        for(int r=0;r<s.size();r++){
            flag=1;
            if(check.find(s[r])!=check.end()){
                check[s[r]]++;
            }
            for(auto c:check){
                if(c.second < target[c.first]){
                    flag=0;
                    break;
                }
            }
            while(flag){
                pos = (maxf<r-l+1) ? pos : make_pair(l,r);
                maxf = (maxf<r-l+1)? maxf: r-l+1;
                if(check.find(s[l])!=check.end()){
                    if(check[s[l]]==target[s[l]]){
                        break;
                    }
                    check[s[l]]--;
                }
                l++;
            }
        }
        return (flag == 1) ? s.substr(pos.first,pos.second - pos.first+1) : "";
    }
};