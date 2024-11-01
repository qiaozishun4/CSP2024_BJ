#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MXN=1e5+10;
int n;
int r[MXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    int ans=n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(q.size()&&q.front()<r[i]){
            q.pop();
            ans--;
        }
        q.push(r[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
