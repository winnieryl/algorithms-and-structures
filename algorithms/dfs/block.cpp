#include<iostream>
#include<vector>
#include<utility>
#include<unordered_set>
using namespace std;
struct simplePairHash {
    size_t operator()(const pair<int, int>& p)const {
        return p.first ^ p.second;
    }
};
typedef unordered_set<pair<int,int>, simplePairHash> SET;
class Solution {
public:
    constexpr static int matrix_size = 1e6;

    bool dfs(SET& touched, int r, int c, int &limit)
    {
        cout<<limit<<endl;
        if(limit == 0) return true;
        pair<int, int> cur(r, c);
        if(r<0 || r>=matrix_size || c<0 || c >= matrix_size || touched.count(cur) == true) return false;
        touched.insert(cur);

        limit--;

        return dfs(touched, r-1, c, limit)
        || dfs(touched, r+1, c, limit)
        || dfs(touched, r, c-1, limit)
        || dfs(touched, r, c+1, limit);
    }

    bool isEscapePossible(vector<vector<int> >& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.size() < 2) return true;
        int limit = blocked.size() * (blocked.size()-1) / 2 + 1, limit1=limit;
        cout<<"before touched"<<endl;
        SET touched;
        cout<<"here"<<endl;
        for(auto& p:blocked)
        {
            touched.insert(make_pair(p[0], p[1]));
        }

        auto touched1 = touched;
        return dfs(touched, source[0], source[1], limit) && dfs(touched1, target[0], target[1], limit1);
    }


};

int main()
{
    Solution solution;
    vector<vector<int>> blocked = {{1, 0}, {0, 1}};
    vector<int> source = {0, 0};
    vector<int> target = {2, 0};
    cout<<"calling function"<<endl;
    bool res = solution.isEscapePossible(blocked, source, target);

    cout<< res<<endl;

    return 0;
}