#include <bits/stdc++.h>
using namespace  std;
int n;
int a[100005];
int v[100005];
int s[100005];
int ma,mi=2e9;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]]++;
        ma=max(ma , a[i]);
        mi=min(mi,a[i]);
    }
    for(int i = 1; i <= ma; i++)
    {
        s[i]=s[i-1]+v[i];
    }
    int cur , minn = 2e9;
    for(int i = 1; i<=ma; i++){
        if(minn >= abs(s[i]-s[ma]/2)){
            cur = i;
            minn = abs(s[i]-s[ma]/2);
        }
    }
    if(s[cur]*2>=s[ma]) cout << max(s[cur],s[ma]-s[cur]);
    else cout << v[a[mi]];
    return 0;
}
