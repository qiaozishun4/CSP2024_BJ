#include <bits/stdc++.h>
using namespace std;
const int b[8]={-1,-1,1,7,4,2,0,8};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        int x = n/7;
        int y = n%7;
        if(y>1)
        {
            cout << b[y];
            for(int i = 1;i <= x;i++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else if(y==0)
        {
            for(int i = 1;i <= x;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else
        {
            y = 8;
            x--;
            cout << "10";
            for(int i = 1;i <= x-1;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}