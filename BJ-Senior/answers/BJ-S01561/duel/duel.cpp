#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N];
queue<int> Q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    sort(r+1,r+1+n);
    int ans=n;
    for(int i=1;i<=n;i++){
        if(!Q.empty()&&r[i]>Q.front())ans--,Q.pop();
        Q.push(r[i]);
    }
    cout<<ans;
    return 0;
}
