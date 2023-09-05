class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int currentPtr=0;
        int temp=0;
        int result=0;
        for(int nextPtr=1;nextPtr<prices.size();nextPtr++)
        {
            temp=prices[nextPtr]-prices[currentPtr];
            if(temp>0 && result<temp)
            {
                result=temp;
            }
            if(temp<0)
            {
                currentPtr=nextPtr;
            }
        }
        return result; */

        int profit=0;
        int currentMinimum=prices[0];
        for(int i=1;i<prices.size();i++)
        {
          profit=max(profit,prices[i]-currentMinimum);
          currentMinimum=min(prices[i],currentMinimum);  
        }
        return profit;
    }
};
