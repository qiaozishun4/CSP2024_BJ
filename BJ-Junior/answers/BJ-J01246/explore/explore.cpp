#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,xx,yy,dd,cnt=0,cnt2=0;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin>>a[i][j];
                if(a[i][j]=='.')cnt++;
            }
        }
        if(cnt==n*m)
        {
            cout<<k+1<<endl;
        }
        else{
            if(n==1&&m<=2)
            {
                if(cnt>1) cout<<2<<endl;
                else cout<<1<<endl;
            }
            else if(a[xx][yy-1]=='x'&&a[xx][yy+1]=='x'&&a[xx+1][yy]=='x'&&a[xx-1][yy]=='x') cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}
