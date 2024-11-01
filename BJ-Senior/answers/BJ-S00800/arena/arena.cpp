#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m,a[N],c[N],d[N],x[4];
int ma(int r){
    int mx=0;
    for(int i=1;i<=r;i++)mx=max(mx,a[i]);
    return mx;
}
int main(){

    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=ceil(log2(n));i++){
        cin>>d[i];
    }
    int t;
    cin>>t;
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        int p[N];
        for(int i=1;i<=n;i++){
            p[i]=a[i]^x[i%4];
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(c[i]==1)ans^=(1*i);
            if(pow(log2(i),2)!=i){
                ans^=(i*(ma(c[i])+(long long)ceil(log2(i))));
            }else{
                ans^=(i*ma(c[i]));
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
