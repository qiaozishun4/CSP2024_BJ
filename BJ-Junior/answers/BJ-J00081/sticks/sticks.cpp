#include <iostream>
#include <cstdio>
using namespace std;
int d[10] = {6,2,5,5,4,5,6,3,7,6};
int d1[10] = {8,10,18,22,20,28,68};
int db[1005] ;
int f(int n)
{
    int t = n,s = 0;
    while(t > 0)
    {
        s += d[t % 10];
        t /= 10;
    }
    return s;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= 10000000;i++)
    {
        int x = f(i);
        if(!db[x]) db[x] = i;
    }
    while(t--)
    {
        int n;
        cin >> n;
        if(n <= 1)
        {
            cout << "-1\n";
            continue;
        }
        if(n <= 56)
        {
            cout << db[n] << "\n";
            continue;
        }

        cout << d1[n%7];
        for(int i = 1;i*7 + 7 <= n;i++)
        {
            cout << "8";
        }
        cout << "\n";
        continue;

    }
    return 0;
}
