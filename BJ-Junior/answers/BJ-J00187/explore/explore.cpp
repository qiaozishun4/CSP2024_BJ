#include<bits/stdc++.h>
using namespace std;
set<pair<int, int> >st;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char mp[1005][1005];int n, m, k, x, y, d;
void f(int x, int y, int d, int k){
    st.insert(make_pair(x, y));
    if(k == 0)return;
    while(k > 0){
        int fx = x + dx[d], fy = y + dy[d];
        if(fx > 0 && fx <= n && fy > 0 && fy <= m && mp[fx][fy] == '.'){
            f(fx, fy, d, k - 1);
            break;
        }else{
            k--;
            d = (d + 1) % 4;
        }
    }
    return;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        st.clear();

        cin >> n >> m >> k >> x >> y >> d;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> mp[i][j];
            }
        }
        //f(x, y, d, k);
        for(int i = 1; i <= k; i++){
            st.insert(make_pair(x, y));
            while(i <= k){
                int fx = x + dx[d], fy = y + dy[d];
                if(fx > 0 && fx <= n && fy > 0 && fy <= m && mp[fx][fy] == '.'){
                    x = fx; y = fy;
                    break;
                }else{
                    i++;
                    d = (d + 1) % 4;
                }
            }
        }
        cout << st.size() << endl;
    }

    return 0;
}
