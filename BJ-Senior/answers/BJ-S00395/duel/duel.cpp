#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int N = 1e5 + 10;

int n,m;
int a[N],b[N];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
        m = max(m,a[i]);
    }
    int ans = b[1];
    // cout << ans << endl;
    for(int i = 2;i <= m;i++)
    {
        if(b[i] > ans)
        {
            ans = b[i];
        }
        // cout << "* " << i << " ans:" << ans << " b:" << b[i] << endl;
    }
    cout << ans << endl;
    return 0;
}
