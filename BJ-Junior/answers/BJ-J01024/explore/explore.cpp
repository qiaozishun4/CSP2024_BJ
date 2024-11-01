#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int ans[1005][1005];
struct robot
{
    int x,y;
    int d;
}r;
void change(int &x1,int &y1)
{
    if(r.d==0)
    {
        x1=r.x;
        y1=r.y+1;
    }
    if(r.d==1)
    {
        x1=r.x+1;
        y1=r.y;
    }
    if(r.d==2)
    {
        x1=r.x;
        y1=r.y-1;
    }
    if(r.d==3)
    {
        x1=r.x-1;
        y1=r.y;
    }
    return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,i,j;
	cin>>T;
	while(T--)
    {
        for(i=1;i<=1000;i++)
        {
            for(j=1;j<=1000;j++)
            {
                ans[i][j]=0;
            }
        }
        //东0,南1，西2，北3
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        r.x=x0;
        r.y=y0;
        r.d=d0;
        ans[r.x][r.y]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        while(k)
        {
            int x1,y1;
            change(x1,y1);
            if(mp[x1][y1]=='x'||!(x1>=1&&x1<=n)||!(y1>=1&&y1<=m))
            {
                r.d=(r.d+1)%4;
                k--;
                continue;
            }
            r.x=x1;
            r.y=y1;
            k--;
            ans[r.x][r.y]=1;
        }
        int cnt=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cnt+=ans[i][j];
                //cout<<ans[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<cnt<<endl;
    }
	return 0;
}
