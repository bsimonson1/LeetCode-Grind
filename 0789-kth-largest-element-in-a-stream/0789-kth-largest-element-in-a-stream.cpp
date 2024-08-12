#include <iostream>
class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minH;
    int max;
    KthLargest(int k, vector<int>& nums) {
        max = k;
        for (auto& num : nums)
        {
            minH.push(num);
            if (minH.size() > k)
            {
                minH.pop();
            }
        }
    }
    
    int add(int val) {
        minH.push(val);
        if (minH.size() > max)
        {
            minH.pop();
        }
        return minH.top();
        // stream.push_back(val);
        // std::vector<int> copy;
        // copy = stream;
        // sort(copy.begin(), copy.end(), std::greater<int>());
        // int low = 0;
        // int high = copy.size();
        // while (low <= high) 
        // {
        //     int mid = low + (high - low) / 2;

        //     if (dest == (mid+1))
        //         return copy[mid];

        //     if (mid < dest)
        //         low = mid + 1;

        //     else
        //         high = mid - 1;
        // }
        // return -1;
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
