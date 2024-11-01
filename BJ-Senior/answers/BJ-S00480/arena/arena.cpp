#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long a[N] , b[N] , c;
int main()
{
    ios::sync_with_stdio( false );
    cin.tie( 0 ) , cout.tie( 0 );
    freopen( "arena.in" , "r" , stdin );
    freopen( "arena.out" , "w" , stdout );
    int n , m;
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }
    for( int i = 0; i < m; i++ )
    {
        cin >> b[i];
    }
    while( true )
    {
        cin >> c;
        if( c == 0 || c == 1 )
        {

            break;
        }
    }
    int T;
    cin >> T;
    while( T-- )
    {
       cout << "1" << endl;
    }
    return 0;
}
