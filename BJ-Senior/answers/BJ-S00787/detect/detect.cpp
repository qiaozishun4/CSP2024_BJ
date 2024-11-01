#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],a[N],v[N];
int p[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,V;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            for(int j=1;j<=m;j++)
            {
                if(d[i]<=p[j]&&v[i]>V) flag=1;
            }
            if(flag==1) cnt++;
        }
        printf("%d %d\n",cnt,m-1);
    }
    return 0;
}
