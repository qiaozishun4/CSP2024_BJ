#include<bits/stdc++.h>
using namespace std;
long long n,m,l,vz,d[1000005],v[1000005],a[1000005],p[10000005];
int sum,sum2,t;
bool pd[10000055],c[1000005];
int main()
{

    cin>>t;
    for(int o=1;o<=t;o++)
    {
        sum=0;
        cin>>n>>m>>l>>vz;
        sum2=m;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            c[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            pd[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(v[i]>vz)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(p[j]>=d[i]&&pd[j]==0)
                        {
                            if(c[i]==0)
                            {
                                sum++;
                            }
                            c[i]=1;
                            pd[j]=1;
                        }
                    }
                }
                else
                {
                    if((vz*vz-v[i]*v[i])/a[i]<=l)
                    {
                        for(int j=1;j<=m;j++)
                        {
                            if((vz*vz-v[i]*v[i])/a[i]<=p[j]&&p[j]>=d[i])
                            {
                                if(c[i]==0)
                                {
                                    sum++;
                                }
                                c[i]=1;
                                pd[j]=1;
                            }
                        }
                    }
                }
            }
            else if(a[i]<0)
            {
                if(v[i]>vz)
                {
                    if((vz*vz-v[i]*v[i])/a[i]<=l)
                    {
                        for(int j=1;j<=m;j++)
                        {
                            if((vz*vz-v[i]*v[i])/a[i]>=p[j]&&p[j]>=d[i])
                            {
                                sum++;
                                if(c[i]==0)
                                {
                                    sum++;
                                }
                                c[i]=1;
                                pd[j]=1;
                            }
                        }
                    }
                }
            }
            else
            {
                if(v[i]>vz)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(p[j]>=d[i])
                        {
                            if(c[i]==0)
                            {
                                sum++;
                            }
                            c[i]=1;
                            pd[j]=1;
                        }
                    }
                }
            }
        }
        cout<<sum<<" ";
        for(int i=1;i<=m;i++)
        {
            if(pd[i]==0)
            {
                sum2--;
            }
        }
        cout<<sum2<<endl;
    }
    return 0;
}