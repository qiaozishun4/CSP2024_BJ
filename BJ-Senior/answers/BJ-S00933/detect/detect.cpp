#include<bits/stdc++.h>
using namespace std;
int d[100005];//驶入位置
int v[100005];//初速度
int a[100005];//加速度
int p[100005];//检查站的位置
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
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]<=p[m]&&v[i]>V)
            {
                ans++;
            }
        }
        if(ans==0)
        {
            printf("%d %d\n",ans,m);
            continue;
        }
        printf("%d %d\n",ans,m-1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
