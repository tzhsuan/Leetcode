class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size()<1) return 0; //notice
            unordered_map<int,int> umap;
            int lcs=1;
            for(int num:nums){
                if(umap[num]) continue;//exsist 
                //umap[num] records the length of consecutive nums
                if(umap.find(num-1)==umap.end() && umap.find(num+1)==umap.end()){
                    umap[num]=1;   
                    continue;
                }//non-num-non
                else if(umap.find(num+1)==umap.end()){
                    umap[num] = umap[num-umap[num-1]] = umap[num-1]+1;
                    lcs = max(umap[num],lcs);
                    continue;
                }//exsist-num-non 
                //renew the leftest value
                else if(umap.find(num-1)==umap.end()){
                    umap[num] = umap[num+umap[num+1]] = umap[num+1]+1;
                    lcs = max(umap[num],lcs);
                    continue;
                }//non-num-exsist     
                //renew the rightest value    
                umap[num] = umap[num-umap[num-1]] = umap[num+umap[num+1]]
                = umap[num-1] + umap[num+1] +1; //exsist-num-exsist
                //renew the leftest and the rightest value 
                lcs = max(umap[num],lcs);
            }
            return lcs;
        }
    };