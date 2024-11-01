#include <bits/stdc++.h>
using namespace std ;

int len = 0 ;

long long a[100010] ;
int k()
{
    if(len == 1) return -1 ;
    if(len >= 2  && len <= 7) return a[len] ;
    return 0 ;
}
int main()
{
    freopen("sticks.in" , "r" , stdin) ;
    freopen("sticks.out" , "w" , stdout) ;
    a[1] = -1 , a[2] = 1 , a[3] = 7 , a[4] = 4 , a[5] = 2 , a[6] = 6 , a[7] = 8; 
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> len ;
        if(k() != 0)
            cout << k() << endl;
        else 
        {
            if(len % 7 == 0) 
            {
                for(int j = 1 ; j <= len / 7; j ++)
                {
                    cout << 8 ;
                }
                cout << endl;
            }
            else if(len % 7 == 1)
            {
                cout << 10 ;
                int o = (len - 8) / 7 ;
                for(int j = 1 ; j <= o ; j ++)
                {
                    cout << 8 ;
                }
                cout << endl;
            }
            else if(len % 5 == 0)
            {
                for(int j = 1 ; j <= len / 5 ; j ++)
                {
                    cout << 5 ;
                }
                cout << endl;
            }
            else cout << -1 << endl;
        }
    }
    return 0 ;
}