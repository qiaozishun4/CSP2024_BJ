#include <bits/stdc++.h>
using namespace std;

int t,n,m,l,V,d[114514],v[114514],a[114514],p[114514],ans;
double temp;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d %d %d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++)scanf("%d %d %d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&p[i]);
        for(int i=1;i<=n;i++)
        {
            if(p[m]>=d[i])
            {
                temp=pow(v[i],2)+(2*a[i]*(p[m]-d[i]));
                if(sqrt(temp)>V)ans++;
            }
        }
        cout << ans << " " << (ans==0?m:m-1) << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}