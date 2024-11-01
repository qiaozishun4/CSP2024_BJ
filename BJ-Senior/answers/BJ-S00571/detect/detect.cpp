#include<iostream>
#include<cmath>
#include<algorithm>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(l);i>=(r);i--)
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
typedef double ld;
const ld eps=1e-9;
struct node{
    int l,r;
}an[maxn];
int ap[maxn];
bool cmp(node a,node b){
    return a.l<b.l;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int it;
    cin>>it;
    while(it--){
        int in,im,il,V,tot=0;
        scanf("%d %d %d %d",&in,&im,&il,&V);
        rep(v1,1,in){
            int id,iv,ia;
            scanf("%d %d %d",&id,&iv,&ia);
            if(ia>0){
                if(iv>V)an[++tot]={id,il};
                else{
                    ld t=ld(V-iv+eps)/ld(ia),s=id+iv*t+t*t*ia*0.5;
                    if(s<=il)an[++tot]={(int)ceil(s),il};
                }
            }
            else if(ia==0){
                if(iv>V)an[++tot]={id,il};
            }
            else if(iv>V){
                ld t=ld(V-iv)/ld(ia),s=id+iv*t+t*t*ia*0.5;
                // cout<<v1<<' '<<t<<' '<<s<<endl;
                // cout<<s<<' '<<il<<endl;
                an[++tot]={id,min(il,(int)floor(s-eps))};
            }
        }
        rep(v1,1,im)scanf("%d",ap+v1);
        int nt=0;
        rep(v1,1,tot){
            // cout<<an[v1].l<<' '<<an[v1].r<<endl;
            int pos=upper_bound(ap+1,ap+im+1,an[v1].r)-1-ap;
            if(pos&&ap[pos]>=an[v1].l){
                int pos2=lower_bound(ap+1,ap+pos+1,an[v1].l)-ap;
                // cout<<pos<<'-'<<pos2<<endl;
                an[++nt]={pos2,pos};
            }
        }
        sort(an+1,an+nt+1,cmp);
        ap[0]=-inf;
        int p1=0,p2=1,ans=0,minr=0;
        while(p2<=nt){
            while(p1<im&&p1<minr&&p1<an[p2].l)p1++;
            // cout<<p1<<endl;
            if(p1<an[p2].l)ans++,minr=inf;
            // cout<<"*"<<ans<<endl;
            while(p1<im&&p1<an[p2].l)p1++;
            // cout<<an[p2].l<<' '<<an[p2].r<<' '<<p1<<" "<<minr<<endl;
            minr=min(minr,an[p2].r);
            p2++;
        }
        printf("%d %d\n",nt,im-ans);
        // break;
    }
    return 0;
}