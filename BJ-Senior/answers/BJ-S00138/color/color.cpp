#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int T,n,a[N],maxn;
vector<int> G[N];
void dfs(int lastr, int lastb, int v, int i){
    if(i > n){
        maxn = max(maxn,v);
        return;
    }
    if(a[i] == a[lastr]) v += a[i];
    dfs(i,lastb,v,i+1);
    if(a[i] == a[lastr]) v -= a[i];
    if(a[i] == a[lastb]) v += a[i];
    dfs(lastr,i,v,i+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--){
        maxn = 0;
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        dfs(0,0,0,1);
        cout << maxn << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
