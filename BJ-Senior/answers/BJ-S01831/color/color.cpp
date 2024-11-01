#include <bits/stdc++.h>
using namespace std;

const long long MAXN=1e5+5;
struct node{int l,r;}t[MAXN];

int n,m,l,V,d[MAXN],v[MAXN],a[MAXN],p[MAXN],cf[MAXN],qzh[MAXN];
bool vis[MAXN];

double speed(int i){
    if(a[i]==0){
        if(v[i]>V)return d[i]-1;
        return l;
    }
    if(a[i]>0)return (V*V-v[i]*v[i])*1.0/(2*a[i])+d[i];
    return (v[i]*v[i]-V*V)*1.0/(2*(0-a[i]))+d[i];
}


int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
int t;cin>>t;while(t--){
    int n;cin>>n;int a[1005];
for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
cout<<ans<<endl;}
    fclose(stdin);
    fclose(stdout);
}
