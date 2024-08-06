class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size = nums.size();
        int onescount = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 1)
            {
                onescount++;
            }
        }
        if (onescount == 0)
        {
            return 0;
        }
        else if (onescount == size)
        {
            return 0;
        }
        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;
        for (int i = 0; i < onescount; ++i) 
        {
            currentOnesInWindow += nums[i];
        }
        maxOnesInWindow = currentOnesInWindow;

        for (int i = onescount; i < size + onescount; ++i) 
        {
            currentOnesInWindow += nums[i % size] - nums[(i - onescount) % size];
            maxOnesInWindow = std::max(maxOnesInWindow, currentOnesInWindow);
        }

        return onescount - maxOnesInWindow;
    }
};