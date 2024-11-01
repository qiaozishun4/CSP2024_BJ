#include <bits/stdc++.h>
using namespace std;
int n,k,d,m,t,x,y,cnt;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        a[x][y]='#';
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<k;i++)
        {
            int x1=x,y1=y;
            if(d==0){y1++;}
            else if(d==1){x1++;}
            else if(d==2){y1-=1;}
            else{x1-=1;}

            if(x1<1||x1>n){d=(d+1)%4;continue;}
            if(y1<1||y1>m){d=(d+1)%4;continue;}
            if(a[x1][y1]=='x'){d=(d+1)%4;continue;}
            x=x1;y=y1;
            if(a[x][y]=='#'){continue;}
            a[x][y]='#';cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}