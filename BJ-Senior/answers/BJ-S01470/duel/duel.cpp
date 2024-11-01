#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int n,a[maxn];
void slv(){
    n=read();up(i,1,n){int x=read();a[x]++;}
    int res=0,V=1e5;
    up(i,1,V)res-=min(a[i],res),res+=a[i];
    cout<<res;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}