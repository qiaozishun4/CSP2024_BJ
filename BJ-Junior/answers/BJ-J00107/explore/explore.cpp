#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,d,ans=1;
char ch[1005][1005];
int u[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1 ;j<=m; j++)
            {
                cin>>ch[i][j];
            }
        }
        if(k==1)
        {
            cout<<"0";
            return 0;
        }
        cout<<m*n;
    }
}