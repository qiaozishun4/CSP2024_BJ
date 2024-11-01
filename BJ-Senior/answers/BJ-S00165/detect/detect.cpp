#include<bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a,l,r;
}lt[100005];
struct pl{
    int pla,sum;
}p[100005];
bool fp=true,fn=true;
int T,n,m,L,V,ans=0,mnl=2000005,ak;
void chck(int pm){
    for(int i=1;i<=n;i++){
        if(lt[i].l==lt[i].r) continue;
        if(lt[i].l<pm&&pm<=lt[i].r) ak++;
    }
}
void ltte(){
    int biit=pow(2,m)-1,pp,mnp=2147483647;
    while(biit>=0){
        ak=0;
        for(int i=0;i<m;i++){
            if(biit&(1<<i)!=0){
                chck(p[i].pla);
                pp++;
            }
            if(ak>ans) ans=ak;
        }
        if(ans==ak) mnp=min(mnp,pp);
        biit--;
    }
    printf("%d %d\n",ans,mnp);
}

void post(){
    if(p[m].pla<=mnl) printf("0 %d\n",m);
    else{
        for(int i=1;i<=n;i++){
            if(lt[i].l<p[m].pla&&lt[i].r!=0) ans++;
        }
        printf("%d %d\n",ans,m-1);
    }
}
void nagt(){

}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        fp=fn=true;ans=0;mnl=2000005;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
                bool ept=true;
            scanf("%d%d%d",&lt[i].d,&lt[i].v,&lt[i].a);
            if(lt[i].a>0){
                fn=false;
                lt[i].l=min((V*V-lt[i].v*lt[i].v)/(2*lt[i].a)+lt[i].d,L);
                lt[i].r=L;
                if(lt[i].l==L) lt[i].l=lt[i].r=0;
            }else if(lt[i].a<0){
                fp=false;
                if(lt[i].v<=V) ept=lt[i].l=lt[i].r=0;
                else{
                    lt[i].l=lt[i].d-1;
                    lt[i].r=min(L,(V*V-lt[i].v*lt[i].v)/(2*lt[i].a)+lt[i].d);
                }
            }else{
                fn=false;
                if(lt[i].v<=V) ept=lt[i].l=lt[i].r=0;
                else{
                    lt[i].l=lt[i].d-1;
                    lt[i].r=L;
                }
            }
            if(ept) mnl=min(mnl,lt[i].l);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i].pla);
        }
        if(n<=21){
            ltte();
        }
        if(fp){

            post();
        }
        if(fn){
            nagt();
        }
    }
    return 0;
}
