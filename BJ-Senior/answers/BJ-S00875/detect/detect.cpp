#include<bits/stdc++.h>
//#define int long long
using namespace std;

int t,n,m,l,v,cntc;
int p[100010],s[100010],pl[100010],pr[100010];
bool vis[100010];
struct node{
    int d,v,a;
}cars[100010];
struct node2{
    int lc,rc;
}arr[100010];

bool check(int now,int tot){
    vis[now]=1;
    if(tot==0){
        if(now>m){
            memset(s,0,sizeof(s));
            for(int i=1;i<=m;i++){
                s[i]=s[i-1]+(int)((bool)vis[i]);
            }
            bool flg=1;
            for(int i=1;i<=n;i++){
                if(pl[i]>pr[i]){
                    continue;
                }
                if(s[pl[i]-1]==s[pr[i]]){
                    flg=0;
                    break;
                }
            }
            return flg;
        }
        return check(now+1,tot);
    }
    if(m-now+1==tot){
        vis[now]=0;
        return check(now+1,tot-1);
    }
    bool flg=check(now+1,tot);
    vis[now]=0;
    return flg||check(now+1,tot-1);
}

signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        memset(cars,0,sizeof(cars));
        memset(arr,0,sizeof(arr));
        cin>>n>>m>>l>>v;
        int tot=n;
        bool isa=true,isb=true;
        for(int i=1;i<=n;i++){
            cin>>cars[i].d>>cars[i].v>>cars[i].a;
            if(cars[i].a==0){
                isb=0;
                if(cars[i].v>v){
                    arr[i].lc=cars[i].d;
                    arr[i].rc=l;
                }
                else{
                    arr[i].lc=arr[i].rc=l+1;
                    tot--;
                }
            }
            else if(cars[i].a>0){
                isa=0;
                if(cars[i].v>v){
                    arr[i].lc=cars[i].d;
                    arr[i].rc=l;
                }
                else{
                    double a=v*v-cars[i].v*cars[i].v,b=2*cars[i].a;
                    int c=v*v-cars[i].v*cars[i].v,d=2*cars[i].a,e;
                    if(c%d==0){
                        e=c/d;
                    }
                    else{
                        e=floor(a/b);
                    }
                    if(cars[i].d+e+1>l){
                        arr[i].lc=arr[i].rc=l+1;
                        tot--;
                    }
                    else{
                        arr[i].lc=cars[i].d+e+1;
                        arr[i].rc=l;
                    }
                }
            }
            else if(cars[i].a<0){
                isa=isb=0;
                if(cars[i].v<=v){
                    arr[i].lc=arr[i].rc=l+1;
                    tot--;
                }
                else{
                    double a=cars[i].v*cars[i].v-v*v,b=-2*cars[i].a;
                    int c=cars[i].v*cars[i].v-v*v,d=-2*cars[i].a,e;
                    if(c%d==0){
                        e=c/d;
                    }
                    else{
                        e=ceil(a/b);
                    }
                    if(cars[i].d+e-1>l){
                        arr[i].lc=cars[i].d;
                        arr[i].rc=l;
                    }
                    else{
                        arr[i].lc=cars[i].d;
                        arr[i].rc=cars[i].d+e-1;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(tot==0){
            cout<<0<<' '<<m<<'\n';
            continue;
        }
        cntc=0;
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++){
            pl[i]=lower_bound(p+1,p+m+1,arr[i].lc)-p;
            pr[i]=upper_bound(p+1,p+m+1,arr[i].rc)-p-1;
            if(pl[i]>pr[i]){
                cntc++;
            }
        }
        if(isa||isb){
            cout<<n-cntc<<' ';
            if(n-cntc==0){
                cout<<m<<'\n';
            }
            else{
                cout<<m-1<<'\n';
            }
            continue;
        }
        for(int i=m;i>=0;i--){
            if(check(1,i)){
                cout<<n-cntc<<' '<<i<<'\n';
                break;
            }
        }
    }

    return 0;
}
