#include<bits/stdc++.h>
using namespace std;
struct car{
    int l,r;
}c[100005];
int cur=0;
int s[1000005],p[100005];
bool cmp(car l1,car l2){
    return l1.r<l2.r;
}
int dp[100005];
struct node{
    int l,r;
    int mn,lz;
}tr[400005];
void pushup(int i){
    tr[i].mn=min(tr[i<<1].mn,tr[i<<1|1].mn);
}
void pushdown(int i){
    if(tr[i].lz==-1)return;
    tr[i<<1].mn=tr[i].lz;
    tr[i<<1|1].mn=tr[i].lz;
    tr[i<<1].lz=tr[i].lz;
    tr[i<<1|1].lz=tr[i].lz;
    tr[i].lz=-1;
}
void build(int i,int l,int r){
    //cout<<i<<"?";
    tr[i].l=l,tr[i].r=r;
    tr[i].lz=-1;
    if(l==r){
        tr[i].mn=1e9;
        return;
    }
    int mid=(l+r)/2;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    pushup(i);
}
void update(int i,int l,int r,int z){
    if(l<=tr[i].l&&tr[i].r<=r){
        tr[i].mn=z;
        tr[i].lz=z;
        return;
    }
    pushdown(i);
    int mid=(tr[i].l+tr[i].r)/2;
    if(l<=mid)update(i<<1,l,r,z);
    if(mid<r)update(i<<1|1,l,r,z);
    pushup(i);
}
int query(int i,int l,int r){
    if(l==0)return 0;
    if(l<=tr[i].l&&tr[i].r<=r){
        return tr[i].mn;
    }
    pushdown(i);
    int mid=(tr[i].l+tr[i].r)/2,ans=1e9;
    if(l<=mid)ans=min(ans,query(i<<1,l,r));
    if(mid<r)ans=min(ans,query(i<<1|1,l,r));
    return ans;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    build(1,1,100000);
    while(t--){
        int n,m,len,V;
        cin>>n>>m>>len>>V;
        update(1,1,m,1e9);
        len++;
        for(int i=1;i<=len;i++)s[i]=0;
        cur=0;
        for(int i=1;i<=n;i++){
            int d,v0,a;
            cin>>d>>v0>>a;
            d++;
            if(a==0){
                if(v0>V)c[++cur]=car{d,len};
                continue;
            }
            if(a>0){
                int s=1.0*(V*V-v0*v0)/(2*a);
                s++;
                s=max(s,0);
                if(d+s<=len)c[++cur]=car{d+s,len};
                continue;
            }
            if(v0<=V)continue;
            int s=1.0*(V*V-v0*v0)/(2*a);
            s+=((V*V-v0*v0)%(2*a)!=0)-1;
            c[++cur]=car{d,min(d+s,len)};
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            p[i]++;
            s[p[i]]++;
        }
        for(int i=1;i<=len;i++)s[i]+=s[i-1];
        int ans1=0;
        for(int i=1;i<=cur;i++){
            if(s[c[i].r]-s[c[i].l-1]>0)++ans1;
            else c[i].r=1e9;
        }
        cout<<ans1<<" ";
        if(ans1==0){
            cout<<m<<"\n";
            continue;
        }
        sort(c+1,c+cur+1,cmp);
        /*for(int i=1;i<=cur&&c[i].r!=1e9;i++)
            cout<<c[i].l<<" "<<c[i].r<<"\n";*/
        int z=0,lmx=0;
        for(int i=1;i<=m;i++){
            if(z==cur||c[z+1].r==1e9)break;
            dp[i]=1e9;
            while(z+1<=cur&&c[z+1].r<p[i]){
                z++;
                lmx=max(lmx,c[z].l);
            }
            int k=0,k2=i-1;
            if(z!=0) k=lower_bound(p+1,p+i+1,lmx)-p,k2=upper_bound(p+1,p+i+1,c[z].r)-p-1;
            dp[i]=query(1,k,k2)+1;
            update(1,i,i,dp[i]);
        //    cout<<dp[i]<<" ";
        }
        //cout<<"\n";
        while(z+1<=cur&&c[z+1].r<1e9){
            z++;
            lmx=max(lmx,c[z].l);
        }
        int k=lower_bound(p+1,p+m+1,lmx)-p,k2=upper_bound(p+1,p+m+1,c[z].r)-p-1;
        cout<<m-query(1,k,k2)<<"\n";
    }
    return 0;
}
