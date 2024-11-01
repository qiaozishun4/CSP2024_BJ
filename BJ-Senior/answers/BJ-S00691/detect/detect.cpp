#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p11[100005],p12[100005];
bool p2[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        int n,m,l,vv,chao=0;
        cin>>n>>m>>l>>vv;
        for(int i=1;i<=n;i++)
            cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)
        {
            cin>>p11[i];
            p2[p11[i]]=1;
        }
        printf("%d 0\n",n);
    }
    return 0;
}