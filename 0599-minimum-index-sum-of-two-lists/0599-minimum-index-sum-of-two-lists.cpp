#include <iostream>
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<std::string, int> mp1;
        std::unordered_map<std::string, int> mp2;
        int lowest = INT_MAX;
        for (int i = 0; i < list1.size(); i++)
        {
            mp1[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++)
        {
            mp2[list2[i]] = i;
        }
        for (auto& i : mp1)
        {
            std::cout<<i.first<< " "<<i.second<<std::endl;
            if (mp2.find(i.first) != mp2.end())
            {
                if ((i.second + mp2.at(i.first)) < lowest)
                {
                    lowest = (i.second + mp2.at(i.first));
                }
            }
        }
        std::vector<std::string> same;
        for (auto& i : mp1)
        {
            if (mp2.find(i.first) != mp2.end())
            {
                if ((i.second + mp2.at(i.first)) == lowest) 
                {
                    same.push_back(i.first);
                }
            }
        }
        return same;
    }
};