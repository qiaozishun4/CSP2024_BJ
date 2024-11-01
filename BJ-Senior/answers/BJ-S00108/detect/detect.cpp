#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,L,V;
int d[100005],v[100005],a[100005],p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>L>>V;
        int flag=true;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)
            {
                flag=false;
            }
            if(v[i]>V)
            {
                ans++;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
        if(flag)
        {
            cout<<ans<<' '<<m-1<<endl;
        }
        else
        {
            cout<<0<<' '<<0<<endl;
        }
    }
    return 0;
}
