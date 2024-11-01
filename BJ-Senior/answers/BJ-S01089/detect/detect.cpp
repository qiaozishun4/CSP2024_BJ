#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
// HF#24THMC Z*L#LH%9
struct node{
    int col,cor;
}co[N];
struct ask{
    int l,r,vis;
}pr[N];
int n,m,L,v,pos[N],cnt;
int chuyi(int x,int y){
    return x/y+1;
}
bool check(int u){
    if(pr[u].l>pr[u].r) return 0;
    if(pr[u].l==-1) return 0;
    int LL=1,R=m+1,mid;
    while(LL+1<R){
        mid=(LL+R)/2;
        if(pos[mid]>=pr[u].l){
            LL=mid;
        }else{
            R=mid;
        }
    }
    //if(u==4) cout<<L<<endl;
    if(pos[LL]>=pr[u].l&&pos[LL]<=pr[u].r) return 1;
    return 0;
}
node getarea(int u){
    node res;
    int LL=1,R=cnt+1,mid;
    if(pr[1].l>pos[u]) return{-1,-1};
    while(LL+1<R){
        mid=(LL+R)/2;
        //cout<<mid;
        if(pr[mid].l<=pos[u]){
            LL=mid;
        }else{
            R=mid;
        }

    }
    res.cor=LL;
    if(pr[cnt].r<pos[u]) return{-1,-1};
    LL=0,R=cnt+1;
    while(LL+1<R){
        mid=(LL+R)/2;
        if(pr[mid].r<pos[u]){
            LL=mid;
        }else{
            R=mid;
        }
    }
    res.col=LL+1;
    if(res.col>res.cor) return{-1,-1};
    return res;
}
bool cmp1(int x,int y){
    return x>y;
}
bool cmp2(ask x,ask y){
    if(x.vis!=y.vis) return x.vis>y.vis;
    if(x.l!=y.l) return x.l<y.l;
    else return x.r<y.r;
}
bool cmp3(node x,node y){
    if(x.col!=y.col) return x.col<y.col;
    else return x.cor<y.cor;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&L,&v);
        for(int i=1;i<=n;++i){
            int d,dv,a;
            scanf("%d%d%d",&d,&dv,&a);
            if(a==0){
                if(dv>v){
                    pr[i].l=d;
                    pr[i].r=L;
                }else{
                    pr[i].l=-1;
                    pr[i].r=-1;
                }
            }else if(a>0){
                if(dv>v){
                    pr[i].l=d;
                    pr[i].r=L;
                }else{
                    pr[i].l=d+chuyi(v*v-dv*dv,2*a);
                    pr[i].r=L;
                }
            }else{
                if(dv>v){
                    pr[i].l=d;
                    if((dv*dv-v*v)%(-2*a)==0){
                        pr[i].r=min(L,d+(dv*dv-v*v)/(-2*a)-1);
                    }else{
                        pr[i].r=min(L,d+(dv*dv-v*v)/(-2*a));
                    }

                }else{
                    pr[i].l=-1;
                    pr[i].r=-1;
                }
            }
        }
        for(int i=1;i<=m;++i){
            scanf("%d",&pos[i]);
        }
        sort(pos+1,pos+m+1,cmp1);
        int ans=0;
        for(int i=1;i<=n;++i){
            pr[i].vis=0;
            if(check(i)){
                pr[i].vis=1;
                ++ans;
            }
        }
        cout<<ans<<" ";
        sort(pr+1,pr+1+n,cmp2);
        int la=L+1;
        cnt=ans;
        for(int i=ans;i>=1;--i){
            if(pr[i].r>=la){
                --cnt;
                pr[i].vis=0;
            }else{
                la=min(pr[i].r,la);
            }
            //cout<<pr[i].l<<" "<<pr[i].r<<endl;
        }
        sort(pr+1,pr+1+ans,cmp2);
        //cout<<cnt<<endl;
        //for(int i=1;i<=cnt;++i){
            //cout<<pr[i].l<<" "<<pr[i].r<<endl;
        //}
        for(int i=1;i<=m;++i){
            co[i]=getarea(i);
            //<<co[i].col<<" "<<co[i].cor<<endl;
        }
        sort(co+1,co+m+1,cmp3);
        int cal=1,szz=1,nxtr;
        ans=0;
        for(int i=1;i<=m;){
            nxtr=0;
            while(co[szz].col<=cal){
                nxtr=max(nxtr,co[szz].cor);
                ++szz;
            }
            cal=nxtr+1;
            ++ans;
            if(nxtr>=cnt) break;
        }
        if(cnt==0) cout<<m<<endl;
        else cout<<m-ans<<endl;
    }
    return 0;
}
