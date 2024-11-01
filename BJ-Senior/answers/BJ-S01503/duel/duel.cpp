#include<bits/stdc++.h>
using namespace std;
int n,a[100010],maxx;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
        maxx=max(maxx,a[x]);
    }
    cout<<maxx<<'\n';
    return 0;
}
