
class Solution {
public:
    string binaryConversion(int n)
    {
        if (n == 0) return "0";
        std::string binary;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                binary = "1" + binary;;
            }
            else
            {
                binary = "0" + binary;
            }
            n /= 2;
        }
        return binary;
    }
    vector<int> countBits(int n) {  
        std::vector<int> bin;
        for (int i = 0; i <= n; i++)
        {
            bin.push_back(__builtin_popcount(i));
        }
        return bin;
    }
};