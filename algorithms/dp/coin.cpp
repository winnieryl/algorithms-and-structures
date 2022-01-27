#include <stdio.h>
#include <iostream>
// three coins 1, 5, 11
using namespace std;

int main()
{
    int f[105], n, cost;
    f[0] = 0;
    cin >> n;
    for(int i =1; i<=n; i++)
    {
        cost = INT_MAX;
        if(i-1 >= 0) cost = min(cost, f[i-1] + 1);
        if(i-5 >= 0) cost = min(cost, f[i-5] + 1);
        if(i-11 >= 0) cost = min(cost, f[i-11] + 1);
        f[i] = cost;
        cout<<"f["<<i<<"]="<<cost<<endl;
    }
}
