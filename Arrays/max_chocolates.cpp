/* You have got 20rs to buy chocolates and chocolates are priced at 1rs each 
shopkeeper also has a special offer where you can exchange 3 wrappers to get another chocolate
calc how many chocolates you'll get for given amount */

#include <iostream>

using namespace std;

// Alternate Method
int alter(int money, int price, int wrap)
{
    if (money < price)
    {
        return 0;
    }

    int choc = money / price;

    choc += (choc - 1) / (wrap - 1);
    return choc;
}

// Traditional Method

int countExtra(int choc, int wrap)
{
    if (choc < wrap)
    {
        return 0;
    }

    int newChoc = choc / wrap; //5 new chocolates

    return newChoc + countExtra(newChoc + choc % wrap, wrap);
}

int countMax(int money, int price, int wrap)
{

    int choc = money / price;

    return choc + countExtra(choc, wrap);
}

int main()
{
    cout << countMax(15, 1, 3);

    cout << alter(15, 1, 3);
    return 0;
}