#include <iostream>
using namespace std;
long long a[10] = {6,2,5,5,4,5,6,3,7,6},n,t,flag;
long long su(long long x)
{
    long long sum = 0;
    if(x >= 100000000)
    {
        sum += a[x / 100000000];
        x %= 100000000;
        sum += a[x / 10000000];
        x %= 10000000;
        sum += a[x / 1000000];
        x %= 1000000;
        sum += a[x / 100000];
        x %= 100000;
        sum += a[x / 10000];
        x %= 10000;
        sum += a[x / 1000];
        x %= 1000;
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 10000000)
    {
        sum += a[x / 10000000];
        x %= 10000000;
        sum += a[x / 1000000];
        x %= 1000000;
        sum += a[x / 100000];
        x %= 100000;
        sum += a[x / 10000];
        x %= 10000;
        sum += a[x / 1000];
        x %= 1000;
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 1000000)
    {
        sum += a[x / 1000000];
        x %= 1000000;
        sum += a[x / 100000];
        x %= 100000;
        sum += a[x / 10000];
        x %= 10000;
        sum += a[x / 1000];
        x %= 1000;
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 100000)
    {
        sum += a[x / 100000];
        x %= 100000;
        sum += a[x / 10000];
        x %= 10000;
        sum += a[x / 1000];
        x %= 1000;
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 10000)
    {
        sum += a[x / 10000];
        x %= 10000;
        sum += a[x / 1000];
        x %= 1000;
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 1000)
    {
        sum += a[x / 1000];
        x %= 1000;
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 100)
    {
        sum += a[x / 100];
        x %= 100;
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 10)
    {
        sum += a[x / 10];
        x %= 10;
        sum += a[x / 1];
        x %= 1;
    }
    if(x >= 1)
    {
        sum += a[x / 1];
        x %= 1;
    }
    return sum;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--)
    {
        flag = 1;
        cin >> n;
        if(n == 1)
        {
            cout << -1 << '\n';
            continue;
        }
        for(register long long i = 1;i <= 100000000;i++)
        {
            if(su(i) == n)
            {
                flag = 0;
                cout << i << '\n';
                break;
            }
        }
        //return 0;
        if(flag)
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}

