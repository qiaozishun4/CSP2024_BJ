#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int a[100009] = {};
        memset(a,0,sizeof(a));
        int minn = 1e8, maxn = -1;
        for(int i = 1; i <= x; i++){
            int y;
            cin >> y;
            a[y]++;
            if(y > maxn) maxn = y;
            if(y < minn) minn = y;
        }
        int ans = 0;
        for(int i = minn; i <= maxn; i++){
            if(a[i] >= 2){
                ans += i * (a[i] / 2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
