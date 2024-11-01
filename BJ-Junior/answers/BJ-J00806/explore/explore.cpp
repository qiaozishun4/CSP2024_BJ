#include<bits/stdc++.h>
using namespace std;
char g[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,sx,sy,i,j,d,ans=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>sx>>sy>>d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }

        while(k--)
        {
            if(d==0)
            {
                if(g[sx][sy+1]=='x'||sx<1||sx>n||(sy+1)<1||(sy+1)>m)
                {
                    d=(d+1)%4;
                    cout<<sx<<" "<<sy<<endl;
                }
                else
                {
                    sy++;
                    ans++;
                    cout<<sx<<" "<<sy<<endl;
                }
            }
            else if(d==1)
            {
                if(g[sx+1][sy]=='x'||(sx+1)<1||(sx+1)>n||sy<1||sy>m)
                {
                    d=(d+1)%4;
                    cout<<sx<<" "<<sy<<endl;
                }
                else
                {
                    sx++;
                    ans++;
                    cout<<sx<<" "<<sy<<endl;
                }
            }
            else if(d==2)
            {
                if(g[sx][sy-1]=='x'||sx<1||sx>n||(sy-1)<1||(sy-1)>m)
                {
                    d=(d+1)%4;
                    cout<<sx<<" "<<sy<<endl;
                }
                else
                {
                    sy--;
                    ans++;
                    cout<<sx<<" "<<sy<<endl;
                }
            }
            else if(d==3)
            {
                if(g[sx-1][sy]=='x'||(sx-1)<1||(sx-1)>n||sy<1||sy>m)
                {
                    d=(d+1)%4;
                    cout<<sx<<" "<<sy<<endl;
                }
                else
                {
                    sx--;
                    ans++;
                    cout<<sx<<" "<<sy<<endl;
                }
            }
        }
        cout<<ans<<endl;
        ans=1;
    }
    return 0;
}
