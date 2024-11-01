#include<bits/stdc++.h>
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
using namespace std;
template<typename A,typename...B>inline void rd(A&x,B&...y){
    cin>>x;
    if constexpr(sizeof...(y))rd(y...);
}
const int N=1e6+33;
int a[N],n;
signed main(){
    file("duel.in","duel.out");
    rd(n);
    fr(i,1,n)rd(a[i]);
    sort(a+1,a+n+1);
    int cnt=0;
    fr(i,1,n){
        int j=i;
        while(j+1<=n&&a[j+1]==a[i])j++;
        fr(_,i,j){
            if(cnt)cnt--;
        }
        cnt+=(j-i+1);
        i=j;
    }
    pt("%d\n",cnt);
    return 0;
}
