#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=100000+10;
int n,m,L,V,p[N],p2[N];
struct PP{
    int d,v,a;
    int l,r;
    PP(){
        d=v=a=l=r=0;
    }
    bool operator<(const PP&rhs)const{return l!=rhs.l?l<rhs.l:r<rhs.r;}
}a1[N],a2[N];

void _insert(int l,int r,int &pos){
    if(l>L)return;
    int ps=upper_bound(p+1,p+1+m,r)-p-1;
    if(ps==m+1)return;
    p2[++pos]=p[ps];
}

void test(){
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++){
        cin>>a1[i].d>>a1[i].v>>a1[i].a;
        a1[i].l=a1[i].r=L+1;
        if(a1[i].a==0){
            if(a1[i].v>V){
                a1[i].l=a1[i].d;
            }
            continue;
        }else if(a1[i].a>0){
            if(a1[i].v>V){
                a1[i].l=a1[i].d;a1[i].r=L+1;
            }else{
                a1[i].r=L+1;
                a1[i].l=floor(a1[i].d+(V*V-a1[i].v*a1[i].v)/(2.0*a1[i].a))+1;
            }
        }else{
            if(a1[i].v<=V)continue;
            a1[i].l=a1[i].d;
            a1[i].r=ceil(a1[i].d+(V*V-a1[i].v*a1[i].v)/(2.0*a1[i].a))-1;
        }
    }
    for(int i=1;i<=m;i++)cin>>p[i];p[m+1]=0;sort(p+1,p+1+m);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(p+1,p+1+m,a1[i].l)-p;
        if(pos!=m+1&&a1[i].l<=p[pos]&&p[pos]<=a1[i].r){
            a2[++cnt]=a1[i];
        }
    }cout<<cnt<<" ";
    /**********/
    sort(a2+1,a2+1+cnt);
    if(cnt==0){
        cout<<m<<endl;return;
    }
    int l=a2[1].l,r=a2[1].r,tl,tr,cnt2=0;
    for(int i=2;i<=cnt;i++){
        tl=max(l,a2[i].l),tr=min(r,a2[i].r);
        if(tl>tr){
            _insert(l,r,cnt2);
            tl=a2[i].l,tr=a2[i].r;
        }else{
            int pos=lower_bound(p+1,p+1+m,tl)-p;
            if(!(pos!=m+1&&tl<=p[pos]&&p[pos]<=tr)){
                _insert(l,r,cnt2);
                tl=a2[i].l,tr=a2[i].r;
            }
        }l=tl,r=tr;
    }
    _insert(l,r,cnt2);
    cout<<m-cnt2<<'\n';
}

signed main(){
    /****************************************************************************************************************/
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)test();
    return 0;
}
