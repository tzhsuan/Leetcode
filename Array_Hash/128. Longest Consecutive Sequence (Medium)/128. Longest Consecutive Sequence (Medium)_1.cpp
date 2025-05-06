class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size()<1) return 0; //notice
            sort(nums.begin(),nums.end());
            int lcs=1,tmp=1;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i+1] == nums[i]+1) tmp+=1;
                else if(nums[i+1] == nums[i]){} 
                else{
                    lcs = (tmp>lcs) ? tmp:lcs;
                    tmp = 1;
                } 
            }
            lcs = (tmp>lcs) ? tmp:lcs;
            return lcs;
        }
    };