#include <bits/stdc++.h>
using namespace std;

int t,n,m,l,vm,s,d[100007],v[100007],a[100007],p[100007];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        s=0;
        cin>>n>>m>>l>>vm;
        for(int i=1;i<=n;i++)  cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)  cin>>p[i];
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++)
        {
            if(v[i]>vm && d[i]<=p[m])  s++;
        }
        if(s==0)  cout<<s<<" "<<m<<endl;
        else cout<<s<<" "<<m-1<<endl;
    }
}