class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size()<1) return 0; //notice
            unordered_map<int,int> umap;
            int lcs=1;
            for(int num:nums){
                if(!umap[num]){
                    umap[num] = umap[num-1]+umap[num+1]+1;
                    umap[num-umap[num-1]] = umap[num];
                    umap[num+umap[num+1]] = umap[num];
                }
                lcs = max(umap[num],lcs);
            }
            return lcs;
        }
    };
    