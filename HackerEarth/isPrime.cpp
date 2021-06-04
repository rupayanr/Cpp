#include <iostream>
using namespace std;

bool isPrime(int n)
{

    if (n == 1)
    {
        return false;
    }

    // using property that for sqrt(N) where N = a*b, a or b will be smaller that sqrt(n)
    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n, t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        if (isPrime(n))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}