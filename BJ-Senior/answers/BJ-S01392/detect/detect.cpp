#include<bits/stdc++.h>
#define ll long long
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int maxn=1e5+10;
const ll mod=998244353;
const ll inf=1e9+10;
ll n,m,t,l;
double v;
double a[maxn];

struct node{
    double d,v,a;
}q[maxn];

struct line{
    int id,checker,opt;
}p[maxn*2];

int stk[maxn*2],tp=0,instk[maxn];

int check(double dis,double opt){
    int l=1,r=m,pos=-1;
    //cout<<dis<<endl;
    while(l<=r){
      //      cout<<l<<" "<<r<<endl;

        int mid=(l+r)>>1;
        //cout<<dis<<" "<<a[mid]<<" "<<mid<<" "<<a[mid]*opt<<" "<<dis*opt<<pos<<endl;
        //if(dis==60794.9) cout<<a[mid]<<endl;
        if(opt<1){
            if(a[mid]>=dis) r=mid-1;
            else l=mid+1,pos=mid;
            //if(aa[mid+1]>)
            if(a[pos+1]>=dis&&pos>0) return pos;
            continue;
        }
        if(a[mid]>dis)r=mid-1,pos=mid;
        else l=mid+1;
        if(pos<0) continue;
        if(a[pos-1]<=dis) return pos;
    }

  //  cout<<a[pos-1]<<" "<<mid<<endl;
    return pos;
}

bool cmp(line a,line b){
    if(a.checker==b.checker) return a.opt>b.opt;
    return a.checker<b.checker;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);


    while(t--){
        memset(a,0,sizeof(a));
        tp=0;
        int tot=0;
        scanf("%lld%lld%lld%lf",&n,&m,&l,&v);

        for(int i=1;i<=n;i++){
            instk[i]=0;
            scanf("%lf%lf%lf",&q[i].d,&q[i].v,&q[i].a);
        }

        for(int i=1;i<=m;i++){
            scanf("%lf",&a[i]);
        }
        int cnt=0,cnt1=0;
        double dis1=l+1;
        for(int i=1;i<=n;i++){
            if(q[i].a>0){
                double t,dis;
                if(q[i].v>v) dis=q[i].d-1;
                else{
                    t=(v-q[i].v)/q[i].a;
                    dis=q[i].v*t+q[i].d+q[i].a*t/2.0*t;
                }

               int pos=check(dis,1);
                if(pos==-1) continue;
                p[++tot]=(line){i,pos,1};
                p[++tot]=(line){i,m,-1};
            }
            else if(q[i].a==0){
                if(q[i].v<=v||q[i].d>a[m]) continue;
                dis1=min(dis1,q[i].d);
                cnt1++;
            }
            else{
                if(q[i].v<=v) continue;

                double t,dis;
                t=(v-q[i].v)/q[i].a;
                dis=q[i].d;
                int pos=check(dis,1);
                if(pos==-1) continue;


                dis=q[i].v*t+q[i].d+q[i].a*t/2.0*t;
               // if(i==6) cout<<a[pos]<<endl;
                if(dis<=a[pos]) continue;
                p[++tot]=(line){i,pos,1};
                if(dis>a[m]) dis=a[m]+1;
                pos=check(dis,-1);
                //cout<<i<<" "<<dis<<" "<<pos<<endl;
                p[++tot]=(line){i,pos,-1};
            }
        }

        if(dis1<=l){
            //cnt1--;
            int pos=check(dis1,1);
            if(pos!=-1){
                cnt1--;
                p[++tot]=(line){n+1,pos,1};
                p[++tot]=(line){n+1,m,-1};
            }
        }

     //   cout<<1<<endl;
        sort(p+1,p+1+tot,cmp);


        for(int i=1;i<=tot;i++){
       //     cout<<i<<" "<<tot<<" "<<p[i].opt<<" "<<p[i].checker<<" "<<p[i].id<<" "<<instk[p[i].id]<<endl;
            if(p[i].opt==1){
                instk[p[i].id]=1;
                stk[++tp]=p[i].id;
            }
            else{
             //   cout<<i<<" "<<tp<<endl;
                cnt1++;
                if(!instk[p[i].id]) continue;
               // cout<<i<<endl;
                while(tp) instk[stk[tp--]]=0;
                cnt++;
            }
            //cout<<i<<endl;
        }
        //cout<<1<<endl;
        printf("%d %d\n",cnt1,m-cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
