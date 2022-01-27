#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0) return 0;
        vector<int>next(n,0);
        for(int i = 1, j = 0; i<n; i++)
        {
            while(j>0 && needle[i] != needle[j]) j = next[j-1];
            if(needle[i] == needle[j])
            {
               j++;
            }
            next[i] = j;
        }

        for(int i = 0, j = 0; i<m; i++)
        {
            while(j>0 && haystack[i] != needle[j]) j = next[j-1];
            if(haystack[i] == needle[j])
            {
               j++;
            }
            if(j == n)
            {
                return i-n+1;
            }
        }
        return -1;
    }
};


int main()
{
    Solution solution;
    cout << solution.strStr("hello","ll") << endl;
    return 0;
}
