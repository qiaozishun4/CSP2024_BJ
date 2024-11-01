#include<bits/stdc++.h>
using namespace std;
template<class T>
void read(T&x){
    x=0;T f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=((x<<3)+(x<<1)+(ch&15));
    x=x*f;
}
template<class T,class...Args>
void read(T&x,Args&...args){read(x);read(args...);}
#define FileIO(csp) freopen(csp".in","r",stdin),freopen(csp".out","w",stdout)
#define For(i,x,y) for(int i=(x);(i)<=(y);++i)
#define Rof(i,x,y) for(int i=(x);(i)>=(y);--i)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define chkmax(x,y) x=max((x),(y))
#define chkmin(x,y) x=min((x),(y))
const int N=1e5+5;
int n,a[N]={0},mx=0,ans=0;
signed main(){
    FileIO("duel");
    read(n);
    For(i,1,n){
        int x;
        read(x);
        chkmax(mx,x);
        a[x]++;
    }
    For(i,1,mx)if(a[i])chkmax(ans,a[i]);
    printf("%d",ans);
    return 0;
}