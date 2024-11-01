#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],ans,repeat[maxn];
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    int vis[maxn];
    map<int,int>mp;
    int count=1;
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(mp[a[i]]==1){
            repeat[count]=a[i];
            count++;
        }
        mp[a[i]]++;
    }
    count--;
    if(mp.size()==n){
        cout<<0<<endl;
        return;
    }
    sort(repeat+1,repeat+n+1,cmp);
    for(int i=1;i<=count;i++){
        ans+=(mp[repeat[i]]-1)*repeat[i];
    }
    cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}