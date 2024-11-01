#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double ldb;

const lint N=1e5+5,M=1e5+5,LL=1e6+5;

lint n,m,L,V;

lint nn;

class BIT{
public:
    lint c[LL];
    lint lowbit(lint x){return x&-x;}
    lint query(lint i){
        i++;
        lint ret=0;
        while(0<i){
            ret+=c[i];
            i-=lowbit(i);
        }
        return ret;
    }
    void add(lint i,lint x){
        i++;
        while(i<LL){
            c[i]+=x;
            i+=lowbit(i);
        }
    }
    void clear(){
        memset(c,0,sizeof(c));
    }
}bit;

struct Car{
    lint d,v,a;
    lint l,r;
}cr[N];
lint p[M];

pair<lint,lint> func(lint d,lint v,lint a){
    if(v>V){
        if(a>=0){
            return {d,L};
        }
        else{
            a=-a;
            return {d,min(d+(v*v-V*V)/(2*a),L)};
        }
    }
    else{
        if(a<=0){
            return {L,0};
        }
        else{
            return {d+(V*V-v*v)/(2*a)+1,L};
        }
    }
}

void solve1(){
    lint ans=0;
    bit.clear();
    for(lint i=1;i<=m;i++){
        bit.add(p[i],1);
    }

    for(lint i=1;i<=n;i++){
        if(cr[i].l<=cr[i].r){
            lint cnt=bit.query(cr[i].r)-bit.query(cr[i].l-1);
            // cout<<i<<" "<<cr[i].l<<" "<<cr[i].r<<" "<<cnt<<endl;
            if(cnt>0){
                ans++;
            }
        }
    }
    cout<<ans<<" ";
}

struct P{
    lint pp,cnt;
}q[M];

void solve2(){
    bit.clear();
    lint ans=0;

    for(lint i=1;i<=m;i++){
        for(lint j=1;j<=n;j++){
            if(cr[j].l<=cr[j].r){
                bit.add(cr[j].l,1);
                bit.add(cr[j].r+1,-1);
            }
        }
        for(lint j=1;j<=m;j++){
            q[j].pp=p[j];
            q[j].cnt=bit.query(p[j]);
        }

        for(lint j=1;j<=n;j++){
            if(cr[j].l<=cr[j].r){
                bit.add(cr[j].l,-1);
                bit.add(cr[j].r+1,+1);
            }
        }
        sort(q+1,q+m+1,[](const P& x,const P& y){
            return x.cnt>y.cnt;
        });

        if(q[1].cnt){
            ans++;
        }
        else{
            break;
        }
        for(lint j=1;j<=n;j++){
            if(cr[j].l<=q[1].pp&&q[1].pp<=cr[j].r){
                cr[j].l=L;
                cr[j].r=0;
            }
        }
    }
    cout<<m-ans<<endl;
}

void solve(){
    cin>>n>>m>>L>>V;
    for(lint i=1;i<=n;i++){
        cin>>cr[i].d>>cr[i].v>>cr[i].a;
    }
    for(lint i=1;i<=m;i++){
        cin>>p[i];
    }

    nn=n;
    for(lint i=1;i<=n;i++){
        auto pr=func(cr[i].d,cr[i].v,cr[i].a);
        cr[i].l=pr.first;
        cr[i].r=pr.second;
    }

    #ifdef DBG
    cout<<"cr"<<endl;
    for(int i=1;i<=n;i++){
        cout<<cr[i].l<<" "<<cr[i].r<<endl;
    }
    #endif

    solve1();
    solve2();
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    lint T;
    cin>>T;
    for(lint i=1;i<=T;i++){
        solve();
        // cout<<endl;
        // while(1);
    }

    return 0;
}