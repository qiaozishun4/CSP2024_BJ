#include <bits/stdc++.h>
using namespace std ;

string a[100010] ;
int main()
{
    freopen("poker.in" , "r" , stdin) ;
    freopen("poker.out" , "w" , stdout) ;
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ;i ++)
        cin >> a[i] ;
    sort(a + 1 , a + n + 1 ) ;
    int cnt = 0;
    for(int i = 1 ;i  <= n ; i ++)
    {
        if(a[i] != a[i - 1]) cnt ++ ;
    }
    cout << 52 - cnt << endl;
    return 0 ;
}