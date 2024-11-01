#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
inline int read(){
    int s=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,a[N],b[N],cnt[N],maxn=-1,tmp=0,ans;
bool cmp(int a,int b){return a<b;}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read();ans=n;
    for(int i=1;i<=n;i++){a[i]=read();}
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){tmp++;}
        cnt[tmp]++;b[i]=tmp;maxn=max(maxn,tmp);
    }
    int lst=cnt[1];
    for(int i=2;i<=maxn;i++){
        ans-=min(lst,cnt[i]);
        lst=lst+cnt[i]-min(lst,cnt[i]);
    }
    cout<<ans;
    return 0;
}