#include<bits/stdc++.h>
using namespace std;
struct mz
{
    int m=0,n=0,k=0,x0=0,y0=0,d0=0,cnt=1,x1=0,y1=0;
    char mp[1010][1010];
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
}mz[10];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>mz[i].n >>mz[i].m>>mz[i].k >>mz[i].x0>>mz[i].y0>>mz[i].d0;
        mz[i].x1=mz[i].x0;
        mz[i].y1=mz[i].y0;

        //cout<<mz[i].mp[mz[i].x0][mz[i].y0]<<" ";
        for(int j=1;j<=mz[i].n;j++)
        {
            for(int p=1;p<=mz[i].m;p++)
            {
                cin>>mz[i].mp[j][p];
            }
        }
        mz[i].mp[mz[i].x0][mz[i].y0]='*';
        for(int w=0;w<mz[i].k;w++)
        {
            /*int x=0,y=0;
            if(mz[i].d0==0)
            {
                x=0;
                y=1;
            }
            else if(mz[i].d0=1)
            {
                x=+1;
                y=0;
            }
            else if(mz[i].d0==2)
            {
                x=0;
                y=-1;
            }
            else
            {
                x=-1;
                y=0;
            }*/

            if(mz[i].mp[mz[i].dx[mz[i].d0]+mz[i].x0][mz[i].dy[mz[i].d0]+mz[i].y0]!='x'&&mz[i].dx[mz[i].d0]+mz[i].x0>0&&mz[i].dx[mz[i].d0]+mz[i].x0<=mz[i].n &&mz[i].dy[mz[i].d0]+mz[i].y0>0&&mz[i].dy[mz[i].d0]+mz[i].y0<=mz[i].m)
            {

                if(mz[i].mp[mz[i].dx[mz[i].d0]+mz[i].x0][mz[i].dy[mz[i].d0]+mz[i].y0]=='.')
                {
                    mz[i].cnt++;
                }
                mz[i].mp[mz[i].dx[mz[i].d0]+mz[i].x0][mz[i].dy[mz[i].d0]+mz[i].y0]='*';
                mz[i].x0=mz[i].dx[mz[i].d0]+mz[i].x0;
                mz[i].y0=mz[i].dy[mz[i].d0]+mz[i].y0;
            }
            else
            {
                mz[i].d0=(mz[i].d0+1)%4;
            }
           // cout<<mz[i].d0<<" "<<mz[i].x0<<" "<<mz[i].y0<<" "<<mz[i].mp[mz[i].x0][mz[i].y0]<<" "<<mz[i].cnt<<endl;
        }

            cout<<mz[i].cnt<<endl;

    }
    return 0;
}

