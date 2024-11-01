// 会赢吗？
//14:33 start A
//finish at 14:36
#include <bits/stdc++.h>
#define rep(i,a,b,c)    for(int i=(a),i##end=(b);i<=(i##end);i+=(c))
#define per(i,a,b,c)    for(int i=(a),i##end=(b);i>=(i##end);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define vint vector<int>
using namespace std;

const int maxn=1.2e5;

map<int,int> M;
int a[maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    rep(i,1,n,1){
        int x;cin>>x;
        M[x]++;
    }
    int cc=0;
    for(auto [v,c]:M)   a[++cc]=c;
    int pr=0,su=0;
    per(i,cc,1,1){
        pr-=min(pr,a[i]);
        pr+=a[i];
    }
    cout<<pr<<endl;
    return 0;
}