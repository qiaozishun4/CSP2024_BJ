#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int T,n,m,L,V,p[N],s[N],ans1;
struct Node{
    int d,v,a;
    int ed;
}a[N];
inline int mabs(int a){
    return a<0?-a:a;
}
inline bool check(int tt){
    bool flg=1;
    for(int i=1;i<=n;i++)
        if(a[i].a<0) flg=0;
    if(flg){
        if(ans1) return tt>=1; /* when a>=0,last is the best*/
        else{
            return tt>=0;
        }
    }
    vector<int> t,v; t.clear(),v.clear();
    for(int i=1;i<=n;i++){
        if(a[i].a<0){
            if(a[i].v<V) continue;
            if(1.0*a[i].d+1.0*(a[i].v*a[i].v-V*V)/mabs(2*a[i].a)<a[i].d*1.0) continue;
            if(s[a[i].ed]-s[a[i].d-1]==0) continue;
            t.push_back(i);
        }
    }
    int loc=0;
    int szt=t.size(),i=0;
    while(i<szt){

        while(i<szt && a[t[i]].d<=p[loc] && a[t[i]].ed>=p[loc]) i++;

        while(loc<=m && p[loc]<=a[t[i]].ed) loc++;

        if(i>=szt) break;
        tt--; loc--;

    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(a[i].a>0 && p[loc]-a[i].d<max(0,(V*V-a[i].v*a[i].v)))
                flag=1;
    }

    if(flag) tt--;
    return tt>=0;
}
inline bool cmp(Node a,Node b){
   if(a.ed!=b.ed) return a.ed<b.ed;
   else return a.d<b.d;
}

inline void solve(){

    scanf("%d%d%d%d",&n,&m,&L,&V);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
        if(a[i].a>=0) a[i].ed=L+1;

        else a[i].ed=(int)a[i].d+1.0*(a[i].v*a[i].v-V*V)/mabs(2*a[i].a);
    }
    sort(a+1,a+1+n,cmp);
    ans1=0;
    for(int i=1;i<=m;i++) scanf("%d",p+i);
    p[m+1]=L+1;
    sort(p+1,p+1+m);
    for(int i=1;i<=n;i++)
        a[i].ed=min(a[i].ed,p[m]);
    int t=1;
    for(int i=1;i<=1000000;i++){
        s[i]=s[i-1];
        if(p[t]==i){
            s[i]=s[i-1]+1;
            t++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].a>0){
            double t1=sqrt(a[i].v*a[i].v+2*a[i].a*(p[m]-a[i].d));
            if(t1>V) ans1++;
        }else if(a[i].a==0 && a[i].d<=p[m]){
            if(a[i].v>V) ans1++;
        }else{
            if(1.0*a[i].d+1.0*(a[i].v*a[i].v-V*V)/mabs(2*a[i].a)>a[i].d*1.0 && s[a[i].ed]-s[a[i].d-1]>=1) ans1++;
        }
    }
    printf("%d ",ans1);
    int l=0,r=m+1;
    while(r-l>5){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    //cout<<l<<" "<<r<<'\n';
    for(;l<=r;l++)
        if(check(l)) break;
    printf("%d\n",m-l);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
