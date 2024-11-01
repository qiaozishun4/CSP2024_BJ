#include<iostream>
using namespace std;
char a[1005][1005];
bool flag[1005][1005]={false};
int main()
{
    int x,y,tx,ty;
    int d=0,n=0,m=0,t=0,k=0;
    int cnt=1;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int l=0;l<t;l++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                flag[i][j]=false;
            }
        }
        flag[x][y]=true;
        //x=x0;
        //y=y0;
        //d=d0;
        for(int i=0;i<k;i++)
        {
            tx=x;
            ty=y;
            if(d==0)
            {
                //tx=x;
                ty+=1;
            }
            else if(d==1)
            {
                tx+=1;
                //ty=y;
            }
            else if(d==2)
            {
                //tx=x;
                ty-=1;
            }
            else
            {
                tx-=1;
                //ty=y;
            }
            if((tx>=1)&&(tx<=n)&&(ty>=1)&&(ty<=m)&&(a[tx][ty]=='.'))
            {
                x=tx;
                y=ty;
                //cout<<flag[x][y]<<" ";
                if(flag[x][y]==false)
                {
                    cnt++;
                    flag[x][y]=true;
                }

            }
            else
            {
                d=(d+1)%4;
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}
