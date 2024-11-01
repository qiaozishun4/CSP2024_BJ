#include <bits/stdc++.h>
using namespace std;
const int N=100005;
long long int a[N],b[N];
long long int n, x, num;
long long int ans;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x]++;
    }

    for(int i=1;i<N;i++){
        if(a[i])if(a[i]>=ans)ans=a[i];
    }
    //for(int i=1;i<=num;i++)cout<<b[i]<<" ";
    cout<<ans;
    return 0;
}
