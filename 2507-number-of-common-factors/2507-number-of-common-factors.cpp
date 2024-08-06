class Solution {
public:
    int commonFactors(int a, int b) {
        std::vector<int> af;
        std::vector<int> bf;
        int div = 1;
        while (div <= a)
        {
            if (a % div == 0)
            {
                af.push_back(div);
            }
            div++;
        }
        div = 1;
        while (div <= b)
        {
            if (b % div == 0)
            {
                bf.push_back(div);
            }
            div++;
        }
        int counter = 0;
        sort(af.begin(), af.end());
        sort(bf.begin(), bf.end());
        for (int i = 0; i < af.size(); i++)
        {
            for (int j = 0; j < bf.size(); j++)
            {
                if (af[i] == bf[j])
                {
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }
};