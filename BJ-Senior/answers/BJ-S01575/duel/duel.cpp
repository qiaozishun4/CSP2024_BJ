#include <bits/stdc++.h>
using namespace std;

int n,a[100005];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=2;i<=100000;i++){
        a[i]+=max(0,a[i-1]-a[i]);
    }
    cout<<a[100000];
    return 0;
}
