#include<bits/stdc++.h>
using namespace std;
const int N = 200010,oo = 1000010;
int t;
int n,a[N],f[oo];
int minn = oo,maxn = -1;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;++i)
        {
            cin >> a[i];
            ++f[a[i]];
            minn = min(minn,a[i]);
            maxn = max(maxn,a[i]);
        }
        bool d = 0;
        for(int i=minn;i<=maxn;++i)
        {
            if(f[a[i]]>1)
            {
                d = 1;
                break;
            }
        }
        if(!d)
        {
            cout << 0 << endl;
            continue;
        }
    }
    return 0;
}
