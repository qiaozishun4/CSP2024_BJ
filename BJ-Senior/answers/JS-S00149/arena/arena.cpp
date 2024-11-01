#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int n,m;
int a[N],d[N][N],c[N],k,x[5];
bool ok[N];
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    k=log2(n);
    int tmp=(1<<k);
    if(tmp<n)k++;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=(1<<(k-i));j++){
            cin>>d[i][j];
        }
    }
    cin>>x[0];
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n;i++)a[i]=a[i]^x[i%4];
    int ans=0;
    
    for(int i=1;i<=m;i++){
        tmp=0;
        for(int j=1;j<=c[i];j++){
            tmp+=j;
        }
        ans^=(i*tmp);
    }
    cout<<ans<<endl;
    return 0;
}
