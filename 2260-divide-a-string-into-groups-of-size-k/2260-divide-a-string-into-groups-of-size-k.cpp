class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        std::vector<std::string> groups;
        std::string g1 = "";
        int n = s.size();
        int i = 0;
        for (i; i < n; i++)
        {
            g1 += s[i];
            if ((i+1) % k == 0)
            {
                groups.push_back(g1);
                g1 = "";
            }
        }
        if (n % k != 0)
        {
            for (i; i < (k+n-1); i++)
            {
                g1 += fill;
                if ((i+1) % k == 0)
                {
                    groups.push_back(g1);
                    g1 = "";
                }
            }
        }
        return groups;
    }
};