#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,ai;
priority_queue <int,vector<int>,greater<int> > q;
queue <int> q2;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",&ai);
        q.push(ai);
    }
    for (int i=1;i<=n;i++){
        if (!q2.empty() && q2.front()<q.top()){
            q2.pop();
        }
        q2.push(q.top());
        q.pop();
    }
    printf("%lld",q2.size());
    return 0;
}
