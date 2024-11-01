#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,m,k,ans=0;
        cin>>n>>m>>k;
        string s[n];
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        }
        int x,y,d;
        cin>>x>>y>>d;
        x-=1;
        y-=1;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        ans++;


        for(int i=0;i<k;i++)
        {
            int xi=x,yi=y;
            if(d==0)
            {
                yi++;
            }
            if(d==1)
            {
                xi++;
            }
            if(d==2)
            {
                yi--;
            }
            if(d==3)
            {
                xi--;
            }
            if(xi>=0&&xi<n&&yi>=0&&yi<m&&s[xi][yi]!='x')
            {
                x=xi;
                y=yi;
                a[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;
        t--;

    }
    return 0;
}
