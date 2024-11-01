#include <bits/stdc++.h>
using namespace std;
int ans[10] = {-1,-1,1,7,4,2,6,8};
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n <= 7)
        {
            cout << ans[n] <<endl;
            continue;
        }
        int len = ceil(n / 7.0);
        if(ceil((n - 2) / 7.0) <= len-1)
        {
            cout << 1 ;
            int num = (len - 1) * 7 + 2 - n;
            for(int i = 1; i <= num; i++)
                cout << 0 ;
            for(int i = 1; i <= len - 1 - num; i++)
                cout << 8 ;
            cout <<"\n";
        }
        else if(ceil((n - 5) / 7.0) <= len-1)
        {
            cout << 2 ;
            int num = (len - 1) * 7 + 5 - n;
            for(int i = 1; i <= num; i++)
                cout << 0 ;
            for(int i = 1; i <= len - 1 - num; i++)
                cout << 8 ;
            cout <<"\n";
        }
        else if(ceil((n - 6) / 7.0) <= len-1)
        {
            cout << 6 ;
            int num = (len - 1) * 7 + 6 - n;
            for(int i = 1; i <= num; i++)
                cout << 0 ;
            for(int i = 1; i <= len - 1 - num; i++)
                cout << 8 ;
            cout <<"\n";
        }
        else
        {
            for(int i = 1; i <= len; i++)
                cout << 8 ;
            cout <<"\n";
        }
    }
    return 0;
}
