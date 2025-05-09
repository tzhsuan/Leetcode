class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans=0,tmph=prices[0],tmpl=prices[0];
            for(int i=0;i<prices.size();i++){
                if(prices[i]>tmph){
                    tmph = prices[i];
                    ans = (ans > tmph - tmpl) ? ans :tmph - tmpl;
                }
                else if(prices[i]<tmpl){
                    tmph= prices[i]; 
                    tmpl= prices[i];
                }
            }
            return ans;
        }
    };