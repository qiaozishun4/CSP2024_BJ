#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
struct node{
    int l,r;
    node(){}
    node(int _l,int _r){
        l=_l,r=_r;
    }
}mp[100010];
int ct=0;
int n,m,L,V;
int q[1000010];
void add(int l,int r){
    if(l>r)return;
    if(l>L)return;
    mp[++ct]=node(l,min(r,L));
}
int get(int l,int r){
    l++,r++;
    return q[r]-q[l-1];
}
bool cmp(node a,node b){
    if(a.r==b.r)return a.l<b.l;
    return a.r>b.r;
}
node sum(node a,node b){
    return node(max(a.l,b.l),min(a.r,b.r));
}
bool check(node a){
    if(a.l>a.r)return 0;
    if(get(a.l,a.r)==0)return 0;
    return 1;
}
inline void run(){
    memset(q,0,sizeof q);
    cin >> n >> m >> L >> V;
    ct=0;
    fr(i,1,n){
        int d,v,a;
        cin >> d >> v >> a;
        if(a==0){
            if(v>V){
                add(d,L);
            }
        }
        else if(a>0){
            if(v>V){
                add(d,L);
                continue;
            }
            if(v==V){
               add(d+1,L);
                continue;
            }
            double t=((V*V)-(v*v))/(2.0*a);
            int tt=ceil(t);
            if(((V*V)-(v*v))==(2.0*a)*tt){
                add(d+tt+1,L);
            }
            else{
                add(d+tt,L);
            }
        }
        else{
            if(v<=V){
                continue;
            }
            double t=((V*V)-(v*v))/(2.0*a);
            int tt=floor(t);
            if(((V*V)-(v*v))==(2.0*a)*tt){
                add(d,d+tt-1);
            }
            else{
                add(d,d+tt);
            }
        }
    }
    fr(i,1,m){
        int p;
        cin >> p;
        q[p+1]++;
    }
    fr(i,2,L+1)q[i]+=q[i-1];
    int ans=0;
    int tpppp=ct;
    ct=0;
    fr(i,1,tpppp){
        int l=mp[i].l,r=mp[i].r;
        if(get(l,r)>0){
            ans++;
            add(l,r);
        }
    }
    cout << ans << " ";
    ans=0;
    sort(mp+1,mp+1+ct,cmp);
    node now=node(0,L+1);
    fr(i,1,ct){
        node tmp=sum(now,mp[i]);
        if(!check(tmp)){
            ans++;
            now=mp[i];
        }
        else now=tmp;
    }
    if(now.l!=0||now.r!=L+1)ans++;
    cout << m-ans << endl;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        run();
    }
return 0;
}
