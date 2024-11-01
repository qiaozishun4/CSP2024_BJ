#include<bits/stdc++.h>

using namespace std;
#define ls (q<<1)
#define rs (q<<1)|1
#define ll long long
template<class T>void read(T &x){
    x=0;
    int f=0;
    char c=getchar();
    while(!isdigit(c)){
        f|=(c=='-');
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(f)x=-x;
    return;
}
const int N=2e5+5,M=1e6+5;
int a[N];
ll cnt=0;
struct node{
    int l,r;ll maxn;
}t[N<<2];
void pushup(int q){
    t[q].maxn=max(t[ls].maxn,t[rs].maxn);
    return;
}
void build(int q,int l,int r){
    cnt++;
    t[q].l=l;t[q].r=r;
    if(l==r){
        t[q].maxn=0;
        return;
    }
    int mid=(l+r)>>1;
    if(l<=mid)build(ls,l,mid);
    if(r>mid)build(rs,mid+1,r);
    pushup(q);
    return;
}
ll ask(int q,int l,int r){
    cnt++;
    if(l>r)return 0;
    if(t[q].l>=l&&t[q].r<=r){
        return t[q].maxn;
    }
    int mid=(t[q].l+t[q].r)>>1;
    ll ans=0;
    if(l<=mid)ans=ask(ls,l,r);
    if(r>mid)ans=max(ans,ask(rs,l,r));
    return ans;
}
void change(int q,int x,ll d){
    cnt++;
    if(t[q].l==t[q].r){
        t[q].maxn=max(t[q].maxn,d);
        return;
    }
    int mid=(t[q].l+t[q].r)>>1;
    if(x<=mid)change(ls,x,d);
    else change(rs,x,d);
    pushup(q);
    return;
}
void cl(int x){
    cnt+=x;
    for(int i=1;i<=x;i++)t[i].maxn=t[i].l=t[i].r=0;
    return;
}
int d[N],v[M],f[M];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    read(t);
    while(t--){
        int n;
        read(n);
        cl(n<<2);
        build(1,1,n);
        for(int i=1;i<=n;i++){
            read(a[i]);
            d[i]=a[i];
            f[i]=v[i]=0;
            //printf("%d\n",a[i]);
        }
        sort(d+1,d+1+n);
        int tot=unique(d+1,d+1+n)-d-1;
        for(int i=1;i<=n;i++){
            v[a[i]]=lower_bound(d+1,d+1+tot,a[i])-d;
          //  b[v[a[i]]]=a[i];
            if(!f[a[i]])f[a[i]]=i;
           // printf("%d*\n",v[a[i]]);
        }
        //puts("******88");
        //printf("%d*\n",tot);
        ll ad=0;
        for(int i=1;i<=n;i++){
            int c=v[a[i]];
            ll z;
            if(f[a[i]]==i)z=max(ask(1,1,c-1),ask(1,c+1,tot));
            else z=max(ask(1,c,c)+a[i],max(ask(1,1,c-1),ask(1,c+1,tot)));
            int flag=0;
            if(a[i]==a[i-1])ad+=a[i],flag=1;
            if(i>1)change(1,v[a[i-1]],z-flag*a[i]);
          //  printf("%lld*\n",ask(1,10,10));
            //for(int i=1;i<=tot;i++){
             //   printf("%d ",ask(1,i,i));
           // }//puts("*");
        }
        //cout<<ad<<endl;
        printf("%lld\n",ask(1,1,tot)+ad);
    }
   // printf("%lld",cnt);
    return 0;
}

/*1
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13*/
