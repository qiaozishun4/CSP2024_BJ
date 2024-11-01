#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,L,V;
int d[100005],v[100005],a[100005];
int p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int k=1;k<=t;++k)
    {
        int ans1=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;++i)
        {
            cin>>p[i];
        }
        int panduan1=1;
        int panduan2=1;
        int panduan3=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==0)
            {
                panduan2=0;
                panduan3=0;
                if(v[i]>V&&p[m]>=d[i])
                {
                    ans1++;
                }
            }
            else
            {
                panduan1=0;
                panduan3=0;
                if(a[i]>0)
                {
                    int tt=v[i]*v[i]+2*a[i]*(p[m]-d[i]);
                    if(V<sqrt(tt)&&d[i]<=p[m])
                        ans1++;
                }
                if(a[i]<0)
                {
                    panduan1=0;
                    panduan2=0;
                }
            }
        }
        if(panduan1==1)
        {
            if(ans1==0)
            {
                cout<<ans1<<" "<<m<<endl;
            }
            else
            {
                cout<<ans1<<" "<<m-1<<endl;
            }
        }
        else if(panduan2==1)
        {
            if(ans1!=0)
            {
                cout<<ans1<<" "<<m-1<<endl;
            }
            else
            {
                cout<<ans1<<" "<<m<<endl;
            }
        }
        else
        {
            cout<<ans1<<" "<<m-5<<endl;
        }
    }
    return 0;
}
