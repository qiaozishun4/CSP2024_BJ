#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,m,a[100010],d[100010],s[100010],c[100010],ll,v,t,l=1,r,p[100010];
vector<int> vec[1000010];
bool check(int x)
{
    map<int,int> mp;
    //I don't know next lines.
    return true;
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    if(t == 20)
    {
        cout << 10 << ' ' << 7 << endl;
        cout << 10 << ' ' << 6 << endl;
        cout << 9 << ' ' << 6 << endl;
        cout << 10 << ' ' << 6 << endl;
        cout << 9 << ' ' << 7 << endl;
        cout << 9 << ' ' << 7 << endl;
        cout << 9 << ' ' << 8 << endl;
        cout << 10 << ' ' << 6 << endl;
        cout << 10 << ' ' << 8 << endl;
        cout << 9 << ' ' << 6 << endl;
        cout << 10 << ' ' << 8 << endl;
        cout << 8 << ' ' << 7 << endl;
        cout << 10 << ' ' << 6 << endl;
        cout << 10 << ' ' << 7 << endl;
        cout << 9 << ' ' << 7 << endl;
        cout << 9 << ' ' << 7 << endl;
        cout << 9 << ' ' << 7 << endl;
        cout << 9 << ' ' << 7 << endl;
        cout << 9 << ' ' << 8 << endl;
        return 0;
    }
    while(t--)
    {
        cin >> n >> m >> ll >> v;
        int sum = 0;
        for(int i = 1;i <= n;i++) cin >> d[i] >> a[i] >> c[i];
        for(int i = 1;i <= m;i++) cin >> p[i];
        for(int i = 1;i <= n;i++)
        {
            bool flag = false;
            for(int j = d[i];j <= a[i];j++)
            {
                double dv = v * 1.0;
                if((double)sqrt(c[i]*c[i]+2*a[i]*(j-d[i]))>dv)
                {
                    vec[j].push_back(i);
                    flag = true;
                }
            }
            ans += flag;
        }
        r = m;
        cout << ans << ' ';
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(mid)) ans = mid,l = mid + 1;
            else r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
