#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],sum[N];
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    int cnt=1;sum[cnt]=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1])sum[++cnt]++;
        else sum[cnt]++;
    }
    //for(int i=1;i<=cnt;i++)cout<<sum[i]<<" ";
    int ans=sum[cnt];
    for(int i=cnt-1;i>=1;i--){
        if(sum[i]>=ans)ans=sum[i];
    }
    cout<<ans;
    return 0;
}
