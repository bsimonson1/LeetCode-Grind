// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int iter = 0;
        while (iter < n)
        {
            if (isBadVersion(iter))
            {
                return iter;
            }
            iter++;
        }
        return iter;
    }
};