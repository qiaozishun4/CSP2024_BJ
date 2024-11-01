#include <iostream>
#include<algorithm>
using namespace std;
int a[100005];
long long n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        a[t]++;
    }
    int ans=-1;
    for(int i=1;i<=100005;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}
