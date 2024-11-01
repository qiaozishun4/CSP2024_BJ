
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
const int maxn=101000;
// struct node{
//     int l,r,sum;
// }smt[maxn<<2];
// #define ll smt[now].l
// #define rr smt[now].r
// #define ss smt[now].sum
// #define mid (ll+rr>>1)
// #define lson smt[now<<1]
// #define rson smt[now<<1^1]
// inline void pushup(int now){ss=lson.sum+rson.sum;}
// void build(int now){
//     if(ll==rr){ss=1;return;}
//     lson.l=ll,rson.r=rr,lson.r=mid,rson.l=mid+1;
//     build(now<<1),build(now<<1^1),pushup(now);
// }
// void change(int now,int l,int r){
//     if(l>r)return;
//     if(l==ll&&r==rr){ss=0;return;}
//     if(l<=mid)change(now<<1,l,min(r,mid));
//     if(r>mid)change(now<<1^1,max(l,mid+1),r);
//     pushup(now);
// }
struct car{
    double d,v,a;
}c[maxn];
int T,n,m,l,V,csd[maxn],x,y,z,ans,ans2,le,ri,zz;
vector<pair<int,int> >vec;
#define dd c[i].d
#define vv c[i].v
#define aa c[i].a
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        memset(c,0,sizeof(c));
        memset(csd,0,sizeof(csd));
        //memset(smt,0,sizeof(smt));
        ans=ans2=0;
        vec.clear();
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            c[i]={x,y,z};
        }
        for(int i=1;i<=m;i++)cin>>csd[i];
        //smt[1].l=1,smt[1].r=n;build(1);
        for(int i=1;i<=n;i++){
            if(vv<=V&&aa<=0)continue;
            if(vv<=V)le=floor((V*V-vv*vv)/aa/2)+dd+1,ri=l+1;//左闭右开
            else if(aa<0)le=dd,ri=ceil((V*V-vv*vv)/aa/2)+dd;
            else le=dd,ri=l+1;
            int left=lower_bound(csd+1,csd+m+1,le)-csd,right=lower_bound(csd+1,csd+m+1,ri)-csd;
            //cout<<left<<"  "<<right<<"\n";
            if(right>left)ans++,vec.push_back({left,right-1});
        }if(!vec.size()){
            cout<<"0 "<<m<<"\n";
            continue;
        }
        sort(vec.begin(),vec.end());
        int left=vec[0].first,right=vec[0].second;zz=0,ans2=1;
        while(zz<vec.size()){
            while(left<=right&&zz<vec.size()){
                left=max(left,vec[zz].first),right=min(right,vec[zz].second);
                zz++;
            }
            if(left>right)ans2++,left=vec[zz-1].first,right=vec[zz-1].second;
        }
        cout<<ans<<" "<<m-ans2<<"\n";
    }
    return 0;
}