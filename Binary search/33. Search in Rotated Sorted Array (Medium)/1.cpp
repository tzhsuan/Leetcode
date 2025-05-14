class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,m;
        while(l<r){
            m = (l+r)/2;
            if(nums[m] > nums[r]){
                if(target > nums[r] && target <= nums[m]){
                    r = m;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(target > nums[m] && target <= nums[r]){
                    l=m+1;
                }
                else{
                    r=m;
                }                
            }
        }
        return (target == nums[l])? l:-1;
    }
};