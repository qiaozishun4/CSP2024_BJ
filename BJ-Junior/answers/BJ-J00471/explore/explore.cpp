#include <bits/stdc++.h>

using namespace std;

int t;
int n,m,k;
int x,y,fd;
int d[3][5]={{0,1,0,-1},{1,0,-1,0}};
char a[1010][1010];
int flag;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>fd;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        if((x+d[0][fd])>=1&&(x+d[0][fd])<=n&&(y+d[1][fd])>=1&&(y+d[1][fd])<=m)
            if(a[x+d[0][fd]][y+d[1][fd]]!='x')
            {
                cout<<2<<endl;
                flag=1;
            }
        if(flag==0)
            cout<<1<<endl;
        flag=0;
    }
    return 0;
}
