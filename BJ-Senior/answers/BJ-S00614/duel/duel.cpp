#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=n;
    for (int i=1,j=1;i<=n;i++) {
        if (a[i]>a[j]) {
            j++;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
