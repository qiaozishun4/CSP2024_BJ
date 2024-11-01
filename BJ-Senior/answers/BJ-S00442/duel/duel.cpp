#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],p=0,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int i=1,x=0;
    while(i<=n){
        x=upper_bound(a+p+1,a+n+1,a[i])-a;
        if(x>n) break;
        p=x;
        //cout<<i<<" "<<x<<endl;
        i++;
    }
    cout<<n-i+1;
    return 0;
}