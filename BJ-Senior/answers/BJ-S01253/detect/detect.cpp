#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long t,n,m,L,V,ans1,ans2;
struct CAR{
    long long d,v,a;
}car[N];
long long p[N];
long long calv(long long i,long long x){
    return max(car[i].v+2*car[i].a*(x-car[i].d),(long long)0);
}
pair<long long,long long>lll[N];
long long cnt;
int nop[N*10];
void erfen(long long i){
    if(car[i].a==0){
        if(car[i].v>V){
            lll[++cnt].first=nop[car[i].d]+(p[nop[car[i].d]]<car[i].d);
            lll[cnt].second=m;
            if(lll[cnt].first>lll[cnt].second) cnt--;
            else ans1++;
        }
    }
    else if(car[i].a>0){
        int l=car[i].d,r=L,mid,tmp=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(calv(i,mid)>V){
                tmp=mid;
                r=mid-1;
            }else l=mid+1;
        }
        if(tmp!=-1){
            lll[++cnt].first=nop[tmp]+(p[nop[tmp]]<tmp);
            lll[cnt].second=m;
            if(lll[cnt].first>lll[cnt].second) cnt--;
            else ans1++;
        }
    }else if(car[i].v>V){
        int l=car[i].d,r=L,mid,tmp;
        while(l<=r){
            mid=l+(r-l)/2;
            if(calv(i,mid)>V){
                tmp=mid;
                l=mid+1;
            }else r=mid-1;
        }
        lll[++cnt].first=nop[car[i].d]+(p[nop[car[i].d]]<car[i].d);
        lll[cnt].second=nop[tmp];
        if(lll[cnt].first>lll[cnt].second) cnt--;
        else ans1++;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        ans1=0;
        ans2=0;
        cnt=0;
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        V=V*V;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&car[i].d,&car[i].v,&car[i].a);
            car[i].v*=car[i].v;
        }

        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
        }
        if(p[1]==0) nop[0]=1;
        for(int i=1;i<=L;i++){
            if(p[nop[i-1]+1]==i) nop[i]=nop[i-1]+1;
            else nop[i]=nop[i-1];
        }
        for(int i=1;i<=n;i++){
            erfen(i);
        }
        sort(lll+1,lll+cnt+1);
        //for(int i=1;i<=cnt;i++) cout<<lll[i].first<<' '<<lll[i].second<<endl;
        long long ll=lll[1].first,rr=lll[1].second;
        for(int i=2;i<=cnt;i++){
            if(lll[i].second<rr) rr=lll[i].second;
            if(lll[i].first>rr){
                ans2++;
                ll=lll[i].first;
                rr=lll[i].second;
            }
            else if(lll[i].first>ll) ll=lll[i].first;
        }
        if(ans1) ans2++;
        printf("%lld %lld\n",ans1,m-ans2);
        //cout<<endl;
    }
    return 0;
}
