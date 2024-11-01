#include<bits/stdc++.h>
using namespace std;
//int a[10] = {7,2,5,5,4,5,6,3,7,6};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k = n/7;
        int x = n-k*7;
        if(x == 0)
        {
            for(int i = 1;i <= k;i++) cout << 8;
        }
        else if(x == 1)
        {
            if(k >= 1)
            {
                cout << 1;
                cout << 0;
                for(int i = 1;i < k;i++) cout << 8;
            }
            else cout << -1;
        }
        else if(x == 2)
        {
            cout << 1;
            for(int i = 1;i <= k;i++) cout << 8;
        }
        else if(x == 3)
        {
            if(k >= 2)
            {
                cout << 2;
                cout << "00";
                for(int i = 1;i <= k-2;i++) cout << 8;
            }
            else if(k == 1) cout << 40;
            else cout << 7;
        }
        else if(x == 4)
        {
            if(k >= 1)
            {
                cout << 2;
                cout << 0;
                for(int i = 1;i < k;i++) cout << 8;
            }
            else cout << 4;
        }
        else if(x == 5)
        {
            cout << 2;
            for(int i = 1;i <= k;i++) cout << 8;
        }
        else if(x == 6)
        {
            cout << 6;
            for(int i = 1;i <= k;i++) cout << 8;
        }
        cout << endl;
    }
    return 0;
}
