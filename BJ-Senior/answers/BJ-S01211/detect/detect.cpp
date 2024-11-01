#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
struct car{
    ll d,v,a,num,num1;
    void clear(){d=0;v=0;a=0;num=0;}
}c[N];
ll p[N];
ll n,m,l,v;
ll low[N],low_=0;
void init(){
    for(int i=0;i<n;i++){
        c[i].clear();
        low[i]=0;
    }
    for(int i=0;i<m;i++){
        p[i]=0;
    }
    low_=0;
}
ll find1(ll who){
    ll l=0,r=m-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(p[mid]==c[who].d)return mid;
        if(p[mid]>c[who].d)r=mid-1;
        else l=mid+1;
    }
    return l;
}
int cmp2(int x,int y){
    if(c[x].num1!=c[y].num1)return c[x].num1<c[y].num1;
    return c[x].num<c[y].num;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        init();
        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        ll re=0;
        ll ans=0;
        low_=0;
        for(int i=0;i<n;i++){
            ll l2=find1(i),r2=m-1;ll l1=l2,r1=r2;
            if(c[i].a==0){
                if(c[i].v>v && l2<=r2){
                    re++;
                    low[low_]=i;
                    low_++;
                }
                c[i].num=l2;
                c[i].num1=r2;
                continue;
            }
            else if(c[i].a<0){
                while(l2<=r2){
                    ll mid=(l2+r2)/2;
                    if(c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d)>v*v)l2=mid+1;
                    else r2=mid-1;
                }
                c[i].num=l1;
                c[i].num1=r2;
                if(l1<=r2){
                    re++;
                    low[low_]=i;
                    low_++;
                }
                continue;
            }
            else if(c[i].a>0){
                while(l2<=r2){
                    ll mid=(l2+r2)/2;
                    if(c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d)>v*v)r2=mid-1;
                    else l2=mid+1;
                }
                c[i].num=l2;
                c[i].num1=r1;
                if(l2<=r1){
                    re++;
                    low[low_]=i;
                    low_++;
                }
                continue;
            }
        }
        cout<<re<<' ';
        sort(low,low+low_,cmp2);
        for(int i=0;i<low_;){
            int di=1;
            for(int j=i+1;j<low_;j++){
                if(c[low[j]].num<=c[low[i]].num1){
                    di++;
                    c[low[j]].num=0;
                    c[low[j]].num1=0;
                }
            }
            c[low[i]].num=0;
            c[low[i ]].num1=0;
            ans++;
            sort(low,low+low_,cmp2);
            i+=di;
        }
        cout<<m-ans<<endl;
    }
    return 0;
}
