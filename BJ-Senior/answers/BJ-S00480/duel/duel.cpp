#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int r[N];
int vis[N];
int main()
{
    freopen( "duel.in" , "r" , stdin );
    freopen( "duel.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ) , cout.tie( 0 );
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> r[i];
    }
    int x = n;
    sort( r , r + n );
    if( r[n - 1] <= 2 )
    {
        for( int i = 0; i < n; i++ )
        {
            if( r[i] == 2 )
            {
                x = i;
                break;
            }
        }
        int y = n - x;
        cout << max( x , y );
        return 0;
    }
    for( int i = 0; i < n; i++ )
    {
        if( vis[i] == 1 )
        {
            continue;
        }
        for( int j = i + 1; j < n; j++ )
        {
            if( vis[j] == 2 || vis[j] == 1 )
            {
                continue;
            }
            else if( r[j] > r[i] )
            {
                vis[i] = 1;
                vis[j] = 2;
                break;
            }
        }
    }
    int ans = 0;
    for( int i = 0; i < n; i++ )
    {
       if( vis[i] == 2 || vis[i] == 0 )
       {
           ans++;
       }
    }
    cout << ans;
    return 0;
}
