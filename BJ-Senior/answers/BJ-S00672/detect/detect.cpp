#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,l,V;
int d[100010],v[100010],a[100010],p[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        bool fla=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)
                fla=1;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        if(n<=20&&m<=20)//1 2
        {
            bool x[25][25]={};
            int y[25]={};
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(d[i]<=p[j])
                    {
                        //cout<<d[i]<<' '<<p[j]<<' '<<1.0*v[i]+2.0*a[i]*1.0*(p[j]-d[i])-0.01<<endl;
                        if(1.0*v[i]*v[i]+2.0*a[i]*1.0*(p[j]-d[i])-0.01>=V*V)
                        {
                            x[i][j]=1;
                            y[j]++;
                        }
                    }
                }
            }
            int nn=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(x[i][j])
                    {
                        nn++;
                        break;
                    }
                }
            }
            int che[25]={};
            for(int sdf=1;sdf<=m;sdf++)
            {
                int maxx=0,id=-1;
                for(int i=1;i<=m;i++)
                {
                    if(y[i]>maxx)
                    {
                        maxx=y[i];
                        id=i;
                    }
                }
                //cout<<id<<endl;
                for(int i=1;i<=n;i++)
                {
                    if(x[i][id]==1)
                    {
                        che[i]=1;
                        che[24]++;
                        //cout<<i<<endl;
                        for(int j=1;j<=m;j++)
                        {
                            if(x[i][j]==1)
                            {
                                x[i][j]=0;
                                y[j]--;
                            }
                        }
                    }
                }
                if(che[24]==nn)
                {
                    cout<<nn<<' '<<m-sdf<<endl;
                    break;
                }
            }
        }
        else if(fla==0)
        {
            int nn=0;
            for(int i=1;i<=n;i++)
            {
                if(v[i]>V&&d[i]<=p[m])
                {
                    nn++;
                }
            }
            if(nn>0)
            {
                cout<<nn<<' '<<m-1<<endl;
            }
            else
            {
                cout<<nn<<' '<<m<<endl;
            }
        }
        else
        {
            int nn=0;
            for(int i=1;i<=n;i++)
            {
                if((1.0*v[i]*v[i]+2.0*a[i]*1.0*(1.0*p[m]-d[i]))-0.001>1.0*V*V)
                {
                    nn++;
                }
            }
            if(nn>0)
            {
                cout<<nn<<' '<<m-1<<endl;
            }
            else
            {
                cout<<nn<<' '<<m<<endl;
            }
        }
    }
}

















































/*#include <iostream>

using namespace std;
int T;
int n,m,l,v;
int d[100010],v[100010],a[100010];
int ll[1000010];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>dd>>vv>>aa;
            if((vv>v)||((vv*vv+2*aa*(l-dd)))>v)//hui
            {
                if(aa>0)
                {
                    double t=1.0*(v-vv)/aa;
                    int s=v*t+0.5*aa*t*t+0.99999;
                    ll[s+dd]++;
                }
                else if(aa=0)
                {
                    ll[dd]++;
                }
                else
                {
                    double t=1.0*(v-vv)/aa;
                    int s=v*t+0.5*aa*t*t;
                    ll[dd]++;
                    ll[dd+s]--;
                }
            }
        }
        for(int i=1;i<=l;i++)
        {
            ll[i]+=ll[i-1];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p;
        }
    }
    return 0;
}
*/
