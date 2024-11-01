#include <bits/stdc++.h>
using namespace std;
int t;
int n;
// 6 2 5 5 4 5 6 3 7 6
void nx8(int x)
{
    for(int i = 1;i <= x;i++) cout << '8';
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << "-1\n";
            continue;
        }
        if(n == 2)
        {
            cout << "1\n";
            continue;
        }
        if(n == 3)
        {
            cout << "7\n";
            continue;
        }
        if(n == 4)
        {
            cout << "4\n";
            continue;
        }
        if(n == 5)
        {
            cout << "2\n";
            continue;
        }
        if(n == 6)
        {
            cout << "6\n";
            continue;
        }
        if(n == 7)
        {
            cout << "8\n";
            continue;
        }

        if(n % 7 == 0)
        {
            nx8(n / 7);
            cout << '\n';
        }
        if(n % 7 == 1)
        {
            cout << "10";
            nx8(n / 7 - 1);
            cout << '\n';
        }
        if(n % 7 == 2)
        {
            cout << "1";
            nx8(n / 7);
            cout << '\n';
        }
        if(n % 7 == 3)
        {
            cout << "200";
            nx8(n / 7 - 2);
            cout << '\n';
        }
        if(n % 7 == 4)
        {
            cout << "20";
            nx8(n / 7 - 1);
            cout << '\n';
        }
        if(n % 7 == 5)
        {
            cout << "2";
            nx8(n / 7);
            cout << '\n';
        }
        if(n % 7 == 6)
        {
            cout << "6";
            nx8(n / 7);
            cout << '\n';
        }
    }
    return 0;
}