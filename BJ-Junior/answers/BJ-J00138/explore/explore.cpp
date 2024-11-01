#include <bits/stdc++.h>
using namespace std;
char a[10010][10010];
bool vis[10010][10010];
int xi[10] = {0 , 1 , 0 , -1};
int yi[10] = {1 , 0 , -1 , 0};
int main()
{
    freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int T;
	scanf("%d" , &T);
	while(T--)
    {
        //memset
        int n , m , k;
        scanf("%d %d %d" , &n , &m , &k);
        int x , y , d;
        scanf("%d %d %d" , &x , &y , &d);
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= m ; j ++)
            {
                cin >> a[i][j];
            }
        }
        vis[x][y] = true;
        for(int i = 1 ; i <= k ; i ++)
        {
            int ax = x + xi[d];
            int ay = y + yi[d];
            if(a[ax][ay] == '.' && ((1 <= ax && ax <= n) && (1 <= ay &&  ay <= m)))
            {
                x += xi[d];
                y += yi[d];
            }
            else
            {
                d = (d + 1) % 4;
            }
            vis[x][y] = true;
            //cout << x << " " << y << endl;
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= m ; j ++)
            {
                if(vis[i][j] == true)
                {
                    cnt ++;
                }
                a[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        printf("%d\n" , cnt);
    }
	return 0;
}
