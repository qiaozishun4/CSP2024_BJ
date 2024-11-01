#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int cnt[100005];
int maxn;
int last;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cnt[a[i]]++,maxn=max(maxn,a[i]);
    last=0;
    for(int i=1;i<=maxn;i++){
        last-=min(last,cnt[i]);
        last+=cnt[i];
    }
    cout<<last;
}
