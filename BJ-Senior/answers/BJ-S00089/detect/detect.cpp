#include<bits/stdc++.h>
using namespace std;
int d[100001],v[100001],a[100001],p[100001];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int n,m,L,V,cnt=0;
        cin>>n>>m>>L>>V;
        bool flag1=0,flag2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        int maxn=-1;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];

            maxn=max(maxn,p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0&&d[i]<=maxn)
            {
                double vs=1.0*sqrt(v[i]*v[i]+2*a[i]*(maxn-d[i]));
                if(vs>V)
                {
                    cnt++;
                    flag1=1;
                }
            }
            //else if(a[i]<0)
            //{
                //if(v[i]*v[i]+2*a[i]*minn>0)
                //{
                    //double vs=1.0*sqrt(v[i]*v[i]+2*a[i]*minn);
                    //if(vs>V)
                    //{
                    //    cnt++;
                    //    flag2=1;
                    //}
                //}

            //}
            else
            {
                int vs=v[i];
                if(vs>V&&d[i]<=maxn)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<" ";
        if(cnt>0&&flag1==0&&flag2==0)
        {
            cout<<m-1<<endl;
        }
        else if(flag1==1&&flag2==1)
        {
            cout<<m-2<<endl;
        }
        else if(cnt==0)
        {
            cout<<m<<endl;
        }
        else
        {
            cout<<m-1<<endl;
        }
    }
    return 0;
}
