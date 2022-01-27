#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(x,y) (x) < (y) ? (x) : (y)
int dynamic_coin_changing(int *coins, int coin_num, int amount)
{
    // all elements should be zero except the first cow from 1:end;
    int result = -1;
    int *dp[coin_num+1];
    int i, j;
    for(i=0;i<coin_num+1;i++)
        dp[i]= (int *)calloc((amount+1), sizeof(int));
    for(i=1;i<amount+1;i++)
        dp[0][i] = INT_MAX;
    // fill the matrix
    for(i=1;i<coin_num+1;i++)
    {
        for(j=0;j<coins[i-1];j++)
            dp[i][j] = dp[i-1][j];
        for(j=coins[i-1];j<amount+1;j++)
            dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);  
    }
    result = dp[coin_num][amount];
    // free memory
    for(i=0;i<coin_num+1;i++)
        free(dp[i]);
    return result;
}



int dynamic_coin_changing_simple(int *coins, int coin_num, int amount)
{
    int *dp = (int *)calloc(amount+1, sizeof(int));
    int i, j, result;
    for(i=1;i<amount+1;i++)
        dp[i] = INT_MAX;
    for(i=1;i<coin_num+1;i++)
    {
        for(j=coins[i-1];j<amount+1;j++)
            dp[j]=min(dp[j-coins[i-1]]+1, dp[j]);
    }
    result = dp[amount];
    free(dp);
    return result;
}

int main()
{
    int coins[] = {1, 3, 4};
    printf("min coin number is: %d\n", dynamic_coin_changing(coins, sizeof(coins)/sizeof(int), 18));
    printf("using simple algorithm: min coin number is: %d\n", dynamic_coin_changing_simple(coins, sizeof(coins)/sizeof(int), 18));
    return 0;    
}
