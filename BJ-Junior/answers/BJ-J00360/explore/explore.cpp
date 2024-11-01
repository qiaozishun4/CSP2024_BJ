#include <bits/stdc++.h>

using namespace std;
const int MAXNM=1e3+4;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
char c[MAXNM][MAXNM];
bool b[MAXNM][MAXNM];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        int n,m,k,x,y,d,s=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        b[x][y]=1;
        while(k--)
        {
            int next_x=x+xx[d];
            int next_y=y+yy[d];
            if(c[next_x][next_y]!='.'||next_x>n||next_y>m) d=(d+1)%4;
            else
            {
                x=next_x;
                y=next_y;
                if(!b[x][y])
                {
                    s++;
                    b[x][y]=1;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
