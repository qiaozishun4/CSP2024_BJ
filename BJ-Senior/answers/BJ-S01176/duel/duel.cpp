#include <bits/stdc++.h>
using namespace std;
int n,a[100005],t[100005];
bool vis[100005];
int d[100005];
void zt(int p){
    for(int i = 1; i < p; i++){
        if(d[i+1]-d[i] >= 0){
            continue;
        } else{
            d[i+1] = d[i];
        }
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t[a[i]]++;
        if(vis[a[i]] == false) vis[a[i]] = true;
    }
    int p = 0;
    for(int i = 1; i <= 100005; i++){
        if(vis[i] == 1){
            ++p;
            d[p] = t[i];
        }
    }
    zt(p);
    cout << d[p] << endl;
    return 0;
}
