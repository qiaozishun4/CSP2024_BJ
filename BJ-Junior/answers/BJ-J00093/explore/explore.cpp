#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool book[1005][1001];
int T,i,j;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
                book[i][j]=0;
            }
        int cnt=1;
        book[x][y]=1;
        while(k--)
        {
            if(d==3)//north
            {
                if(a[x-1][y]!='.')
                    d=(d+1)%4;
                else
                    x=x-1;
            }
            else if(d==2)//west
            {
                if(a[x][y-1]!='.')
                    d=(d+1)%4;
                else
                    y=y-1;
            }
            else if(d==1)//south
            {
                if(a[x+1][y]!='.')
                    d=(d+1)%4;
                else
                    x=x+1;
            }
            else if(d==0)//east
            {
                if(a[x][y+1]!='.')
                    d=(d+1)%4;
                else
                    y=y+1;
            }
            if(book[x][y]==0)
            {
                cnt++;
                book[x][y]=1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
