#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct Node{
    ll l,r;
}a[N];
int n,h,m,l,v;
ll b[N];
bool cmp(Node x,Node y){
    if(x.r!=y.r){
        return x.r<y.r;
    }else{
        return x.l<y.l;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&l,&v);
        h=0;
        for(int i=1;i<=n;++i){
            ll x,y,z;
            scanf("%lld%lld%lld",&x,&y,&z);
            if((y>v)&&(z>=0)){
                ++h;
                a[h].l=x;
                a[h].r=l;
            }else if(y>v){
                ++h;
                a[h].l=x;
                a[h].r=x+(v*v-y*y)/(2*z);
                if((v*v-y*y)%(2*z)==0){
                    --a[h].r;
                }
                a[h].r=min(a[h].r,l*1ll);
            }else if(z>0){
                if(x+(v*v-y*y)/(2*z)+1<=l){
                    ++h;
                    a[h].l=x+(v*v-y*y)/(2*z)+1;
                    a[h].r=l;
                }
            }
        }
        for(int i=1;i<=m;++i){
            scanf("%lld",&b[i]);
        }
        sort(a+1,a+1+h,cmp);
        int ans1=0,ans2=0;
        b[0]=-1e9;
        for(int i=1,j=0,p=0;i<=h;++i){
            if(a[i].l<=b[j]){
                ++ans1;
                continue;
            }
            while((p<m)&&(b[p+1]<=a[i].r)){
                ++p;
            }
            if(b[p]>=a[i].l){
                j=p;
                ++ans1;
                ++ans2;
            }
        }
        printf("%d %d\n",ans1,m-ans2);
    }
    return 0;
}