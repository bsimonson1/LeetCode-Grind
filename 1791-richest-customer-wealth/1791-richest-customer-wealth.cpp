class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        int curr = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 0; j < accounts[i].size(); j++)
            {
                curr += accounts[i][j];
            }
            if (curr > max)
            {
                max = curr;
            }
            curr = 0;
        }
        return max;
    }
};