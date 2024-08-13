#include <iostream>
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<std::string, int> mp1;
        int lowest = INT_MAX;
        std::vector<std::string> same;
        for (int i = 0; i < list1.size(); i++) mp1[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++)
        {
            if ((mp1.find(list2[i]) != mp1.end()) && (mp1.at(list2[i]) + i) < lowest)
            {
                lowest = mp1.at(list2[i]) + i;
                same.clear();
                same.push_back(list2[i]);
            }
            else if ((mp1.find(list2[i]) != mp1.end()) && (mp1.at(list2[i]) + i) == lowest)
            {
                same.push_back(list2[i]);
            }
        }
        return same;
    }
};