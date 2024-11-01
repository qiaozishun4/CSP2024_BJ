#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
struct node {
    int n[9];
    int len;
}dp[115];
bool vis[10]={1,1,1,0,1,0,1,1,1,0};
int w[9]={6,2,5,5,4,5,6,3,7},cnt;
inline void print0 (int x,int l) {
    for (int i=1;i<=l;i++) {
        cout<<x;
    }
    return;
}
inline void print (node x) {
    bool p=0;
    for (int i=1;i<9;i++) {
        if (x.n[i]==0 || !vis[i]) continue;
        if (!p) {
            p=1;
            cout<<i;
            print0(0,x.n[0]);
            print0(i,x.n[i]-1);
        }
        else {
            print0(i,x.n[i]);
        }
    }
    for (int i=1;i<=cnt;i++) cout<<8;
    cout<<'\n';
    return;
}
inline node change (node tmp,int id) {
    tmp.len++;
    tmp.n[id]++;
    return tmp;
}
inline bool cmp (node a,node b) {
    if (a.len!=b.len) return a.len<b.len;
    for (int i=1;i<9;i++) {
        if (!vis[i]) continue;
        if (a.n[i]==0 && b.n[i]==0) continue;
        if (a.n[i]==0 && b.n[i]!=0) return 0;
        if (a.n[i]!=0 && b.n[i]==0) return 1;
        for (int j=0;j<9;j++) {
            if (a.n[j]!=b.n[j]) return a.n[j]<b.n[j];
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        int n;
        cnt=0;
        cin>>n;
        if (n>=100) {
            cnt=(n-100)/7;
            n=100+(n-100)%7;
        }
        for (int i=1;i<=n;i++) {
            dp[i].len=inf;
        }
        for (int i=1;i<9;i++) {
            if (!vis[i]) continue;
            for (int j=w[i];j<=n;j++) {
                if (cmp(change(dp[j-w[i]],i),dp[j])) {
                    dp[j]=change(dp[j-w[i]],i);
                }
            }
        }
        for (int i=6;i<=n;i++) {
            if (cmp(change(dp[i-6],0),dp[i])) {
                dp[i]=change(dp[i-6],0);
            }
        }
        if (dp[n].len==inf) cout<<"-1\n";
        else {
            print(dp[n]);
        }
    }
    return 0;
}
