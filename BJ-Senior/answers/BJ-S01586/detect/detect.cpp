#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define double long double
const double eps=1e-9;
int n,m;
double L,V;
int T;
struct car{
    double d,v,a;
}a[100005];
int p[100005];
double dis(double v0,double a,double t){//t时刻的位移
    if(a==0){
        return 1.0*(double)v0*t;
    }
    double s=v0*t+0.5*a*t*t;
    return s;
}
double ofv(double v0,double a,double t){//t时刻后的速度
    if(a==0){
        return v0;
    }
    double v1=v0+a*t;
    return v1;
}
//setprecision()
double timev(double v0,double a,double s){
    if(a==0){
        return v0;
    }
    return sqrtl(v0*v0+2*a*s);
}
pair<double,double> jiao(pair<double,double> x,pair<double,double> y){
    if(x.first>y.first) swap(x,y);
    if(x.second<y.first) return {-2233,-2233};
    if(x.first+eps<=y.first&&y.second<=x.second+eps){
        return y;
    }
    return {y.first,x.second};
}
//按r排序以后随便做
#define fi first
#define se second
vector<pair<int,int>> v;
bool check(int pos,int dis){
    //car id
    //dis
    //cout<<'!';
    //cout<<(timev(a[pos].v,a[pos].a,dis-a[pos].d)>V)<<'\n';
    return timev(a[pos].v,a[pos].a,dis-a[pos].d)>V;
}
bool cmp(pair<int,int> x,pair<int,int> y){
    return (x.se==y.se?x.fi<y.fi:x.se<y.se);
}
int solve(){
    int cnt=0;
    sort(v.begin(),v.end(),cmp);
    int pos=0,R=-1;
    //for(auto i:v) cout<<i.fi<<' '<<i.se<<'\n';
    for(int i=0;i<v.size();i=pos){
        R=max(R,v[i].se);cnt++;
        while(pos<v.size()&&v[pos].fi<=R){
            pos++;
        }
        //cout<<pos<<'\n';
    }
    v.clear();
    return cnt;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        v.clear();
        _for(i,1,n) cin>>a[i].d>>a[i].v>>a[i].a;
        _for(i,1,m) cin>>p[i];
        _for(i,1,n){
            int it=lower_bound(p+1,p+m+1,a[i].d)-p;
            if(it==m+1) continue;
            if(a[i].a>=0){
                int l=it,r=m,res=-1;
                while(l<=r){
                    int mid=l+r>>1;
                    //cout<<l<<' '<<r<<'\n';
                    if(check(i,p[mid])) res=mid,r=mid-1;
                    else l=mid+1;
                }
                if(res!=-1){
                    v.push_back({res,m});
                }
            }else{
                int l=it,r=m,res=-1;
                while(l<=r){
                    int mid=l+r>>1;
                    if(check(i,p[mid])) res=mid,l=mid+1;
                    else r=mid-1;
                }
                if(res!=-1){
                    v.push_back({it,res});
                }
            }
        }
        cout<<v.size()<<' '<<m-solve()<<'\n';
    }
    return 0;
}
