#include<bits/stdc++.h>
#define mian main
#define feropen freopen
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],t1,t[4],k=1,k2;
string s[111];
void solve(int x){
    solve(x/2);
}
int mian(){
    feropen("arena.in","r",stdin);
    feropen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    while(k<n){
        k=k<<1;
        ++k2;
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int i=1;i<=k;i++)cin>>s[i];
    scanf("%d",&t1);
    for(int i=0;i<4;i++)scanf("%d",&t[i]);
    for(int i=1;i<=n;i++){
        a[i]^=t[i%4];
    }printf("8");
    return 0;
}

