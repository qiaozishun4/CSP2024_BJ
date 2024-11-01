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
const int N=100;
int n,cnt=52;
string s[N];
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    read(n);
    rep(i,1,n){cin>>s[i];}
    rep(i,1,n){
        if(!mp[s[i]]) cnt--;
        mp[s[i]]=1;
    }
    printf("%d\n",cnt);
    return 0;
}
