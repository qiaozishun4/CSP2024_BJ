#include<bits/stdc++.h>
using namespace std;
float t,n[21],m[21],l[21],v[21],chao[21],flag[21][1000005];
float cam[21][1000005];
bool shan[21][1000005];
struct node
{
    float st,v,a;
}car[21][100005];
bool check(int i,int j)
{
    float maxx=car[i][j].st+(v[i]*v[i]-car[i][j].v*car[i][j].v)/(2*car[i][j].a);
    if(car[i][j].a>=0)
    {
        for(int y=1;y<=m[i];y++)
        {
            if(maxx<cam[i][y])
            {
                for(int z=1;z<=m[i];z++)
                {
                    if(cam[i][z]>=cam[i][y])
                    {
                        shan[i][z]=1;
                    }
                    else shan[i][z]=0;
                }
                flag[i][j]=cam[i][y];
                return true;
            }
        }
        return false;
    }
    else
    {
        for(int y=m[i];y;y--)
        {
            if(maxx>cam[i][y]&&cam[i][y]>=car[i][j].st)
            {
                for(int z=m[i];z;z--)
                {
                    if(cam[i][z]<=cam[i][y])
                    {
                        shan[i][z]=1;
                    }
                    else shan[i][z]=0;
                }
                return true;
            }
        }
        return false;
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i]>>m[i]>>l[i]>>v[i];
        for(int j=1;j<=n[i];j++)
        {
            cin>>car[i][j].st>>car[i][j].v>>car[i][j].a;
        }
        for(int j=1;j<=m[i];j++)
        {
            cin>>cam[i][j];
        }
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=n[i];j++)
        {
            chao[i]+=check(i,j);
        }
        cout<<chao[i];
    }
    return 0;
}
