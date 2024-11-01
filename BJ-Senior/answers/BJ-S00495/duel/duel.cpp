#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
inline int read(){
    int w = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f*=-1;
        ch = getchar();
    }
    while(isdigit(ch)){
        w = (w <<1) +(w <<3) + (ch^48);
        ch = getchar();
    }

    return w*f;
}
int n,r[N],x,cnt[N],op,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n = read();
    for(int i = 1;i <= n; i ++)
        r[i] = read();
    sort(r+1,r+1+n);
    for(int i = 1; i <= n; i ++){
        if(r[i] == x) cnt[op] ++;
        else cnt[++op] ++;
        x = r[i];
    }
    for(int i = 1; i < op; i ++){
        if(cnt[i+1] >= cnt[i]) cnt[i] = 0;
        else cnt[i] -= cnt[i+1];
        cnt[i+1] += cnt[i];
        cnt[i] = 0;
    }
    for(int i = 1;i <= op; i ++) ans += cnt[i];
    printf("%d",ans);
    return 0;
}