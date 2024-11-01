#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n , m , l , v , a[N] , b[N] , c[N] , d[N] , tmp;
vector <pair <int , int> > e , g;
bool cmp(pair <int , int> x , pair <int , int> y){
    return x.second < y.second;
}
int main(){
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        e.clear();
        g.clear();
        cin >> n >> m >> l >> v;
        for (int i = 1;i <= n;i++){
            cin >> a[i] >> c[i] >> b[i];
        }
        for (int i = 1;i <= m;i++){
            cin >> d[i];
        }
        for (int i = 1;i <= n;i++){
            if (b[i] == 0){
                if (c[i] > v) e.push_back({a[i] , l});
            }
            else if (b[i] > 0){
                if (c[i] <= v){
                    tmp = (v - c[i]) * (c[i] + v) / (2 * b[i]) + 1 + a[i];
                    if (tmp <= l) e.push_back({tmp , l});
                }
                else e.push_back({a[i] , l});
            }
            else{
                if (c[i] > v){
                    b[i] = -b[i];
                    tmp = ((c[i] - v) * (c[i] + v) - 1) / (2 * b[i]) + a[i];
                    e.push_back({a[i] , min(tmp , l)});
                }
            }
        }
        int x , y;
        for (pair <int , int> z : e){
            x = lower_bound(d + 1 , d + m + 1 , z.first) - d , y = upper_bound(d + 1 , d + m + 1 , z.second) - d - 1;
            if (x <= y) g.push_back({x , y});
        }
        cout << g.size() << ' ';
        sort(g.begin() , g.end() , cmp);
        int last = 0 , ans = 0;
        for (pair <int , int> x : g){
            if (last < x.first){
                last = x.second;
                ++ans;
            }
        }
        cout << m - ans << '\n';
    }
    return 0;
}