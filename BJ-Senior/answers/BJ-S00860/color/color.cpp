#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int m, a[100005], n;
vector<int> dict[1000005];

long long dfs(int x, int y, long long k){
    long long ans = k;
    bool f=0;
    for(int i=y+1; i<=n; i++){
        if(f == 0 && y>0 && a[i]==a[y-1]){
             ans = max(ans, dfs(y-1, y+1, k+a[y-1]));
             f = 1;
        }
        if(dict[a[i]].size() > 1){
            for(int j=0; j<dict[a[i]].size(); j++){
                if(dict[a[i]][j] > i){
                    long long cnt = 0;
                    for(int l=i+1; l<dict[a[i]][j]; l++){
                        if(a[l] == a[l+1]) cnt += a[l];
                        if(l == y+2 && a[l] == a[y-1]) cnt += a[l];
                    }
                    ans = max(ans, dfs(i, dict[a[i]][j], k+a[i]+cnt));
                }
            }
        }
    }
    return ans;
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> m;
    for(int i=1; i<=m; i++){
        memset(a, 0, sizeof(a));
        memset(dict, 0, sizeof(dict));
        cin >> n;
        for(int j=1; j<=n; j++){
            cin >> a[j];
            dict[a[j]].push_back(j);
        }
        cout << dfs(0, 0, 0) << endl;
    }
    return 0;
}

