#include <bits/stdc++.h>
using namespace std;
int n,r[100008],ans,maxn;
queue<int>q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        maxn=max(maxn,r[i]);
    }
    if(maxn==2){
        int cnt[3]={};
        for(int i=1;i<=n;i++){
            cnt[r[i]]++;
        }
        cout<<max(cnt[1],cnt[2])<<endl;
        return 0;
    }
    sort(r+1,r+n+1);
    q.push(r[1]);
    for(int i=2;i<=n;i++){
        if(r[i]>q.front()){
            q.pop();
            ans--;
        }
        q.push(r[i]);
    }
    cout<<ans<<endl;
    return 0;
}
