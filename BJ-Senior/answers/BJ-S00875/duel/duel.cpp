#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n,ans;
int a[100010],t[100010];

bool cmp(int x,int y){
    return x>y;
}

signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    sort(a+1,a+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            continue;
        }
        if(cnt+t[a[i-1]]>=t[a[i]]){
            cnt+=(t[a[i-1]]-t[a[i]]);
        }
        else{
            ans+=(t[a[i]]-cnt-t[a[i-1]]);
            cnt=0;
        }
    }
    cout<<ans;

    return 0;
}
