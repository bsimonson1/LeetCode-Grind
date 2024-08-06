class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // first we want to find the number of ones in the vector
        int numOnes = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 1)
            {
                numOnes++;
            }
        }
        if (numOnes == size || numOnes == 0)
        {
            return 0;
        }
        int sumInWin = 0;
        for (int i = 0; i < numOnes; i++)
        {
            sumInWin += nums[i];
        }
        int maxSum = sumInWin;
        for (int i = numOnes; i < size + numOnes; i++) 
        {  
            sumInWin += nums[i%size] - nums[(i - numOnes)%size];  
            maxSum = std::max(maxSum, sumInWin);  
        }  
        return numOnes - maxSum;
    }
};