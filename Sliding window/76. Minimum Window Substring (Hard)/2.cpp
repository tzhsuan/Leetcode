class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> check, target;
        if(t.size()==0 || t.size()>s.size()) return "";
        pair<int ,int> pos = {0,0};
        for(char c:t) target[c]++;

        int maxf=INT_MAX,l=0,have=0,need=target.size();
        for(int r=0;r<s.size();r++){
            check[s[r]]++;
            if(target.find(s[r])!=target.end() && check[s[r]]==target[s[r]]){
                have++;
            }
            while(have == need){
                if(maxf>=r-l+1) pos = make_pair(l,r), maxf = r-l+1;
                if(target.find(s[l])!=target.end()){
                    if(check[s[l]]==target[s[l]]){
                        break;
                    }
                    check[s[l]]--;
                }
                l++;
            }
        }
        return (have == need) ? s.substr(pos.first,pos.second - pos.first+1) : "";
    }
};