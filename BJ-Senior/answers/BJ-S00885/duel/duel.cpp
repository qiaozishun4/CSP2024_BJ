#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define LL long long

template<class T>
inline void read(T &x){
    T f=-1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=f;
}

const int N=1e5+5;
int n,a[N];

inline bool check(int x){
    //printf("x=%d\n",x);
    int lim=n-x;
    if(x==n) return (a[n]==a[n-1]);
    int i=1;
    rep(j,2,lim) if(a[j]>a[i]) i++;
    //printf("%d\n",i);
    if(i==lim) return a[n]>a[lim];
    rep(j,lim+1,n-1) if(a[j]>a[i] && i<lim) i++;
    //printf("%d\n",i);
    return i==lim && a[n]>a[lim];
}


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    //rep(i,1,n) printf("%d ",a[i]);
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}