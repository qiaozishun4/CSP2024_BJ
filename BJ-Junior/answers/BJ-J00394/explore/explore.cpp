#include<iostream>
#include<string.h>
using namespace std;

int m,n;
int address(int i,int j)
{
    return i*m-m+j;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    for(int l=1;l<=T;l++)
    {
        int k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        int amap[n*m+2*n+2*m+4];
        for(int i=0;i<=n*m+n+m+1;i++)amap[i]=0;

        string nmap;
        for(int i=1;i<=n;i++)
        {
            cin>>nmap;
            for(int j=1;j<=m;j++)
            {
                if(nmap[j-1]=='x')amap[address(i,j)]=1;
            }
        }

        int ans=1;
        amap[address(x,y)]=2;
        for(;k>0;k--)
        {
            if(d==0)
            {
                if(amap[address(x,y+1)]!=1&&x>=1&&x<=n&&y+1>=1&&y+1<=m)y++;
                else d=1;
            }
            else if(d==1)
            {
                if(amap[address(x+1,y)]!=1&&x+1>=1&&x+1<=n&&y>=1&&y<=m)x++;
                else d=2;
            }
            else if(d==2)
            {
                if(amap[address(x,y-1)]!=1&&x>=1&&x<=n&&y-1>=1&&y-1<=m)y--;
                else d=3;
            }
            else if(d==3)
            {
                if(amap[address(x-1,y)]!=1&&x-1>=1&&x-1<=n&&y>=1&&y<=m)x--;
                else d=0;
            }

            if(amap[address(x,y)]==0)
            {
                amap[address(x,y)]=2;
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
