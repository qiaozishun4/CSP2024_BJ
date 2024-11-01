#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=1e5+5,M=1e6+5;
int T,n,m,len,V,sp[N],pos[N],num;
int sum[M],ans,tr[M<<2];
struct node{
    int L,R,use;
}c[N];
bool cmp(node x,node y){
    return x.R<y.R;
}
void upd(int p,int l,int r,int x){
    if(l==r){
        tr[p]++;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) upd(p<<1,l,mid,x);
    if(x>mid) upd(p<<1|1,mid+1,r,x);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
int query(int p,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr){
        return tr[p];
    }
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) res+=query(p<<1,l,mid,ql,qr);
    if(qr>mid) res+=query(p<<1|1,mid+1,r,ql,qr);
    return res;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(sp,0,sizeof(sp));
        memset(sum,0,sizeof(sum));
        memset(tr,0,sizeof(tr));
        memset(c,0,sizeof(c));
        scanf("%d%d%d%d",&n,&m,&len,&V);
        num=0;
        for(int i=1;i<=n;i++){
            int d,v,a;
            scanf("%d%d%d",&d,&v,&a);
            if(a==0){
                if(v>V) c[i].L=d,c[i].R=len,sp[i]=1;
            }
            else if(a<0){
                if(v>=V){
                    lol dis=1ll*(1ll*V*V-1ll*v*v)/(2ll*a);
                    if(1ll*(1ll*V*V-1ll*v*v)%(2ll*a)==0) dis--;
                    sp[i]=1;
                    if(dis>1ll*(len-d)){
                        c[i].L=d; c[i].R=len;
                    }
                    else c[i].L=d,c[i].R=d+dis;
                }
            }
            else{
                if(v>=V){
                    sp[i]=1;
                    c[i].L=d; c[i].R=len;
                }
                else{
                    lol dis=1ll*(1ll*V*V-1ll*v*v)/(2ll*a);
                    if(1ll*(1ll*V*V-1ll*v*v)%(2ll*a)!=0) dis++;
                    if(d+dis<=len){
                        sp[i]=1;
                        c[i].L=d+dis; c[i].R=len;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&pos[i]);
            sum[pos[i]]++;
        }
        for(int i=1;i<=len;i++){
            sum[i]+=sum[i-1];
        }
        for(int i=1;i<=n;i++){
            if(sp[i]){
                if(c[i].L==0&&sum[c[i].R]>0){
                    ++num; c[i].use=1;
                }
                else if(sum[c[i].R]-sum[c[i].L-1]>0){
                    ++num; c[i].use=1;
                }
            }
        }
        printf("%d ",num);
        sort(pos+1,pos+1+m);
        sort(c+1,c+1+n,cmp);
        ans=0;
        for(int i=1;i<=n;i++){
            if(!c[i].use) continue;
            int tmp=query(1,0,len,c[i].L,c[i].R);

            if(tmp>0) continue;
            else{
                int l=1,r=m,lst=0;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(pos[mid]<=c[i].R){
                        lst=mid; l=mid+1;
                    }
                    else r=mid-1;
                }
                upd(1,0,len,pos[lst]);
                ans++;
            }
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
