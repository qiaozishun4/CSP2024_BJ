#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],cnt[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        cnt[a[i]]++;
    }
    int ans=-1;
    for(int i=0;i<=100000;i++){
        ans=max(ans,cnt[i]);
    }
    cout <<ans;
    return 0;
}
