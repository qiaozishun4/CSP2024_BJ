#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005];
long long cnt[100005];
int main(){
    ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    long long maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        maxn=max(maxn,cnt[a[i]]);
    }
    cout<<maxn;
    return 0;
}
