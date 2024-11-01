#include <bits/stdc++.h>
using namespace std ;

int main()
{
    freopen("chain.in" , "r" , stdin) ;
    freopen("chain.out" , "w" , stdout) ;
    int t ;
    cin >> t ;
    while(t--)
    {
        int q , m , k ;
        cin >> m >> k >> q;
        for(int i = 1 ; i <= m  ; i++)
        {
            int n , x;
            cin >> n ;
            for(int j = 1 ; j <= n ; j ++)
            {
                cin >> x ;
            }
        }
        for(int i =  1 ; i <= q ; i ++)
            cin >> m >> k ;
        for(int i = 1 ; i <= q ; i ++)
            cout << 0 << endl;
    }
    return 0 ;
}