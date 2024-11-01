#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define pii pair<int,int>
#include<cstring>
#define fi first
#define se second
using namespace std;
int n,m,l,V;
const int N=1e5+5,M=1e6+5;
int fst[N];
int lst[N];
int p[M];
int d[M];
pii a[N];
bool vis[M];
int len=0;

double calc(int v0,int v1,int a){
    double x=v1*v1-v0*v0;
    double y=2*a;
    return x/y;
}

int findfst(int x){
    int l=1,r=m;
    while(l<r){
        int mid=l+r>>1;
        if(p[mid]>=x)r=mid;
        else l=mid+1;
    }
    return l;
}

int findlst(int x){
    int pos=findfst(x);
    if(p[pos]==x)return x;
    else return p[pos-1];
}

bool cmp(pii x,pii y){
    return x.se-x.fi>y.se-y.fi;
}

void solve(){
    memset(vis,0,sizeof(vis));
    len=0;
    cin>>n>>m>>l>>V;
    for(int i=1;i<=n;i++){
        int d,v,a;
        cin>>d>>v>>a;
        if(a<0){
            if(v>V){
                fst[i]=d;
                lst[i]=d+int(calc(v,V,a));
            }else{
                fst[i]=2e9;
                lst[i]=-2e9;
            }
        }else if(a==0){
            if(v>V){
                fst[i]=d;
                lst[i]=2e9;
            }else{
                fst[i]=2e9;
                lst[i]=-2e9;
            }
        }else{
            fst[i]=d+ceil(calc(v,V,a));
            lst[i]=2e9;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }

    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        int pos=findfst(fst[i]);
        if(fst[i]<=p[m] && p[pos]<=lst[i]){
            ans1++;
           // cout<<i<<" "<<fst[i]<<" "<<lst[i]<<" "<<findfst(fst[i])<<"\n";
            a[++len]={fst[i],lst[i]};
        }
    }
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=len;i++){
        //cout<<a[i].fi<<" "<<a[i].se<<endl;
    }
    int pre=-1;
    for(int i=1;i<=len;i++){
        //cout<<i<<" "<<pre<<endl;
        if(a[i].fi<=pre && pre<=a[i].se){
        }else{
            int pos=findlst(min(a[i].se,a[i+1].se));
            pre=pos;
            ans2++;
        }
    }
    cout<<ans1<<" "<<m-ans2<<'\n';


}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
