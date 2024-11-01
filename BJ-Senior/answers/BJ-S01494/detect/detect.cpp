#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int qv(int d, int v, int a, int t){
    return v + a * t;
}
struct Node {
    bool b1,b2;
};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n,m,l,v;
        scanf("%d%d%d%d",&n,&m,&l,&v);
        queue <int> q1;// ->
        queue <int> q2;// <-
        int ans1 = 0;
        for(int j = 1; j <= n; j++){
            int d,v,a;
            cin >> d >> v >> a;
            if(a == 0 && v > l){
                q1.push(v);
                ans1++;
                continue;
            }
        }
        Node p[N];
        int maxn = -1,minn = 1e6;
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            p[x].b1 = 1;
            p[x].b2 = 1;
            if(x >= maxn) maxn = x;
            if(x <= minn) minn= x;
        }
        int num = q1.size();
        int ans2 = 0;
        while(!q1.empty()){
            int x = q1.front();
            q1.pop();
            for(int j = x; j <= maxn ; j++){
                if(p[j].b1 && p[j].b2){
                    p[j].b2 = 0;
                    break;
                }
            }
        }
        for(int j = minn; j <= maxn; j++){
            if(p[j].b1 && p[j].b2) ans2++;
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
