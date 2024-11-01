#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int a,x,y,x0,y0,cs,fx,dt[1000][1000],dt2[1000][1000]={},cnt=0;
    char zj;
    cin>>a;
    int answer[a];
    for(int i=1;i<=a;i++)
    {
        cnt=1;
        dt2[1000][1000]={};
        cin>>x>>y>>cs>>x0>>y0>>fx;
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<=y;k++)
            {
                cin>>zj;
                dt[j][k]=1;
                if(zj==120) dt[j][k]=0;
            }
        }
        dt2[x0][y0]=1;
        for(int k=1;k<=cs;k++)
        {
            if(fx=0)
            {
                if(y0>1&&dt[x0][y0-1]==1)
                {
                    y0--;
                }
                else
                {
                    fx++;
                    fx=fx%4;
                    continue;
                }
            }
            if(fx=1)
            {
                if(x0<x&&dt[x0+1][y0]==1)
                {
                    x0++;
                }
                else
                {
                    fx++;
                    fx=fx%4;
                    continue;
                }
            }
            if(fx=2)
            {
                if(y0<y&&dt[x0][y0+1]==1)
                {
                    y0++;
                }
                else
                {
                    fx++;
                    fx=fx%4;
                    continue;
                }
            }
            else
            {
                if(x0>0&&dt[x0-1][y0]==1)
                {
                    x0--;
                }
                else
                {
                    fx++;
                    fx=fx%4;
                    continue;
                }
            }
            dt2[x0][y0]=1;
        }
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<=y;k++)
            {
                if(dt2[j][k]==1) cnt++;
            }
        }
        cnt--;
        answer[i]=cnt;
    }

    for(int i=1;i<=a;i++) cout<<answer[i]<<endl;
    return 0;
}
