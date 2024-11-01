#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,m,l,maxn,tot,mx;
int ans1=0,ans2=0;
bool flag=false;
double b[N];
struct node{
    double d,v,a;
}c[N];

struct range{
    int l,r;
}p[N];

inline int bsearch_1(int l,int r,int id){
    int ans=-1;
    double v=c[id].v, d=c[id].d, a=c[id].a;
    while(l <= r){
        int mid=(l+r)>>1;
        double x=sqrt(v*v + 2*a*(b[mid]-d));
        if(x > maxn){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

inline int bsearch_2(int l,int r,int id){
    int ans=-1;
    double v=c[id].v, d=c[id].d, a=c[id].a;
    while(l<=r){
        int mid=(l+r)>>1;
        double y=v*v + 2*a*(b[mid]-d);
        if(y < 0){
            r=mid-1;
            continue;
        }
        double x=sqrt(y);
        if(x > maxn){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

bool cmp(range x,range y){
    return x.r < y.r;
}

void init(){
    flag=false;
    ans1=ans2=0;
    tot=0;
    mx=-1;
}

void solve(){
    //cout<<"//"<<mx<<endl;
    if(tot==0){
        if(ans1) ans2++;
        return;
    }
    int lst=p[1].r;
    ans2++;
    bool flag=false;
    for(int i=2;i<=tot;i++){
        if(lst < p[i].l) {
            lst=p[i].r;
            ans2++;
        }
        if(lst >= mx) flag=true;
    }
    if(!flag) ans2++;
    return;
}

int main(){
    //freopen("detect.in","w",stdout);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){

        cin>>n>>m>>l>>maxn;
        for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++) cin>>b[i];

        for(int i=1;i<=n;i++){
            int pos=lower_bound(b+1,b+m+1,c[i].d)-b;
            if(pos==m+1) continue;
            if(c[i].a > 0) {
                int fst=bsearch_1(pos,m,i);
                double x=sqrtl(c[i].v*c[i].v + 2*c[i].a*(b[m]-c[i].d));
                if(x > maxn){
                    ans1++;
                }
                mx=max(mx,fst);
            }
            if(c[i].a==0){
                if(c[i].v > maxn && pos!=m+1){
                   ans1++;
                }
            }
            if(c[i].a < 0){
                int lst=bsearch_2(pos,m,i);
                if(lst!=-1) ans1++;
                if(lst!=-1) p[++tot].l=pos,p[tot].r=lst;
            }
        }
        sort(p+1,p+tot+1,cmp);
        solve();
        cout<<ans1<<" "<<m-ans2<<endl;
        init();
    }
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,m,n,l,b[N],maxn;
int ans1,ans2,tot;
struct node{
    double d,v,a;
}c[N];

void init(){
    ans1=ans2=0;
    tot=0;
}

bool cmp(range x,range y){
    return x.r < y.r;
}

struct range{
    int l,r;
}p[N];

void solve(){
    int lst=p[1].r;
    ans2++;
    bool flag=false;
    for(int i=2;i<=tot;i++){
        if(lst < p[i].l) {
            lst=p[i].r;
            ans2++;
        }
        if(lst >= mx) flag=true;
    }
    if(!flag) ans2++;
    return;
}

int main(){
    //freopen("detect.in","w",stdout);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m>>l>>maxn;
        for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++) cin>>b[i];
        int lst=b[m];
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(c[i].a >= 0){
                int v=c[i].v, d=c[i].d, a=c[i].a;
                double x=sqrt(v*v + 2*a*(lst-d));
                if(x > maxn){
                    ans1++;
                    flag=true;
                }
            }
        }

    }
    return 0;
}*/
