#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    vector<vector<char>> a;
    vector<vector<bool>> v;
    while (T--){
        int ans = 0;
        int newx,newy;
        int n,m,k,x,y,d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        a.resize(n);
        v.resize(n);
        for (int i = 0;i < n;i++){
            a[i].resize(m);
            v[i].resize(m);
            for (int j = 0;j < m;j++){
                cin >> a[i][j];
                v[i][j] = 0; // not visited
            }
        }
        newx = x-1;
        newy = y-1;
        for (int i = 0;i < k;i++){
            // visit a place or turn right
            // if that place are not visited
            // then ans++
            if (!v[newx][newy]){
                v[newx][newy] = 1;
                ans++;
                // cout << "found-new-place:" << newx + 1 << " " << newy + 1 << "    ans=" << ans << endl;
            }
            // else cout << "found-old-place:" << newx + 1 << " " << newy + 1 << endl;
            newx += dx[d];
            newy += dy[d];
            if (newx < 0 || newy < 0 || newx >= n || newy >= m){
                newx -= dx[d];
                newy -= dy[d];
                d = (d + 1) % 4;
                // cout << "out-of-range-Error\n";
                continue;
            }
            if (a[newx][newy] == 'x'){
                newx -= dx[d];
                newy -= dy[d];
                d = (d + 1) % 4;
                // cout << "Are-x-Error\n";
                continue;
            }
            if (!v[newx][newy]){
                v[newx][newy] = 1;
                ans++;
                // cout << "found-new-place:" << newx + 1 << " " << newy + 1 << "    ans=" << ans << endl;
            }
            // else cout << "found-old-place:" << newx + 1 << " " << newy + 1 << endl;
        }
        // cout << "ans=";
        cout << ans << endl;
    }
    return 0;
}
