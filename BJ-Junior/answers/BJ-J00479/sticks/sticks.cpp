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
int T,n;
string ans;
int ck(int l,int num){
    return l*2<=num&&l*7>=num;
}
int a[]={6,2,5,5,4,5,6,3,7,9};
void solve(){
    read(n);ans="";
    int len=n/7;if(n%7!=0) len++;
    if(n<=1){printf("-1\n");return;}
    rep(i,1,len){
        int st=0;if(i==1) st=1;
        rep(j,st,9){
            if(ck(len-i,n-a[j])){
                ans+='0'+j;
                n-=a[j];
                break;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    read(T);
    while(T--) solve();
    return 0;
}
/*
6 2 5 5 4 5 6 3 7 6
*/
