#include<bits/stdc++.h>
using namespace std;
bool b[1002][1002];
char c[1002][1002];
int x1[7]={0,1,0,-1};

int main()
{

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int q;
    cin>>q;
    int y1[7]={1,0,-1,0};
    while(q--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int cnt=1;
        b[x][y]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cin>>c[i][j];
        }
        while(k--)
        {
            if(c[x+x1[d]][y+y1[d]]=='x'||x+x1[d]>n||x+x1[d]<1||y+y1[d]>m||y+y1[d]<1)
            {
                d++;
                d=d%4;

            }
            else
            {
                x=x+x1[d];
                y=y+y1[d];
                cnt++;
                if(b[x][y])cnt--;
                else b[x][y]=true;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                b[i][j]=0;
        cout<<cnt<<endl;
    }
    return 0;
}
