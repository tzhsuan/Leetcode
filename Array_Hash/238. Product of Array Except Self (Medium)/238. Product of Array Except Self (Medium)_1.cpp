class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int sum=1,zeronum = 0;
            for(int num : nums){
                if(num!=0) sum *= num;
                else zeronum += 1;
            }
            for(int i = 0;i<nums.size();i++){
                if(zeronum>1) nums[i] = 0;
                else if(zeronum) nums[i]= (nums[i] == 0) ? sum:0;
                else nums[i] = sum/nums[i];
            }
            return nums;
        }
    };