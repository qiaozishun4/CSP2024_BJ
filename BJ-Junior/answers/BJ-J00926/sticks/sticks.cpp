#include <bits/stdc++.h>
using namespace std;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n;
        int num,numm;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n % 7 == 0)
        {
            num = n / 7;
            for(int j = 1;j <= num;j++)
                cout << 8;
            cout << endl;
            continue;
        }
        else
        {
                num = n / 7 + 1;
                numm = 7 - (n % 7);
                if(numm == 5)
                {
                    cout << 1;
                    for(int j = 1;j <= num - 1;j++)
                        cout << 8;
                    cout << endl;
                    continue;
                }
                if(numm == 6)
                {
                    cout << 10;
                    for(int j = 1;j <= num - 2;j++)
                            cout << 8;
                    cout << endl;
                    continue;
                }
                if(numm == 4)
                {
                    if(num == 1)
                    {
                        cout << 7;
                        cout << endl;
                        continue;
                    }
                    if(num == 2)
                    {
                        cout << 22;
                        cout << endl;
                        continue;
                    }
                    cout << 200;
                    for(int j = 1;j <= num - 3;j++)
                        cout << 8;
                    cout << endl;
                    continue;
                }
                if(numm == 3)
                {
                    if(num == 1)
                    {
                        cout << 4;
                        cout << endl;
                        continue;
                    }
                    cout << 20;
                    for(int j = 1;j <= num - 2;j++)
                        cout << 8;
                    cout << endl;
                    continue;
                }
                if(numm == 2)
                {
                    cout << 2;
                    for(int j = 1;j <= num - 1;j++)
                        cout << 8;
                    cout << endl;
                    continue;
                }
                if(numm == 1)
                {
                    cout << 6;
                    for(int j = 1;j <= num - 1;j++)
                        cout << 8;
                    cout << endl;
                    continue;
                }
        }
    }
    return 0;
}

