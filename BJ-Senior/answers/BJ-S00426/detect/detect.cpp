#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d,v,a;
int p[100001];
struct node{
    int l,r;
}car[100001];
int b,an,ans,cnt;
bool cmp(node q,node w){
    return q.r<w.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        b=-1;
        cnt=0;
        an=0;
        ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i){
            cin>>d>>v>>a;
            int l,r;
            if(a>0){
                l=d+(V*V-v*v)/(2*a)+1;
                r=L;
                if(l>L) --i,--n;
                else car[i].l=l,car[i].r=r;
            }
            else if(a<0){
                if(v<=V) --i,--n;
                else{
                    l=d;
                    double tmp=1.0*(V*V-v*v)/(2*a);
                    int ymp=(V*V-v*v)/(2*a);
                    r=d+(V*V-v*v)/(2*a);
                    if(tmp-ymp==0) --r;
                    if(r>L) r=L;
                    car[i].l=l,car[i].r=r;
                }
            }
            else if(a==0){
                if(v<=V) --i,--n;
                else car[i].l=d,car[i].r=L;
            }
        }
        for(int i=1;i<=m;++i) cin>>p[i];
        sort(p+1,p+m+1);
        sort(car+1,car+n+1,cmp);
        for(int i=1;i<=n;++i){
            if(b>=car[i].l&&b<=car[i].r) continue;
            while(cnt<=m&&p[cnt]<=car[i].r) ++cnt;
            --cnt;
            if(cnt==-1){
                cnt=0;
                ++an;
                continue;
            }
            if(p[cnt]>=car[i].l) b=p[cnt],++ans;
            else ++an;
        }
        cout<<n-an<<" "<<m-ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
