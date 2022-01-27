#include <stdio.h>
#include <stdlib.h>


int main()
{
    int cents = 0;
    float amount = 0;
    int count = 0;
    int amount_left = 0;
    int coin_values = [25, 10, 5, 1];
    int i;


    amount = .30;
    cents = (int)round(amount*100);
    amount_left = cents;

    for(i = 0; i < sizeof(coin_values); i++)
    {
        while(amount_left >= coin_values[i])
        {
            count++;
            amount_left -= coin_values[i];
        }
    }
    
    printf("You get %d coins\n", count);
    return 0;
}
