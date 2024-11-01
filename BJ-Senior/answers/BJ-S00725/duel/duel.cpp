#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n, a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1,j=0;i<=n;i++){
        if (j+1<i&&a[j+1]<a[i])
            ans++,j++;
    }
    cout << n-ans<<'\n';
    return 0;
}
