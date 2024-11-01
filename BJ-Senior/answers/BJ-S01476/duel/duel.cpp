#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!q.empty()&&q.front()<a[i]){
            q.pop();
        }
        q.push(a[i]);
    }
    int ans=0;
    while(!q.empty()){
        q.pop();
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
