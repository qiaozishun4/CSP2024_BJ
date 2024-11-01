#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int x[21] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 80, 88, 108, 188, 200, 208, 288, 808};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int n, num=0, pos=1;
        cin >> n;
        if(n<=1)
        {
            cout << -1;
            continue;
        }
        while(n)
        {
            if(n<21)
            {
                num += x[n]*pos;
                break;
            }
            else
            {
                num += 8*pos;
                pos++;
                n-=7;
            }
        }
        cout << num << endl;
    }
    return 0;
}

