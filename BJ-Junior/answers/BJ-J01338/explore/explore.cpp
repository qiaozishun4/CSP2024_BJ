#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,xnow,ynow,dnow,cnt,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[1005][1005];
bool book[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cnt=0;
        memset(book,0,sizeof(book));
        cin>>n>>m>>k>>xnow>>ynow>>dnow;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        book[xnow][ynow]=1,cnt++;
        while(k--)
        {
            if(a[xnow+dx[dnow]][ynow+dy[dnow]]=='x'||xnow+dx[dnow]<1||xnow+dx[dnow]>n||ynow+dy[dnow]<1||ynow+dy[dnow]>m)
            {
                dnow++;
                dnow%=4;
                continue;
            }
            xnow+=dx[dnow],ynow+=dy[dnow];
            if(!book[xnow][ynow])
            {
                cnt++;
                book[xnow][ynow]=1;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
