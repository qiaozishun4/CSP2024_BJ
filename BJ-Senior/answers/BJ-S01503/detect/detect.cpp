#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,a,d;
}x[100010];
struct need{
    int l,r;
}y[100010];
int n,m,L,s[100010],cnt,sum;
double V;
double now_speed(int v,int a,int s){
    double now=v*v*1.0+2.0*a*s;
    if(now<0)return 0;
    return sqrt(now);
}
int find(int v,int a,int d){
    if(a>=0){
        if(s[m]<d)return -1;
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)/2;
            if(s[mid]<d)l=mid+1;
            else r=mid;
        }
        if(now_speed(v,a,s[m]-d)<=V)return -1;
        r=m;
        while(l<r){
            int mid=(l+r)/2;
            if(now_speed(v,a,s[mid]-d)<=V)l=mid+1;
            else r=mid;
        }
        return l;
    }else{
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)/2;
            if(s[mid]<d)l=mid+1;
            else r=mid;
        }
        if(now_speed(v,a,s[l]-d)<=V)return -1;
        r=m;
        while(l<r){
            int mid=(l+r+1)/2;
            if(now_speed(v,a,s[mid]-d)<=V)r=mid-1;
            else l=mid;
        }
        return l;
    }
}
bool cmp(need x,need y){
    return x.r<y.r;
}
void solve(){
    sum=0;
    cnt=0;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++)cin>>x[i].d>>x[i].v>>x[i].a;
    for(int i=1;i<=m;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
        if(x[i].v>V)sum++;
        if(x[i].a>=0){
            int ans=find(x[i].v,x[i].a,x[i].d);
            if(ans==-1)continue;
            cnt++;
            y[cnt].l=ans;
            y[cnt].r=m;
        }else{
            int ans=find(x[i].v,x[i].a,x[i].d);
            if(ans==-1)continue;
            int l=1,r=m;
            while(l<r){
                int mid=(l+r)/2;
                if(s[mid]<x[i].d)l=mid+1;
                else r=mid;
            }
            cnt++;
            y[cnt].l=l;
            y[cnt].r=ans;
        }
    }
    cout<<cnt<<" ";
    sort(y+1,y+cnt+1,cmp);
    sum=0;
    int last=0;
    for(int i=1;i<=cnt;i++){
        if(y[i].l>last){
            sum++;
            last=y[i].r;
        }
    }
    cout<<m-sum<<'\n';
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
