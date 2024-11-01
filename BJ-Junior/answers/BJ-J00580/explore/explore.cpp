#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int dx[4] = { 0 , 1 , 0 , -1 };
int dy[4] = { 1 , 0 , -1 , 0 };
bool vis[N][N];
string s[N];
int main()
{
    freopen( "explore.in" , "r" , stdin );
    freopen( "explore.out" , "w" , stdout );
    int t;
    cin >> t;
    while( t-- )
    {
		memset( vis , 0 , sizeof( vis ) );
		int n , m , k;
		cin >> n >> m >> k;
		int x , y , d;
		cin >> x >> y >> d;
		vis[x][y] = true;
		for( int i = 1; i <= n; i++ )
		{
			cin >> s[i];
		}
		int ans = 1;
		for( int i = 0; i < k; i++ )
		{
			int xx = x + dx[d];
			int yy = y + dy[d];
			//cout << x << " " << y << " " << xx << " " << yy << " " << s[xx][yy] << " " << d << endl;
			if( s[xx][yy - 1] == '.' && xx >= 1 && xx <= n && yy >= 1 && yy <= m )
			{
			    //cout << ans << endl;
				if( !vis[xx][yy] )
				{
					vis[xx][yy] = true;
					ans++;
					x = xx;
					y = yy;
				}
				else
				{
				    vis[xx][yy] = true;
					x = xx;
					y = yy;
				}
			}
			else
			{
				d = ( d + 1 ) % 4;
			}
		}
		cout << ans <<endl;
	}
    return 0;
}
