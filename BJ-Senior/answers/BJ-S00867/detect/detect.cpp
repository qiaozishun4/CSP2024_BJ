#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,L,V,d[100001],v[100001],a[100001],p[100001],ans1,ans2,p1[100001];
bool b[100001],c[100001];
struct range{
    int l,r;
}e[100001];
struct car{
    int id,v;
}f[100001];
bool cmp(car x,car y){
    return x.v<y.v;
}
void dfs(int k){
    if(k>m){
        int m1=0;
        for(int i=1;i<=m;i++){
            if(c[i]){
                m1++;
                p1[m1]=p[i];
            }
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(!b[i]){
                continue;
            }
            if(a[i]>=0){
                int v2=v[i]*v[i]+2*a[i]*(p1[m1]-d[i]);
                if(!(d[i]<=p1[m1] && V*V<v2)){
                    flag=0;
                    break;
                }
                continue;
            }
            if(d[i]>p1[m1]){
                flag=0;
                break;
            }
            int l=1,r=m1;
            while(l<r){
                int mid=(l+r)/2;
                if(p1[mid]>=d[i]){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            int v2=v[i]*v[i]+2*a[i]*(p1[l]-d[i]);
            if(!(d[i]<=p1[l] && V*V<v2)){
                flag=0;
                break;
            }
        }
        if(flag){
            int cnt=0;
            for(int i=1;i<=m;i++){
                if(!c[i]){
                    cnt++;
                }
            }
            if(ans2<cnt){
                ans2=cnt;
            }
        }
        return;
    }
    c[k]=1;
    dfs(k+1);
    c[k]=0;
    dfs(k+1);
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        ans1=0;
        for(int i=1;i<=n;i++){
            b[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]>=0){
                int v2=v[i]*v[i]+2*a[i]*(p[m]-d[i]);
                if(d[i]<=p[m] && V*V<v2){
                    b[i]=1;
                    ans1++;
                }
                continue;
            }
            if(d[i]>p[m]){
                continue;
            }
            int l=1,r=m;
            while(l<r){
                int mid=(l+r)/2;
                if(p[mid]>=d[i]){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            int v2=v[i]*v[i]+2*a[i]*(p[l]-d[i]);
            if(d[i]<=p[l] && V*V<v2){
                b[i]=1;
                ans1++;
            }
        }
        cout<<ans1<<' ';
        if(n<=20 && m<=20){
            for(int i=1;i<=m;i++){
                c[i]=0;
            }
            ans2=0;
            dfs(1);
            cout<<ans2<<endl;
            continue;
        }
        bool ab=1;
        for(int i=1;i<=n;i++){
            if(a[i]<0){
                ab=0;
                break;
            }
        }
        if(ab){
            if(ans1==0){
                cout<<m<<endl;
            }
            else{
                cout<<m-1<<endl;
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            if(!b[i]){
                continue;
            }
            int l=1,r=m;
            while(l<r){
                int mid=(l+r)/2;
                if(p[mid]>=d[i]){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            r=m;
            e[i].l=l;
            while(l<r){
                int mid=(l+r+1)/2;
                int v2=v[i]*v[i]+2*a[i]*(p[mid]-d[i]);
                if(V*V<v2){
                    l=mid;
                }
                else{
                    r=mid-1;
                }
            }
            e[i].r=r;
        }
        for(int i=1;i<=n;i++){
            f[i].v=v[i];
            f[i].id=i;
        }
        sort(f+1,f+n+1,cmp);
        int tmp=m+1;
        ans2=m;
        for(int j=n;j>=1;j--){
            int i=f[j].id;
            if(!b[i]){
                continue;
            }
            if(tmp>e[i].r){
                tmp=e[i].l;
                ans2--;
            }
        }
        cout<<ans2<<endl;
    }
    return 0;
}