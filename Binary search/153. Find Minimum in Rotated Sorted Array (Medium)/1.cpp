class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1,mid,ans=INT_MAX;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};