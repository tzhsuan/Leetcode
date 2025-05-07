class Solution {
    public:
        int maxArea(vector<int>& heights) {
            int i=0,j=heights.size()-1,ans=0;
            while(i<j){
                ans = ((j-i) * min(heights[i],heights[j]) > ans ) ? (j-i) * min(heights[i],heights[j]) : ans;
                if(heights[i]>heights[j]) j--;
                else i++;
            }
            return ans;
        }
    };