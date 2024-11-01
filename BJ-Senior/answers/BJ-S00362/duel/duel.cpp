#include<bits/stdc++.h>
using namespace std;
int a[100005];
int hs[100005];
int sy[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        hs[a[i]]++;
        if(hs[a[i]]==1){
            sy[++m]=a[i];
        }
    }
    sort(sy+1,sy+m+1);
    int cnt=0;
    for(int i=1;i<=m;i++){
        cnt=max(0,cnt-hs[sy[i]]);
        cnt+=hs[sy[i]];
    }
    cout<<cnt;
    return 0;
}
