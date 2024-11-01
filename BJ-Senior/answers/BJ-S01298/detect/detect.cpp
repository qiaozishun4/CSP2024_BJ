#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int T;
int n,m,l;
double V;
double d[N],v[N],a[N];
struct node{
    int l,r;
}q[N];
double p[N];
int ans;


#define lc (p<<1)
#define rc (p<<1|1)
struct Tree{
    int tr[N<<2],lt[N<<2];
    void push_down(int p){
        if(lt[p]==0) return ;
        lt[lc]=lt[p],lt[rc]=lt[p];
        tr[lc]=lt[p],tr[rc]=lt[p];
        lt[p]=0;
    }
    void upd(int p,int l,int r,int ul,int ur,int k){
        if(ul<=l&&r<=ur){
            tr[p]=k;
            lt[p]=k;
            return ;
        }
        push_down(p);
        int mid=l+r>>1;
        if(ul<=mid) upd(lc,l,mid,ul,ur,k);
        if(ur>=mid+1) upd(rc,mid+1,r,ul,ur,k);
        tr[p]=min(tr[lc],tr[rc]);
    }
    int query(int p,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr){
            return tr[p];
        }
        int ans=1e9;
        push_down(p);
        int mid=l+r>>1;
        if(ql<=mid) ans=query(lc,l,mid,ql,qr);
        if(qr>=mid+1) ans=min(ans,query(rc,mid+1,r,ql,qr));
        return ans;
    }
}ST,state;

int f[3005][3005];
int lm[N];
void DP(){
    memset(lm,0,sizeof(lm));
    for(int i=1;i<=n;i++){
        if(q[i].r!=0){
            lm[q[i].r]=max(lm[q[i].r],q[i].l);
            //cout<<q[i].l<<' '<<q[i].r<<' '<<endl;
        }
    }
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=i-1;j++){
            f[i][i]=min(f[i][i],f[i-1][j]+1);
        }
        for(int j=lm[i];j<=i-1;j++){
            f[i][j]=min(f[i][j],f[i-1][j]);
        }
    }
    int ans=1e9;
    for(int i=0;i<=m;i++){
        ans=min(ans,f[m][i]);
    }
    cout<<m-ans<<endl;
}

void DP_tree(){
    ST=state;
    memset(lm,0,sizeof(lm));
    for(int i=1;i<=n;i++){
        if(q[i].r!=0){
            lm[q[i].r]=max(lm[q[i].r],q[i].l);
        }
    }
    ST.upd(1,0,m,1,m,1e9);
    ST.upd(1,0,m,0,0,0);
    for(int i=1;i<=m;i++){
        int k=ST.query(1,0,m,0,i-1);
        ST.upd(1,0,m,i,i,k+1);
        if(lm[i]>0) ST.upd(1,0,m,0,lm[i]-1,1e9);
    }
    cout<<m-ST.query(1,0,m,0,m)<<endl;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            q[i].l=q[i].r=0;
        }
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf",&d[i],&v[i],&a[i]);
            //cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            scanf("%lf",&p[i]);
        }
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                if(v[i]>V){
                    q[i].l=lower_bound(p+1,p+m+1,d[i])-p;
                    q[i].r=m;
                }
                else if(v[i]==V){
                    q[i].l=upper_bound(p+1,p+m+1,d[i])-p;
                    q[i].r=m;
                }
                else{
                    double x=-(double)(v[i]*v[i]-V*V)*1.0/(double(2.0*a[i]))+d[i];
                    if(x>(double)p[m]) ans++;
                    else{
                        q[i].l=upper_bound(p+1,p+m+1,x)-p;
                        q[i].r=m;
                    }
                }
            }
            else if(a[i]==0){
                if(v[i]<=V) ans++;
                else{
                    q[i].l=lower_bound(p+1,p+m+1,d[i])-p;
                    q[i].r=m;
                }
            }
            else if(a[i]<0){
                if(v[i]<=V){
                    ans++;
                }
                else{
                    double x=-(double)(v[i]*v[i]-V*V)*1.0/(double(2.0*a[i]))+d[i];
                    if(x>p[m]){
                        q[i].l=lower_bound(p+1,p+m+1,d[i])-p;
                        q[i].r=m;
                    }
                    else{
                        q[i].l=lower_bound(p+1,p+m+1,d[i])-p;
                        q[i].r=lower_bound(p+1,p+m+1,x)-p;
                        if((double)p[q[i].r]>=(double)x) q[i].r--;
                        if(q[i].l>q[i].r) q[i].l=q[i].r=0,ans++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(q[i].l>q[i].r) q[i].l=q[i].r=0,ans++;
        }
        cout<<n-ans<<' ';
        DP_tree();
    }
    return 0;
}