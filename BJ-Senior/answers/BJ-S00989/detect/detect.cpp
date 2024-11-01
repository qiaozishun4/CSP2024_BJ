#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,l,v,ans1;
struct car
{
    int d,v,a,bg,ed;
}c[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;cin>>T;
    for(int iii=0;iii<T;iii++)
    {
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a==0)
            {
                if(c[i].v<=v) continue;
                c[i].bg=c[i].d;
                c[i].ed=l;
            }
        }
        int op[100005]={};
        for(int i=1;i<=m;i++)
        {
            int p;cin>>p;
            for(int j=1;j<=n;j++)
            {
                if(c[j].bg<=p&&c[j].ed>=p) op[i]++;
            }
        }
        sort(op+1,op+m+1);
        ans1=op[m];
        cout<<ans1<<" "<<m-1;
    }
    return 0;
}
