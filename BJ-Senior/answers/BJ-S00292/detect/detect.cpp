#include <bits/stdc++.h>
using namespace std;
long long n,m,L,V,T,i,j,k,p[500009];
struct aaa{
    long long d,v,a,s,l,be,id;//begin
} f[500009];
bool cmp1(aaa x,aaa y)
{
    return x.d<y.d;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >>T;
    while(T--)
    {
        k=0;
        long long flag=0;
        j=0;
        cin >>n >> m >>L >>V;
        for(i=1;i<=n;i++)
        {
            cin >>f[i].d >> f[i].v >> f[i].a;
            f[i].id=i;
            if(f[i].a<0)
            {

                f[i].l=-1;
                if(f[i].v<=V) f[i].s=L+114,f[i].l=1,j++;
                else
                {
                    int g=0;
                    f[i].s=(V*V-f[i].v*f[i].v)/(2*f[i].a)+f[i].d;
                    for(int o=1;o<=m;o++)
                {
                    if(p[o]>=f[i].d&&f[i].d>=f[i].s)
                    g=1;
                }
                if(g==0)
                {
                    j++;
                }
                }
            }else if(f[i].a==0){

                if(f[i].v<=V) f[i].s=L+114,f[i].l=1,j++;
                else f[i].s=f[i].d,f[i].l=1;
                {

                if(f[i].s<=p[m])
                    j++;

                }
            }else{

                f[i].l=1;
                f[i].s=(V*V-f[i].v*f[i].v)/(2*f[i].a)+f[i].d;
                int g=0;
                for(int o=1;o<=m;o++)
                {
                    if(p[o]<=f[i].d&&f[i].d<=f[i].s)
                    g=1;
                }
                if(g==0)
                {
                    j++;
                }
            }
        }
        cout << n-j+1  << ' '<<1;
    }

    return 0;
}
