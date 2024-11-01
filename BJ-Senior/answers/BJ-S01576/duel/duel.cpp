//14:41 first rp++
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
inline int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')w=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())x=10*x+ch-'0';
    return x*w;
}
int n,p,a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read(),p=1;
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i)
        if(a[i]>a[p])++p;
    return printf("%d\n",n-p+1),0;
}