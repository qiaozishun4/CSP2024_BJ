#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=1e6+10;
typedef long double Ld;
typedef pair<int,int> pii;
int n,m,l,VVV;
vector<int> to[MAXN];
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
Ld V(Ld s,Ld v0,Ld a){
    return sqrt(v0*v0+2*a*s);
}
int Find1(Ld x){
    return lower_bound(p+1,p+m+1,x)-p;
}
int Find2(Ld x){
    return upper_bound(p+1,p+m+1,x)-p-1;
}
int f[MAXN];
int Getl(int i){
    if(a[i]==0){
        if(v[i]>VVV) return Find1(d[i]);
        else return -1;
    }
    else if(a[i]>0){
        Ld l=0,r=1e6+10;
        while(l+1e-5<r){
            double mid=(l+r)/2;
            if(V(mid,v[i],a[i])>=VVV){
                r=mid;
            }
            else l=mid;
        }
        if(d[i]+l>p[m]+1e-4) return -1;
        else{
            int tmp=Find1(d[i]+l);
            if(abs(p[tmp]-d[i]-l)<1e-3) tmp++;
            return tmp;
        }
    }
    else{
        if(v[i]>VVV) return Find1(d[i]);
        else return -1;
    }
}
int Getr(int i){
    if(a[i]==0){
        if(v[i]>VVV) return m;
        else return -1;
    }
    else if(a[i]>0){
        Ld tmp=V(p[m]-d[i],v[i],a[i]);
        if(tmp>VVV) return m;
        else return -1;
    }
    else{
        Ld l=0,r=1e6+10;
        while(l+1e-5<r){
            double mid=(l+r)/2;
            if(V(mid,v[i],a[i])>=VVV){
                l=mid;
            }
            else r=mid;
        }
        if(d[i]+l>p[m]+1e-4) return -1;
        else{
            //printf("%.2Lf\n",d[i]+l);
            int tmp=Find2(d[i]+l);
            //cout<<"tmp:"<<tmp<<endl;
            if(abs(p[tmp]-d[i]-l)<1e-3) tmp--;
            return tmp;
        }
    }
}
void Work(){
    cin>>n>>m>>l>>VVV;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;i++) cin>>p[i];
    sort(p+1,p+m+1);
    for(int i=0;i<=1e6;i++) to[i].clear();
    int ans=0;
    for(int i=1;i<=n;i++){
        //cout<<"i:"<<i<<endl;
        int l=Getl(i),r=Getr(i);
        //cout<<"lr:"<<l<<" "<<r<<endl;
        if(l==-1) continue;
        if(l>r) continue;
        ans++;
        //cout<<"chao:"<<l<<" "<<r<<endl;
        to[r].push_back(l);
    }
    for(int i=1;i<=1e6;i++){
        if(!to[i].size()) f[i]=f[i-1];
        else{
            f[i]=1e9;
            for(auto j:to[i]) f[i]=min(f[i],f[j-1]+1); 
        }
    }
    cout<<ans<<" "<<m-f[int(1e6)]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;cin>>t;
    while(t--) Work();
    return 0;
}