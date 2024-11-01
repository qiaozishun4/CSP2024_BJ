#include<bits/stdc++.h>
using namespace std;
string s[1005];
bool p[1005][1005];
int cnt;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        memset(p,0,sizeof(p));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        p[x][y]=1;
        cnt++;
        for(int i=1;i<=n;i++)cin>>s[i],s[i]='x'+s[i],s[i][m+1]='x';
        for(int i=0;i<=m;i++)s[0]+='x',s[n+1]+='x';
        while(k--)
        {
            int x1=x,y1=y;
            if(d==0)y1++;
            if(d==1)x1++;
            if(d==2)y1--;
            if(d==3)x1--;
            if(s[x1][y1]=='x')d++,d&=3;
            else x=x1,y=y1;
            if(!p[x][y])p[x][y]=1,cnt++;
            //cout<<x<<" "<<y<<" "<<d<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
