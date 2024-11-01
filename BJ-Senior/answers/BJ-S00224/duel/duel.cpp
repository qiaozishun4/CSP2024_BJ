#include<bits/stdc++.h>
using namespace std;
namespace FastIO{
    inline int read(){
        int x=0,f=1;
        char ch=getchar();
        while(ch>'9'||ch<'0'){
            if(ch=='-') f=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=(x<<1)+(x<<3)+ch-'0';
            ch=getchar();
        }
        return x*f;
    }
    inline void write(int x){
        if(x<0){
            x=-x;
            putchar('-');
        }
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
using FastIO::read;
using FastIO::write;
const int N=1e5+10;
int n,a[N],cnt[N],mx;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        cnt[a[i]]++;
        mx=max(mx,cnt[a[i]]);
    }
    write(mx);puts("");
    return 0;
}