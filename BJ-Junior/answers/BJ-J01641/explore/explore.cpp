#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char a[10000][10000];
int b[10000][10000];
int used[10000][10000];
int ans=1;
int main()
{
    cin>>T;
    for(int t=1;t<=T;t++)
    {

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
                b[i][j]=0;
            else
                b[i][j]=1;
        }
        while(k>0)
        {
            if(d==0)
            {
                if(y+1<=n&&b[x][y+1]==0)
                {
                    y+=1;
                    if(used[x][y]!=1)
                    {
                        ans++;
                        used[x][y]=1;
                    }
                }
                else
                    d=(d+1)%4;
                k--;
            }
            else
                if(d==1)
                {
                    if(x+1<=n&&b[x+1][y]==0)
                    {
                        x+=1;
                        if(used[x][y]!=1)
                        {
                            ans++;
                            used[x][y]=1;
                        }
                    }
                    else
                        d=(d+1)%4;
                    k--;
                }
                else
                    if(d==2)
                    {
                        if(y-1<=n&&b[x][y-1]==0)
                        {
                            y-=1;
                            if(used[x][y]!=1)
                            {
                                ans++;
                                used[x][y]=1;
                            }
                        }
                        else
                            d=(d+1)%4;
                        k--;
                    }
                    else
                        if(x-1<=n&&b[x-1][y]==0)
                        {
                            x-=1;
                            if(used[x][y]!=1)
                            {
                                ans++;
                                used[x][y]=1;
                            }
                        }
                        else
                            d=(d+1)%4;
                        k--;
            }
        }
        cout<<ans;
    }
    return 0;
}
