#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,L,V;
struct node{
    int d,v,a,l,r,flag;
}arr[100005];
int p[100005];
int getmnpos(int pos){
    if(pos>p[m]) return -1;
    int res=-1,l=0,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(p[mid]>=pos){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}
bool ck(int x,int y){// car x speed > V at p[y]
    if(p[y]<arr[x].d) return false;
    int s=p[y]-arr[x].d;
    int sp=arr[x].v*arr[x].v+2ll*arr[x].a*s;
    if(sp<=0) return false;
    if(sp>V*V) return true;
    return false;
}
struct stu{
    int l,r;
}B[100005];
bool cmp(stu a,stu b){
    if(a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}
void solve(){
    int mn=0x3f3f3f3f;
    scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&arr[i].d,&arr[i].v,&arr[i].a);
        mn=min(mn,arr[i].a);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&p[i]);
    }
    sort(p+1,p+1+m);
    for(int i=1;i<=n;i++){
        int dbg=0;
        if(i==3) dbg=1;
        arr[i].l=getmnpos(arr[i].d);
        if(arr[i].l==-1){
            arr[i].flag=0;
            continue;
        }
        if(arr[i].a==0){
            if(arr[i].v>V){
                arr[i].r=m;
                arr[i].flag=1;
            }else{
                arr[i].flag=0;
            }
        }else if(arr[i].a>0){
            if(!ck(i,m)){
                arr[i].flag=0;
                continue;
            }
            arr[i].flag=1;
            arr[i].r=m;
            int l=arr[i].l,r=m;
            while(l<=r){
                int mid=(l+r)/2;
                if(ck(i,mid)){
                    r=mid-1;
                    arr[i].l=mid;
                }else{
                    l=mid+1;
                }
            }
        }else{
            if(!ck(i,arr[i].l)){
                arr[i].flag=0;
                continue;
            }
            arr[i].flag=1;
            int l=arr[i].l,r=m;
            while(l<=r){
                int mid=(l+r)/2;
                if(ck(i,mid)){
                    arr[i].r=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(arr[i].flag){
            //cerr<<arr[i].l<<" "<<arr[i].r<<"\n";
            cnt++;
        }
    }
    if(m<=20){
        int ans=m;
        for(int i=0;i<(1<<m);i++){
        int tmp[25]={};
            int res=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    res++;
                    tmp[j+1]=1;
                }else{
                    tmp[j+1]=0;
                }
            }
            int fl=0;
            for(int j=1;j<=n;j++){
                if(!arr[j].flag) continue;
                int gl=0;
                for(int k=arr[j].l;k<=arr[j].r;k++){
                    if(tmp[k]){
                        gl=1;
                        break;
                    }
                }
                if(!gl){
                    fl=1;
                    break;
                }
            }
            if(!fl){
                ans=min(ans,res);
            }
        }
        printf("%lld %lld\n",cnt,m-ans);
        return;
    }else if(mn>=0){
        int ans=0;
        if(cnt){
            ans=m-1;
        }else{
            ans=m;
        }
        printf("%lld %lld\n",cnt,ans);
        return;
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        if(arr[i].flag){
            ++tot;
            B[tot].l=arr[i].l;
            B[tot].r=arr[i].r;
        }
    }
    sort(B+1,B+1+tot,cmp);
    int now=0,ans=0;
    for(int i=1;i<=tot;i++){
        if(B[i].l>now){
            now=B[i].r;
            ans++;
        }
    }
    printf("%lld %lld\n",cnt,m-ans);
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%lld",&T);
    while(T--){
        solve();
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/