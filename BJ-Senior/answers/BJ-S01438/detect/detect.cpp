#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

#define LD long double
const int maxn=1e5+10,maxL=1e6+10;
const LD eps=1e-9;
int T,n,m,L,V,det[maxL],nxt[maxL],lst,ans1,pre[maxL],ans2;
struct car{ int pos,spd,inc; } cars[maxn];
struct limit{
    int l,r; 
    limit(LD L, LD R){ l=ceill(L); r=floorl(R); }
    bool operator<(const limit other)const{ return r!=other.r?r<other.r:l>other.l;; }
}; vector<limit> limits;

bool overspeed(LD spd){ return spd>V; }
LD speed(car x, int p){ return sqrtl(x.spd*x.spd+2*x.inc*(p-x.pos)); }
LD pos(car x, LD spd){ return x.pos+(LD)(spd*spd-x.spd*x.spd)/2/x.inc; }

bool test(car x){
    if(x.pos>lst)return false;
    if(x.inc>=0)return overspeed(speed(x, lst));
    if(pos(x,0)<nxt[x.pos])return false;
    return overspeed(speed(x, nxt[x.pos]));
}
void add(car x){
    if(x.inc==0)limits.push_back({x.pos, L});
    else if(x.inc>0)limits.push_back({max(pos(x, V)+eps, (LD)x.pos), L});
    else{
        LD y=min(pos(x, V)-eps,min((LD)L, pos(x,0)));
        limits.push_back({x.pos, y});
    }
}

int tree[maxL];
int lowbit(int x){ return x&-x; }
void clear(){ for(int i=0;i<=L+1;i++)tree[i]=0; }
void add(int p, int v){ for(;p<=L+1;p+=lowbit(p))tree[p]+=v; }
int query(int p){ int ans=0; for(;p;p-=lowbit(p))ans+=tree[p]; return ans; }

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&L,&V); ans1=lst=0; ans2=m; limits.clear(); clear();
        for(int i=0;i<=L+1;i++)det[i]=0;
        for(int i=1;i<=n;i++)scanf("%d%d%d",&cars[i].pos,&cars[i].spd,&cars[i].inc);
        for(int i=1;i<=m;i++){
            int p; scanf("%d",&p);
            det[p]=1; lst=max(lst, p);
        }
        
        for(int i=L;i>=0;i--){
            if(det[i])nxt[i]=i;
            else nxt[i]=nxt[i+1];
        }
        pre[0]=det[0]-1;
        for(int i=1;i<=L;i++){
            if(det[i])pre[i]=i;
            else pre[i]=pre[i-1];
        }
        
        for(int i=1;i<=n;i++)if(test(cars[i]))ans1++,add(cars[i]);
        sort(limits.begin(), limits.end());
        for(limit x:limits)if(query(x.r+1)<=query(x.l)){
            //cout<<x.l<<' '<<x.r<<endl;
            int pos=pre[x.r]; add(pos+1,1);
            ans2--;
        }
        
        printf("%d %d\n",ans1,ans2);
    }
}