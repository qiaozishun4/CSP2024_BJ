#include"bits/stdc++.h"
using namespace std;
int t;
struct car
{
    int d,v,a;
};
bool check(int v,int a,int s,int v)
{
    //s = v*t+0.5
    //
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--)
    {
        int n,m,l,v;
        car c[100010];
        int p[100010];
        cin >> n >> m >> l >> v;
        for(int i = 0;i < n;i++)
            cin >> c[i].d >> c[i].v >> c[i].a;
        for(int i = 0;i < m;i++)
            cin >> p[i];
            int ans;
        for(int i = 0;i < n;i++)
        {
            bool f = 0;
            for(int j ; 0;j < m;j++)
            {
                if(check(c[i].v,c[i].a,p[j]-c[i].d,v))
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
