#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct car
{
    int d,v,a;
};

car c[100010];
vector<int> p;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n,m,l,v;
        cin >> n >> m >> l >> v;
        for(int i=1;i<=n;i++)cin >> c[i].d >> c[i].v >> c[i].a;
        int maxn=-1e9;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin >> x;
            p.push_back(x);
            maxn=max(maxn,x);
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i].v>v&&c[i].d<=maxn)cnt++;
        }
        cout << cnt << ' ' << (cnt==0? m:m-1) << endl;
    }
    return 0;
}
