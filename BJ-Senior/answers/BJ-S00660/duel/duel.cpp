#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd(){
    char ch=getchar();
    int t=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }
    int num=0;
    while('0'<=ch&&ch<='9'){
        num=num*10+(ch-'0');
        ch=getchar();
    }
    return num*t;
}
inline void pt(int x){
    if(x<0){
        putchar('-');
        pt(-x);
    }else if(x>=10){
        pt(x/10);
        putchar((x%10)+'0');
    }else{
        putchar(x+'0');
    }
    return;
}
int num[200010],app[200010];
int q[200010],siz=0;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n=rd();
    for(int i=1;i<=n;i++)num[i]=rd(),app[num[i]]++;
    int ans=0;
    for(int i=1;i<=100010;i++)ans=max(ans,app[i]);
    pt(ans);
    return 0;
}
