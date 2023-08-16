class Solution {
public:
        /*  The DS we are going to use is Deque(Double Ended Queue)-> We can add or remove  elements from both front and backside */
        /*
        Approach:(Note: We are going to append only the index in the deque)
            Step1:         Create a empty Deque and Append the element from the vector  to the Queue if the Queue is empty.
            Step2:      If the Queue is not empty 2 do the following
                        a) Check the deque front element(index) is equal to (i-k).If it is equal remove the front element. Because the Element wont fit in the window
                        b) After checking the above condition check whether the value at the end of the dequeue is greater than the current index element value.If the value is lesser pop the element until the dequeue element becomes greater than the current index element this will ensure maximum elements is append in the front of dequeue
                        c)If the size of the element hits the window size append the front element to the resultant vector Do the above operation until we reach the end of the vector
                        */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int>d;
            vector<int>ans;
            for(int i=0;i<nums.size();i++)
            {
                if(!d.empty() && d.front()==i-k)    d.pop_front();
                while(!d.empty() && nums[i]>nums[d.back()]) d.pop_back();
                d.push_back(i);
                if(i>=k-1)  ans.push_back(nums[d.front()]);
            }
        return ans;
    }
};
