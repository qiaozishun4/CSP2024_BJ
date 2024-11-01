#include<bits/stdc++.h>
using namespace std;

int T,n,m,L,V;
struct car{
    int d,v,a;
}c[100005];
int r[1000005];
int r2[1000005];
int p[1000005];
struct time{
    int l,r;
}t[100005];

int check(int i){
    if(c[i].a==0){
        if(c[i].v>V){
            t[i]={c[i].d,L+1};
            return p[c[i].d];
        }
        else{
            t[i]={L+1,L+1};
            return 0;
        }
    }
    else {
        double pos=c[i].d+(V*V-c[i].v*c[i].v)/(2*c[i].a)*1.0;
        if(c[i].a>0){
            t[i]={pos,L+1};
            return p[t[i].l];
        }
        else{
            t[i]={c[i].d,pos};
            return p[t[i].l]-p[t[i].r];
        }
    }
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        memset(c,0,sizeof(c));
        memset(r,0,sizeof(r));
        memset(p,0,sizeof(p));
        memset(t,0,sizeof(t));
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)cin>>c[i].d>>c[i].v>>c[i].a;
        int tmp;
        for(int i=1;i<=m;i++){
            cin>>tmp;
            r[tmp]++;
        }
        p[L]=r[L];
        for(int i=L;i>=0;i--)p[i]=p[i+1]+r[i];
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=check(i)!=0;
        }
        cout<<cnt<<endl;
    }
}
