#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100005;
int L, vm;
pair<int,int> getRange(int d, int v, int a){
    if(a == 0){
        if(v >vm)return {d,L};
        else return {L+1,L};
    }
    if(a > 0){
        if(v>vm)return {d,L};
        return {min(d+(vm*vm-v*v)/(2*a)+1,L+1), L};
    }
    if(v <= vm) return {L+1,L};
    return {d, min(d+(v*v-vm*vm-2*a-1)/(-2*a)-1,L)};
}
int d[MAXN], v[MAXN], a[MAXN], l0[MAXN], r0[MAXN];
int p[MAXN], s[MAXN];
int pn = 0;
pair<int,int> K[MAXN];
// struct SegmentTree{
//     pair<int,int> maxi;
//     int la;
// }st[MAXN << 2];
// void build(int a, int l, int r){
//     st[a].la=0;
//     st[a].maxi={0,r-1};
//     if(r-l>1){
//         int m = (l + r) >> 1;
//         build(a<<1,l,m);
//         build(a<<1|1,m,r);
//     }
// }
// void pushdown(int a);
// void add(int a, int l, int r, int L, int R, int c){
//     if(r<=L||R<=l)return;
//     else if(L<=l&&r<=R)st[a].maxi.first+=c,st[a].la+=c;
//     else{
//         int m = (l +r) >> 1;
//         pushdown(a);
//         add(a<<1,l,m,L,R,c);
//         add(a<<1|1,m,r,L,R,c);
//         st[a].maxi=max(st[a<<1].maxi,st[a<<1|1].maxi);
//     }
// }
// void pushdown(int a){
//     add(a<<1,0,1,0,1,st[a].la);
//     add(a<<1|1,0,1,0,1,st[a].la);
//     st[a].la=0;
// }
struct SegmentTree{
    int mini=0x3f3f3f3f;
    int la;
}st[MAXN << 2];
void build(int a, int l, int r){
    st[a].la=0;
    st[a].mini=0x3f3f3f3f;
    if(r-l>1){
        int m = (l + r) >> 1;
        build(a<<1,l,m);
        build(a<<1|1,m,r);
    }
}
void pushdown(int a);
void add(int a, int l, int r, int L, int R, int c){
    if(r<=L||R<=l)return;
    else if(L<=l&&r<=R)st[a].mini=c/*,st[a].la+=c*/;
    else{
        int m = (l +r) >> 1;
        pushdown(a);
        add(a<<1,l,m,L,R,c);
        add(a<<1|1,m,r,L,R,c);
        st[a].mini=min(st[a<<1].mini,st[a<<1|1].mini);
    }
}
int query(int a, int l, int r, int L, int R){
    if(r<=L||R<=l)return 0x3f3f3f3f;
    else if(L<=l&&r<=R)return st[a].mini;
    else{
        int m = (l + r) >> 1;
        return min(query(a<<1,l,m,L,R),query(a<<1|1,m,r,L,R));
    }
}
void pushdown(int a){
    // add(a<<1,0,1,0,1,st[a].la);
    // add(a<<1|1,0,1,0,1,st[a].la);
    // st[a].la=0;
}
// set<pair<int,int>> K2;
int l[MAXN], r[MAXN], f[MAXN];
int Li[MAXN];
signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m>>L>>vm;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
            pair<int,int> R = getRange(d[i],v[i],a[i]);
            l0[i]=R.first,r0[i]=R.second;
        }
        for(int i=0;i<m;i++)
            cin>>p[i];
        pn = 0;
        for(int i=0;i<n;i++){
            if(l0[i] > r0[i]) continue;
            int L = lower_bound(p,p+m,l0[i])-p, R = upper_bound(p,p+m,r0[i])-p;
            if(R > L)
                K[pn++]={L, R};
        }
        cout<<pn<<" ";
        sort(K, K+pn);
        int pm = 0;
        for(int i=0;i<pn;i++){
            while(pm && K[i].second <= K[pm-1].second)pm--;
            K[pm++]=K[i];
        }

        for(int i=0;i<pm;i++)l[i]=K[i].first,r[i]=K[i].second;
        for(int i=0;i<=pm;i++)Li[i]=0x3f3f3f3f;
        for(int i=0;i<m;i++){
            int L = lower_bound(r,r+pm,i+1)-r, R = upper_bound(l,l+pm,i)-l;
            if(R > L) Li[R]=min(Li[R], L);
        }
        build(1,0,pm);
        add(1,0,pm,0,1,0);
        for(int i=1;i<=pm;i++){
            if(Li[i] < i) f[i] = query(1,0,pm,Li[i],i) + 1, add(1,0,pm,i,i+1,f[i]);
        }
        cout<<m-f[pm]<<endl;
        // build(1,0,m);
        // for(int i=0;i<pm;i++){
        //     add(1,0,m,K[i].first,K[i].second,1);K2.insert(K[i]);
        // }
        // int cnt = m;
        // while(st[1].maxi.first > 0){
        //     int ma = st[1].maxi.second;
        //     auto it = K2.upper_bound({ma, 0x3f3f3f3f});
        //     --it;
        //     --cnt;
        //     while(1){
        //         auto it1 = it;
        //         --it;
        //         bool flag = it1 == K2.begin();
        //         if(it1->second>=ma+1){
        //             // cout<<it1->first<<" "<<it1->second<<endl;
        //             add(1,0,m,it1->first,it1->second,-1);
        //             K2.erase(it1);
        //         }
        //         if(flag) break;
        //         // cout<<"aww"<<endl;
        //     }
        // }
        // cout<<cnt<<endl;
    }
    return 0;
}