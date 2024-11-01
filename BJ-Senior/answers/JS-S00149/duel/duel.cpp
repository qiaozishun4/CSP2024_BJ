#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int h=0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[h+1]){
            h++;
        }
    }
    cout<<n-h<<endl;
    return 0;
}
