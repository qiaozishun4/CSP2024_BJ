#include<bits/stdc++.h>
#define rep(i,S,T) for(int i=S;i<=T;++i)
#define per(i,T,S) for(int i=T;i>=S;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=1e5+10;
int n,a[N],ans;
queue<int> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    read(n);ans=n;
    rep(i,1,n) read(a[i]);
    sort(a+1,a+n+1);
    rep(i,1,n){
        if(!q.empty()&&q.front()<a[i]){
            q.pop();
            ans--;
        }
        q.push(a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*
1 1 1 1 1 1 1 1 2 2
*/
