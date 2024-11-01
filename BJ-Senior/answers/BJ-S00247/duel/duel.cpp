#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int cnt=1;
    b[cnt]++;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            cnt++;
            b[cnt]++;
        }
        else b[cnt]++;
    }
    int ans=n;
    for(int i=2;i<=cnt;i++){
        int x=b[i-1];
        if(b[i]>=x) ans-=x;
        else ans-=b[i];
    }
    cout<<ans;
    return 0;
}
