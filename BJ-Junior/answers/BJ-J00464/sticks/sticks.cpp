#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
            for(int i = 1;i <= n/7;i++)cout << "8";
        else if(n % 7 == 1)
        {
            if(n == 1)cout << "-1";
            else
            {
                n -= 8;
                cout << "10";
                for(int i = 1;i <= n/7;i++)cout << "8";
            }
        }
        else if(n % 7 == 2)
        {
            n -= 2;
            cout << "1";
            for(int i = 1;i <= n/7;i++)cout << "8";
        }
        else if(n % 7 == 3)
        {
            if(n == 3)cout << "7";
            else if(n == 10)cout << "22";
            else
            {
                n -= 17;
                cout << "200";
                for(int i = 1;i <= n/7;i++)cout << "8";
            }
        }
        else if(n % 7 == 4)
        {
            if(n == 4)cout << "4";
            else
            {
                n -= 11;
                cout << "20";
                for(int i = 1;i <= n/7;i++)cout << "8";
            }
        }
        else if(n % 7 == 5)
        {
            n -= 5;
            cout << "2";
            for(int i = 1;i <= n/7;i++)cout << "8";
        }
        else if(n % 7 == 6)
        {
            n -= 6;
            cout << "6";
            for(int i = 1;i <= n/7;i++)cout << "8";
        }
    }
    return 0;
}