#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=n,last=1;
    for (int i=1;i<=n;i++){
        if (a[last]<a[i]){
            last++;
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
