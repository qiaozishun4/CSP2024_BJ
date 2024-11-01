#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","r",stdout);
    int t,n,m,k,x,y,d,a[1005][1005],ans;
    char s;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        x--;
        y--;
        for(int j=0;j<n;j++)
        {
            for(int kk=0;kk<m;kk++)
            {
                cin>>s;
                if(s=='.')
                {
                    a[j][kk]=1;
                }
                else
                {
                    a[j][kk]=2;
                }
            }
        }
        ans=1;
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(a[x][y+1]%2==1 && x<n && y+1<m)
                {
                    ans++;
                    y++;
                    if(a[x][y]>1)
                    {
                        ans--;
                    }
                    a[x][y]+=2;
                }
                else{
                    d++;
                }
            }
            else if(d==1)
            {
                if(a[x+1][y]%2==1 && x+1<n && y<m)
                {
                    ans++;
                    x++;
                    if(a[x][y]>1)
                    {
                        ans--;
                    }
                    a[x][y]+=2;
                }
                else{
                    d++;
                }
            }
            else if(d==2)
            {
                if(a[x][y-1]%2==1 && x<n && y-1>=0)
                {
                    ans++;
                    y--;
                    if(a[x][y]>1)
                    {
                        ans--;
                    }
                    a[x][y]+=2;
                }
                else{
                    d++;
                }
            }
            else if(d==3)
            {
                if(a[x-1][y]%2==1 && x-1>=0 && y<m)
                {
                    ans++;
                    x--;
                    if(a[x][y]>1)
                    {
                        ans--;
                    }
                    a[x][y]+=2;
                }
                else{
                    d++;
                }
                if(d>3)
                {
                    d=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}