#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans,last;
queue<int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) q.push(i);
    q.push(n+1);
    while(q.front()!=n+1){
        int p=q.front();
        q.pop();
        last=max(last,q.front());
        for(int i=p;i<q.front()&&last<=n;i++){
            last++;
            ans++;
        }
        if(last==n+1) break;
    }
    cout<<n-ans;
    return 0;
}
