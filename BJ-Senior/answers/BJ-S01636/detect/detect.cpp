#include<bits/stdc++.h>

using ll=long long;

int read(){
    int res=0,neg=1; char c=getchar();
    while((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if(c=='-') neg=-1,c=getchar();
    while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48),c=getchar();
    return neg==-1?-res:res;
}

#define MAXN 100005

int n,m;
ll L,V;
ll pm,pv;
ll d[MAXN],v[MAXN],a[MAXN];
ll p[MAXN];
int pl[MAXN],pr[MAXN],oc,rk[MAXN],ans;
std::priority_queue<int,std::vector<int>,std::greater<int> > q;

int bs(ll pos){
    int l=1,r=m+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(p[mid]<pos){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return l;
}
bool cmp(int x,int y){
    return pl[x]<pl[y];
}

void run(){
    n=read(),m=read(),L=read(),V=read();
    for(int i=1;i<=n;i++) d[i]=read(),v[i]=read(),a[i]=read();
    for(int i=1;i<=m;i++) p[i]=read();
    oc=0;
    for(int i=1;i<=n;i++){
        if(a[i]<0){
            if(v[i]<=V) continue;
            ll dis1=(v[i]*v[i]-V*V-a[i]*2-1)/(2*(-a[i]));
            pl[i]=bs(d[i]),pr[i]=bs(d[i]+dis1);
        }else if(a[i]==0){
            if(v[i]<=V) continue;
            pl[i]=bs(d[i]),pr[i]=m+1;            
        }else{
            if(v[i]>V){
                pl[i]=bs(d[i]),pr[i]=m+1;
            }else{
                ll dis1=(V*V-v[i]*v[i]+a[i]*2)/(2*a[i]);
                pl[i]=bs(d[i]+dis1),pr[i]=m+1;
            }   
        }
        if(pl[i]<pr[i]) rk[++oc]=i;
    }
    std::cout<<oc<<' ';

    while(!q.empty()) q.pop();
    std::sort(rk+1,rk+oc+1,cmp);
    int now=1; ans=0;
    for(int i=1;i<=m;i++){
        while(now<=oc){
            if(pl[rk[now]]>i) break;
            q.push(pr[rk[now]]); now++;
        }
        if(!q.empty()) if(q.top()<=i+1){
            ans++;
            while(!q.empty()) q.pop();
        }
    }
    std::cout<<m-ans<<'\n';

    return;
}

int T;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    T=read();
    for(int i=1;i<=T;i++) run();

    return 0;
}