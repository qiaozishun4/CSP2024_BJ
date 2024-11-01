#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REV(i,a,b) for(int i=a;i>=b;i--)
#define mkp make_pair
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+5;
const int L=1e6+5;
struct Car{
    int d,v,a;
}c[N];
ll T,n,m,l,V,p[N],r[L],pmp[L],pp[L];
int main(){
    freopen("detect.in","r",stdin);freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>V;
        ll ans1=0,ans2=0;
        FOR(i,1,l)r[i]=pp[i]=pmp[i]=0;
        ++l;//注意此处将0～l变为了1～l+1
        FOR(i,1,n){
            cin>>c[i].d>>c[i].v>>c[i].a;
            ++c[i].d;
        }
        set<int> st;
        ll mxp=0;
        FOR(i,1,m){cin>>p[i];++p[i];pmp[p[i]]=1;mxp=max(mxp,p[i]);}
        FOR(i,1,l)pp[i]=pp[i-1]+pmp[i];
        FOR(i,1,n){
            ll d=c[i].d,v=c[i].v,a=c[i].a;
            if(a==0){
                if(v<=V)continue;
                else{
                    if(pp[l]-pp[d-1])++ans1;
                    ++r[d];
                    int lo=*lower_bound(p+1,p+m+1,d);
                    if(d<=lo&&lo<=l)st.insert(lo);
                }
            }
            else if(a>0){
                ll outb=d+(V*V-v*v)/(2*a)+1;
                if(outb>l)continue;
                if(pp[l]-pp[outb-1])++ans1;
                ++r[outb];
                int lo=*lower_bound(p+1,p+m+1,outb);
                if(outb<=lo&&lo<=l)st.insert(lo);
            }
            else{
                if(v<=V)continue;
                else{
                    ll oute=d+ceil((V*V-v*v)*1.0/(2.0*a) )-1;
                    ++r[d];
                    if(pp[min(l,oute)]-pp[d-1])++ans1;
                    int lo=*lower_bound(p+1,p+m+1,d);
                    if(d<=lo&&lo<=min(l,oute))st.insert(lo);
                    if(oute<=l)--r[oute+1];
                }
            }
            /*
            cout<<i<<endl;
            int lr=0;
            FOR(i,1,l){
                cout<<(lr+=r[i])<<' ';
            }
            cout<<endl;
            FOR(i,1,l)cout<<i<<' ';
            cout<<endl;
            */
        }

        FOR(i,1,l){
            r[i]=r[i-1]+r[i];
            //cout<<r[i]<<' ';
        }
        //cout<<endl;

        cout<<ans1<<' '<<m-st.size()<<endl;
    }
    return 0;
}
