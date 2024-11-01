#include<bits/stdc++.h>
using namespace std;
char map[1000][1000];
int sum[1000];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k,cnt=0;//k-执行次数
        cin>>n>>m>>k;
        int x,y,d;
        //d = 0 代表向东,d = 1 代表向南,d = 2 代表向西,d = 3 代表向北。
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int z=1;z<=m;z++)
            {
                cin>>map[j][z];
            }
        }
        for(int j=1;j<=k;j++)
        {
            int dirx,diry;
            if(d==0)
            {
                dirx=1;
                diry=0;
            }
            if(d==1)
            {
                dirx=0;
                diry=1;
            }
            if(d==2)
            {
                dirx=-1;
                diry=0;
            }
            if(d==3)
            {
                dirx=0;
                diry=-1;
            }
            if(map[x+dirx][y+diry]=='.')
            {
                x+=dirx;
                //cout<<"dir:"<<d<<" x:"<<x<<"->"<<x+dirx<<endl;
                y+=diry;
                //cout<<" y:"<<y<<"->"<<y+diry<<endl;
                cnt++;
            }
            else

            //cout<<"-1 d:"<<d<<"->"<<(d+1)%4<<endl;
                d=(d+1)%4;
            }
            sum[i]+=cnt;
            cnt=0;
        }

    }
    for(int i=1;i<=t;i++)
    {
        cout<<sum[i]<<endl;
    }
    return 0;
}
