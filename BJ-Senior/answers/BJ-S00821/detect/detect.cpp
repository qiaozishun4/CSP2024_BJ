#include <bits/stdc++.h>
using namespace std;
double d[100001],v[100001],a[100001],p[100001],pp[100001];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    double t;
    cin>>t;
    while(t--)
    {
        int n,m,l,cnt=0;
        double V;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++)if(v[i]>V&&p[m]>=d[i])cnt++;
        cout<<cnt<<" "<<m-1<<endl;
    }
}