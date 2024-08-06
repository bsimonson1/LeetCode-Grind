
#include <iostream>
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int k = part.length();
        int sub = s.find(part);

        while (sub != string::npos) 
        {
            s.erase(sub, k); 
            sub = s.find(part); 
        }
        
        return s;
        // int k = part.length();
        // string sub = "";
        // for (int i = 0; i < k; i++)
        // {
        //     sub += s[i];
        // }
        // // find the first part where the first letter of the part occurs 
        // for (int i = 0; i < s.size()-k+1;)
        // {
        //     if (sub == part)
        //     {
        //         s.erase(i, k);
        //         i = 0;
        //         sub.erase(0, k);
        //         sub.insert(0, s.substr(0, k));
        //     }
        //     else
        //     {
        //         sub.erase(0, 1);
        //         sub += s[i+k];
        //         i++;
        //     }
        //     if (sub.length() < k)
        //     {
        //         break;
        //     }
        // }
        // return s;
    }
};