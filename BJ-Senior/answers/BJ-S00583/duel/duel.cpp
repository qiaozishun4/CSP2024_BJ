#include<bits/stdc++.h>
using namespace std;
int n,f[100010],g[100010],ans;
queue<int> d;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        f[tmp]++;
        g[tmp]++;
    }
    for(int i=1;i<=100005;i++){
        while(f[i]--){
            d.push(i);
        }
        while((!d.empty()) && i>d.front() && g[i]!=0){
            g[i]--;
            d.pop();
            ans++;
        }
    }
    cout<<(n-ans);
    return 0;
}
