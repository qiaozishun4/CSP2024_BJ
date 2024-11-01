#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,cot=1;
    string a;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<n+1;i++)
        {
            getline(cin,a);
            for(int j=1;j<m+1;j++)
            {
                mp[i][j]=a[j];
            }
        }
        for(int i=0;i<k;i++)
        {
            mp[x][y]='f';
            if(d=0)
            {
                if(mp[x][y+1]=='x'||y>m)
                {
                    d=(d+1)%4;
                }
                else
                {
                    if(mp[x][y+1]!='f')
                    {
                        cot++;
                    }
                    y=y+1;
                }
            }
            else if(d=1)
            {
                if(mp[x+1][y]=='x'||x>n)
                {
                    d=(d+1)%4;
                }
                else
                {
                    if(mp[x+1][y]!='f')
                    {
                        cot++;
                    }
                    x=x+1;
                }
            }
            else if(d=2)
            {
                if(mp[x][y-1]=='x'||y<1)
                {
                    d=(d+1)%4;
                }
                else
                {
                    if(mp[x][y-1]!='f')
                    {
                        cot++;
                    }
                    y=y-1;
                }
            }
            else if(d=3)
            {
                if(mp[x-1][y]=='x'||x<n)
                {
                    d=(d+1)%4;
                }
                else
                {
                    if(mp[x-1][y]!='f')
                    {
                        cot++;
                    }
                    x=x-1;
                }
            }
        }
        cout<<cot;
    }
    return 0;
}