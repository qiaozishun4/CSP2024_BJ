#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
int n, m, T;
char s[MAXN][MAXN];
int k, x, y, d;
bool check[MAXN][MAXN];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>s[i][j];
                check[i][j]=0;

            }
        }
        while(k)
        {
            //cout<<k<<"\n";
            check[x][y]=1;
            int n_x=x, n_y=y;
            if(d==0) n_y=y+1;
            //cout<<"1..\n";
            if(d==1) n_x=x+1;
            //cout<<"2..\n";
            if(d==2) n_y=y-1;
            //out<<"3..\n";
            if(d==3) n_x=x-1;
            //cout<<"4..\n";
            //printf("x=%d, y=%d, nx=%d, ny=%d, d=%d\n", x, y, n_x, n_y, d);
            if(n_x>=1&&n_x<=n&&n_y>=1&&n_y<=m&&(s[n_x][n_y]=='.'))
            {
                x=n_x, y=n_y;
                //cout<<"5..\n";
            }
            else d=(d+1)%4;
            //cout<<d<<"\n";
            k--;
        }
        check[x][y]=1;
        long long ans=0;
        //cout<<"...\n";
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                ans+=check[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
