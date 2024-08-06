#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
        int numCount = nums.size();
        std::vector<std::pair<int, int>> mappedNumAndIndex(numCount);
        std::map<int, int> mp;

        // Populate the mapping map
        for (int i = 0; i < mapping.size(); i++) {
            mp[i] = mapping[i];
        }

        // Process each number in nums
        for (int i = 0; i < numCount; ++i) {
            std::string numStr = std::to_string(nums[i]);
            std::string mappedNumStr = "";

            // Map each digit of the number according to the mapping map
            for (char c : numStr) {
                int digit = c - '0'; // Convert char to int
                mappedNumStr += std::to_string(mp[digit]);
            }

            int mappedNum = std::stoi(mappedNumStr);
            mappedNumAndIndex[i] = {mappedNum, i};
        }

        // Sort based on the mapped number
        std::sort(mappedNumAndIndex.begin(), mappedNumAndIndex.end());

        // Extract the original numbers in the sorted order
        std::vector<int> sortedNums;
        for (const auto& pair : mappedNumAndIndex) {
            sortedNums.push_back(nums[pair.second]);
        }

        return sortedNums;
    }
};
