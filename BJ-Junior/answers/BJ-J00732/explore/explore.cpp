#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,cnt=0;
char a[1005][1005];
bool judge(long long x,long long y)
{
    if(a[x][y]=='x') return false;
    if(x<1 || x>n || y<1 || y>m) return false;
    return true;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cnt=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        // d = 0,则令 (x ′ , y ′ ) = (x, y + 1)
        // d = 1,则令(x ′ , y ′ ) = (x + 1, y)
        // d = 2,则令 (x ′ , y ′ ) = (x, y − 1)
        // d = 3,则令(x ′ , y ′ ) = (x − 1, y)
        int tx=0,ty=0;
        while(k--)
        {
            if(d==0)
            {
                if(judge(x,y+1))
                {
                    y+=1;
                }
                else d++;
            }
            else if(d==1)
            {
                if(judge(x+1,y))
                {
                    x+=1;
                }
                else d++;
            }
            else if(d==2)
            {
                if(judge(x,y-1))
                {
                    y-=1;
                }
                else d++;
            }
            else if(d==3)
            {
                if(judge(x-1,y))
                {
                    x-=1;
                }
                else d=0;
            }
            if(x!=tx || y!=ty)
            {
                cnt++;
                tx=x;
                ty=y;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
