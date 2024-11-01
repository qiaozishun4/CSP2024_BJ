#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,s;
    char a[1005][1005];
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        s=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
            for(int l=1;l<=m;l++)
                cin>>a[j][l];
        int x_=x,y_=y,d_=d;
        a[x][y]='n';
        for(int i=1;i<=k;i++)
        {
            if(d_==0)
            {
                if(a[x_][y_+1]!='x'&&y_!=m)
                {
                    y_++;
                    if(a[x_][y_]=='.')
                    {
                        s++;
                        a[x_][y_]='n';
                    }
                }
                else d_=(d_+1)%4;
            }
            else if(d_==1)
            {
                if(a[x_+1][y_]!='x'&&x_!=n)
                {
                    x_++;
                    if(a[x_][y_]=='.')
                    {
                        s++;
                        a[x_][y_]='n';
                    }
                }
                else d_=(d_+1)%4;
            }
            else if(d_==2)
            {
                if(a[x_][y_-1]!='x'&&y_!=1)
                {
                    y_--;
                    if(a[x_][y_]=='.')
                    {
                        s++;
                        a[x_][y_]='n';
                    }
                }
                else d_=(d_+1)%4;
            }
            else
            {
                if(a[x_-1][y_]!='x'&&x_!=1)
                {
                    x_--;
                    if(a[x_][y_]=='.')
                    {
                        s++;
                        a[x_][y_]='n';
                    }
                }
                else d_=(d_+1)%4;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}