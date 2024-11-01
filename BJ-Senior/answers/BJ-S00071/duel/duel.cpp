#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int n=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) n=n*10+c-'0';
    return n*f;
}
void read(int &n){
    n=0;
    int f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) n=n*10+c-'0';
    n*=f;
}
void write(int x){
    if(x<0){
        putchar('-');
        write(-x);
        return ;
    }
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
int a[100005],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;i=j){
        while(a[j]==a[i]) j++;
        ans=max(ans,j-i);
    }
    cout<<ans<<endl;
    return 0;
}

