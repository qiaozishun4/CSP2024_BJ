#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=1e5+10;
const int maxl=1e6+10;
const double eps=1e-8;

ifstream fin("detect.in");
ofstream fout("detect.out");

struct segment_tree{
    #define ls(u) ((u)<<1)
    #define rs(u) ((u)<<1|1)
    int mx[maxl<<2];
    void build(int u,int L,int R){
        mx[u]=0;
        if(L==R)
            return;
        int mid=(L+R)>>1;
        build(ls(u),L,mid);
        build(rs(u),mid+1,R);
    }
    void push_up(int u){
        mx[u]=max(mx[ls(u)],mx[rs(u)]);
    }
    void modify(int u,int L,int R,int p,int x){
        if(L==R){
            mx[u]=x;
            return;
        }
        int mid=(L+R)>>1;
        if(p<=mid)
            modify(ls(u),L,mid,p,x);
        else
            modify(rs(u),mid+1,R,p,x);
        push_up(u);
    }
    int query(int u,int L,int R,int l,int r){
        if(l>r)
            return 0;
        if(l<=L&&R<=r){
            return mx[u];
        }
        int mid=(L+R)>>1;
        int res=-1e9;
        if(l<=mid)
            res=max(res,query(ls(u),L,mid,l,r));
        if(mid+1<=r)
            res=max(res,query(rs(u),mid+1,R,l,r));
        return res;
    }
}st;

int T;
int n,m,L,V;
int d[maxn],v[maxn],a[maxn];
int p[maxm];

struct frac{
    int p,q;
    frac(ll x,ll y){
        p=x;q=y;
        if(p<0&&q<0)
            p=-p,q=-q;
    }
    frac(ll x){
        p=x;q=1;
    }
    friend bool operator==(const frac& x,const frac& y){
        return (ll)x.p*y.q==(ll)y.p*x.q;
    }
    friend bool operator<(const frac& x,const frac& y){
        return (ll)x.p*y.q<(ll)y.p*x.q;
    }
};
struct segment{
    int l,r;
    friend bool operator<(const segment& x,const segment& y){
        return x.r<y.r;
    }
};
vector<segment> s,ss;
int f[maxm];

int main(){
    ios::sync_with_stdio(0);
    fin>>T;
    while(T--){
        fin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
            fin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)
            fin>>p[i];

        for(int i=1;i<=m;i++)
           st.modify(1,0,L,p[i],1);
        
        s.clear();
        for(int i=1;i<=n;i++){
            if(a[i]<0){
                if(v[i]>V){
                    frac r={V*V-v[i]*v[i],2ll*a[i]};
                        
                    if(r<L-d[i]||r==L-d[i]){
                        s.push_back({d[i],d[i]+(r.p-1)/r.q});
                    }
                    else{
                        s.push_back({d[i],L});
                    }
                }
            }
            else if(a[i]==0){
                if(v[i]>V){
                    s.push_back({d[i],L});
                }
            }
            else{
                if(v[i]>V){
                    s.push_back({d[i],L});
                }
                else if(v[i]==V){
                    s.push_back({d[i]+1,L});
                }
                else{
                    frac r={V*V-v[i]*v[i],2ll*a[i]};
                    if(r<L-d[i]){
                        s.push_back({d[i]+r.p/r.q+1,L});
                    }
                }
            }
        }
        ss.clear();
        for(auto t:s){
            if(st.query(1,0,L,t.l,t.r)==1)
                ss.push_back(t);
            // fout<<"s "<<t.l<<' '<<t.r<<endl;
        }
        for(int i=1;i<=m;i++)
            st.modify(1,0,L,p[i],0);

        n=ss.size();
        fout<<n<<' ';
        sort(ss.begin(),ss.end());
        int ps=0,pl=0,pj=0;
        p[++m]=L+1;
        for(int i=0;i<=m;i++){
            while(ps<n&&ss[ps].r<p[i]){
                pl=max(pl,ss[ps].l);
                ps++;
            }
            while(p[pj]<pl)
                pj++;
            if(i==0)
                f[i]=0;
            else
                f[i]=-st.query(1,0,m,pj,i-1)+1;
            // fout<<f[i]<<endl;
            st.modify(1,0,m,i,-f[i]);
            // ans=max(ans,f[i]);
        }
        // for(auto t:s)
            // fout<<(t.fl?'[':'(')<<t.l.p<<'/'<<t.l.q<<','<<t.r.p<<'/'<<t.r.q<<(t.fr?']':')')<<endl;
        fout<<m-1-(f[m]-1)<<endl;
        st.build(1,0,m);
    }
    return 0;
}
// g++ detect.cpp -o detect.exe -std=c++14 -O2 -Wall && ./detect.exe