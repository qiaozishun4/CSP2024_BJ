#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,f[100100],sum,ans,ri,mi,ma;
struct point{
    int a,b,c,d,e;
}a[100100];
int qian[1000100];
bool cmp(point x,point y){
    if(x.d!=y.d)return x.d<y.d;
    return x.e<y.e;
}
int ups(int x,int y,int z){
    double res=(z*z-x*x)/(2*y);
    int re=int(res);
    if(res>re*1.0)return re+1;
    return re;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        scanf("%d %d %d %d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++)scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
        for(int i=1;i<=m;i++)scanf("%d",&f[i]);
        sort(f+1,f+1+m);
        sum=1;
        memset(qian,0,sizeof(qian));
        for(int i=1;i<=l;i++){
            if(i==f[sum])qian[i]=qian[i-1]+1,sum++;
            else qian[i]=qian[i-1];
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].c<0&&a[i].b>v)a[i].d=a[i].a,a[i].e=a[i].a+ups(a[i].b,a[i].c,v);
            else if(a[i].c>=0&&a[i].b>v)a[i].d=a[i].a,a[i].e=l;
            else if(a[i].c>0&&a[i].b<=v)a[i].d=a[i].a+ups(a[i].b,a[i].c,v),a[i].e=l;
            else a[i].d=a[i].e=0;
            a[i].d=min(a[i].d,l),a[i].e=min(a[i].e,l);
            if(qian[a[i].e]-qian[a[i].d-1]>=1)ans++;
            //if(a[i].d>=844954)ans++;
            else a[i].d=0,a[i].e=l;
        }
        //for(int i=1;i<=n;i++)printf("%d %d\n",a[i].d,a[i].e);
        printf("%d ",ans);
        if(ans==0){
            printf("%d\n",m);
            continue;
        }
        sort(a+1,a+1+n,cmp);
        ri=1,ans=0;
        while(ri<=n){
            mi=a[ri].e,ma=a[ri].d;
            while(a[ri+1].d<=mi&&a[ri+1].e>=ma&&qian[min(mi,a[ri+1].e)]-qian[max(ma,a[ri+1].d)-1]>=1)ri++,mi=min(mi,a[ri].e),ma=max(ma,a[ri].d);
            ans++;
            ri=ri+1;
        }
        printf("%d\n",m-ans);
    }

    return 0;
}
