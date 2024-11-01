#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,L,V,p[N],sum,cnt;
bool isa=1;
struct node{
    int d,v,a;
    double s;
};
node c[N];
struct n2{
    int l,r;
};
n2 d[N],d2[N];
int ld,ld2;
bool cmp(n2 x,n2 y){
    if(x.l==y.l){
        return x.r>y.r;
    }
    return x.l<y.l;
}
int solve1(){
    sort(d+1,d+ld+1,cmp);
    for(int i=1;i<=ld;i++){
        if(i==ld||d[i].r<d[i+1].r){
            ld2++;
            d2[ld2]=d[i];
            //cout<<d[i].l<<" "<<d[i].r<<endl;
        }
    }
    int ans=0,i=1,j;
    while(i<=n){
        ans++;
        j=d2[i].r;
        //cout<<j<<endl;
        i++;
        while(d2[i].l<=j&&i<=n) i++;
    }
    return ans;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        cnt=ld=ld2=0;
        isa=1;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a!=0){
                c[i].s=(V*V-c[i].v*c[i].v)*0.5/c[i].a;
                isa=0;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(c[i].a>0){
                if(c[i].v>V){
                    d[++ld].r=m+1;
                    d[ld].l=(lower_bound(p+1,p+m+1,c[i].d)-p);
                    sum=d[ld].r-d[ld].l;
                }
                else{
                    d[++ld].r=m+1;
                    d[ld].l=(lower_bound(p+1,p+m+1,c[i].s+c[i].d)-p);
                    sum=d[ld].r-d[ld].l;
                }
            }
            else if(c[i].a<0){
                if(c[i].v>V){
                    d[++ld].r=lower_bound(p+1,p+m+1,c[i].s+c[i].d)-p;
                    d[ld].l=lower_bound(p+1,p+m+1,c[i].d)-p;
                    sum=d[ld].r-d[ld].l;
                }
                else{
                    sum=0;
                }
            }
            else{
                if(c[i].v>V){
                    d[++ld].r=m+1;
                    d[ld].l=(lower_bound(p+1,p+m+1,c[i].d)-p);
                    sum=d[ld].r-d[ld].l;
                }
                else{
                    sum=0;
                }
            }
            if(sum>0){
                //cout<<d[ld].l<<" "<<d[ld].r<<endl;
                cnt++;
            }
        }
        cout<<cnt<<" ";
        if(isa){
            if(cnt==0){
                cout<<m<<endl;
            }
            else{
                cout<<m-1<<endl;
            }
        }
        else{
            cout<<m-solve1()<<endl;
        }
        //cout<<endl;
    }
    return 0;
}