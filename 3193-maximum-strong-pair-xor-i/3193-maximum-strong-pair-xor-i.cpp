class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int totalMax = 0;
        for (int i = 0; i < nums.size()-1; i++) 
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (std::abs(nums[i] - nums[j]) <= std::min(nums[i], nums[j])) 
                {
                    int curr1 = nums[i] ^ nums[j];
                    totalMax = std::max(totalMax, curr1);
                }
            }
        }

        return totalMax;
    }
};