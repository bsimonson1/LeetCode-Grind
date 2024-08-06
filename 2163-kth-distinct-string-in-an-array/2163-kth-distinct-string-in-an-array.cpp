#include <iostream>
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<string, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
            std::cout<<arr[i]<<" "<<std::endl;
        }
        int counter = 1;
        for (auto& i : arr)
        {
            if (mp[i] == 1)
            {
                if (counter == k)
                {
                    return i;
                }
                counter++;
            }
        }
        return "";
    }
};