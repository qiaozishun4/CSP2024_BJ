#include<iostream>
#include<algorithm>
#define int long long
#define ld long long
using namespace std;
const int N=1e5+100;
struct T{
     ld d,v,a;
}car[N];
struct S{
    long long l,r;
    int i;
}seq[N];
ld p[N];
int ans,overnum;
int n,m;
ld L,V;
int getl(long long x,ld ch){
    int l=1,r=m+1;
    while(l<r){
//        cout<<l<<" "<<r<<endl;
        int mid=(l+r)>>1;
        if(p[mid]*ch<=x)   l=mid+1;
        else       r=mid;
    }
    return l;
}
bool cmp(S a,S b){
    return a.r<b.r;
}
bool cmp1(int a,int b){
    return a<b;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        ans=0,overnum=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)   seq[i].l=0,seq[i].r=0;
        for(int i=1;i<=n;i++)   cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i=1;i<=m;i++)   cin>>p[i];
        sort(p+1,p+1+m,cmp1);
        for(int i=1;i<=n;i++){
            seq[i].i=i;
            if(car[i].a==0){
                if(car[i].v<=V)  continue;
                seq[i].l=getl(car[i].d-1,1);//包括car[i].d
                seq[i].r=m;
            }
            if(car[i].a>0){
                if(car[i].v>V)  seq[i].l=getl(car[i].d-1,1),seq[i].r=m;//包括car[i].d
                else{
                    long long x=(V-car[i].v)*(V-car[i].v)+2*car[i].v*(V-car[i].v);
                    ld ch = 2*car[i].a;
                    seq[i].l=getl(car[i].d*ch+x,ch); //不包括car[i].d+x
                    seq[i].r=m;
                }
            }
            if(car[i].a<0){
                if(car[i].v<V)  continue;
                long long x=(V-car[i].v)*(V-car[i].v)+2*car[i].v*(V-car[i].v);
                x*=-1;
                ld ch = -2*car[i].a;
                seq[i].l=getl(car[i].d-1,1);//包括car[i].d
                if(car[i].d*ch+x>=L*ch)    seq[i].r=m;
                else    seq[i].r = getl(car[i].d*ch+x-1,ch)-1;
//                cout<<i<<" "<<seq[i].l<<" "<<seq[i].r<<" "<<x<<endl;
            }
            if(seq[i].l<=seq[i].r&&seq[i].r!=0) overnum++;
        }
        sort(seq+1,seq+1+n,cmp);
        int lst=0;
        for(int i=1;i<=n;i++)
        {
            if(seq[i].l>seq[i].r)   continue;
//            cout<<seq[i].l<<" "<<seq[i].r<<" "<<seq[i].i<<" "<<lst<<endl;
            if(lst<seq[i].l)    ans++,lst=seq[i].r;
        }
        cout<<overnum<<" "<<m-ans<<endl;
    }
}

