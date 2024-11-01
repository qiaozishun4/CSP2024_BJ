#include<iostream>
using namespace std;
char a[1005][1005];
int n,m,k;
bool b[1005][1005];
bool check(int x,int y)
{
    if(x<1||x>n||y<0||y>m)
    {
        return false;
    }
    if(a[x][y]=='x')
    {
        return false;
    }
    return true;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int ans=0;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int p=1;p<=n;p++)
        {
            for(int q=1;q<=m;q++)
            {
                cin>>a[p][q];
                b[p][q]=0;
            }
        }
        ans++;
        b[x][y]=1;
        int x1=x,y1=y;
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(check(x1,y1+1))
                {
                    y1+=1;
                    if(b[x1][y1]==0)
                    {
                        ans++;
                        b[x1][y1]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(check(x1+1,y1))
                {
                    x1+=1;
                    if(b[x1][y1]==0)
                    {
                        ans++;
                        b[x1][y1]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(check(x1,y1-1))
                {
                    y1-=1;
                    if(b[x1][y1]==0)
                    {
                        ans++;
                        b[x1][y1]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==3)
            {

                if(check(x1-1,y1))
                {
                    x1-=1;
                    if(b[x1][y1]==0)
                    {
                        ans++;
                        b[x1][y1]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}