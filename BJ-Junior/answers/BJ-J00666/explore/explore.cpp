#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int x,y,d0;
char a[1010][1010];
int check[1010][1010] = {0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    for(int i = 1;i <= T;i++)
    {
        memset(check,0,sizeof(check));
        memset(a,0,sizeof(a));
        cin >> n >> m >> k;
        cin >> x >> y >> d0;
        string s;
        for(int j = 1;j <= n;j++)
        {
            cin >> s;
            for(int k = 0;k < m;k++)
                a[j][k+1] = s[k];
        }
        check[x][y] = 1;
        int d = d0;
        for(int j = 1;j <= k;j++)
        {
            if(d == 0)
            {
               // cout << y+1 << " ";
                if(a[x][y+1] == '.' && y+1 <= m)
                {   
                    y++;
                    //cout << y << " ";
                    check[x][y] = 1;
                }
                else if(a[x][y+1] == 'x' || (y+1) > m)
                {
                    d = (d+1) % 4;
                }

            }
            else if(d == 1)
            {
                //cout << x+1 << " ";
                if(a[x+1][y] == '.' && x+1 <= n)
                {   
                    x++;
                    check[x][y] = 1;
                }
                else if(a[x+1][y] == 'x' || (x+1) > n)
                {
                    d = (d+1) % 4;
                }
            }
            else if(d == 2)
            {
                //cout << y-1 << " ";
                if(a[x][y-1] == '.' && y-1 >= 1)
                {   
                    y--;
                    check[x][y] = 1;
                }
                else if(a[x][y-1] == 'x' || (y-1) < 1)
                {
                    d = (d+1) % 4;
                }
            }
            else if(d == 3)
            {
                //cout << x-1 << " ";
                if(a[x-1][y] == '.' && x-1 >= 1)
                {   
                    x--;
                    check[x][y] = 1;
                }
                else if(a[x-1][y] == 'x' || (x-1) < 1)
                {
                    d = (d+1) % 4;
                }
            }
            //cout << d << endl;
        }
        //cout << endl;
        int cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= m;k++)
            {
                //cout << check[j][k] << " ";
                if(check[j][k] == 1)
                    cnt++;
            }
            //cout << endl;
        }
        cout << cnt << endl;
        
    }


    return 0;
}