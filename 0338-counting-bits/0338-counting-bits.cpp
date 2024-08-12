
class Solution {
public:

    vector<int> countBits(int n) {  
        std::vector<int> bin(n+1);
        for (int i = 0; i <= n; i++)
        {
            bin[i] = (__builtin_popcount(i));
        }
        return bin;
    }
};