#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],f[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    int cur=0;
    for (int i=1;i<=N;i++){
        if (a[i]==0) continue;
        f[++cur]=a[i];
    }
    int sum=f[1];
    for (int i=2;i<=cur;i++){
        sum-=min(f[i],sum);
        sum+=f[i];
    }
    cout<<sum;
    return 0;
}
