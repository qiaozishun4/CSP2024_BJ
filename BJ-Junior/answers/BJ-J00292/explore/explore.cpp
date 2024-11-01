#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,e;
string a[1005][1005];
int b[1005][1005];
void explore(int i,int j,int q)
{
    k--;
    b[i][j]=1;
    if(k+1==0)
    {
        return;
    }
    if((q==0)&&(y+1<=m)&&(a[x][y+1]=="."))
    {
        explore(x,y+1,q);
    }
    else if((q==1)&&(x+1<=n)&&(a[x+1][y]=="."))
    {
        explore(x+1,y,q);
    }
    else if((q==2)&&(y-1>0)&&(a[x][y-1]=="."))
    {
        explore(x,y-1,q);
    }
    else if((q==3)&&(x-1>0)&&(a[x-1][y]=="."))
    {
        explore(x-1,y,q);
    }
    else explore(x,y,(q+1)%4);
}
int main()
{
    stdin("explore.in",stdin,r);
    stdout("explore.out",stdout,w);
    cin>>T;
    for(int l=1;l<=T;l++)
    {
        cin>>m>>n>>k;
        cin>>x>>y>>d;
        for(int o=1;o<=m;o++)
        {
            for(int p=1;p<=n;p++)
            {
                cin>>a[p][o];
            }
        }
        explore(x,y,d);
        for(int r=1;r<=m;r++)
        {
            for(int s=1;s<=n;s++)
            {
                if(b[s][r]==1)
                {
                    e++;
                    b[s][r]=0;
                }
            }
        }
        cout<<e<<endl;
        e=0;
    }
    return 0;
}
