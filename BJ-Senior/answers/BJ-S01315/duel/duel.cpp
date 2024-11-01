#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,r[MAXN],a[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        m=max(m,r[i]);
        a[r[i]]++;
    }
    int cnt=0,ans=0;
    for(int i=2;i<=m;i++){
        cnt+=a[i-1];
        if(a[i]>=cnt){
            ans+=cnt;
            cnt=0;
        }else{
            ans+=a[i];
            cnt-=a[i];
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
