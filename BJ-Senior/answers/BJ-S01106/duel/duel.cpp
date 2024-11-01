#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt1=1;
    int cnt2=0;
    int ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            ans+=max(0ll,cnt2-cnt1);
            cnt2+=cnt1;
            cnt1=1;
            if(cnt2>0)cnt2--;
        }
        else{
            cnt1++;
            if(cnt2>0)cnt2--;
        }
    }
    cnt2+=cnt1;
    cout<<cnt2;
    return 0;
}
