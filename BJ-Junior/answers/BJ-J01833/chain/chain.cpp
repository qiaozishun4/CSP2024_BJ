#include <iostream>
#include <vector>
using namespace std;
int l[200005];
struct Node{
    vector<int> a, b;
} a[200005];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while (T --){
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i ++){
            cin >> l[i];
            for (int j = 0; j < l[i]; j ++){
                int t;
                cin >> t;
                a[i].a.push_back(t);
                if (t == 1) a[i].b.push_back(j);
            }
        }
        while (q --){
            int r, c;
            cin >> r >> c;
            if (r == 1){
                bool flag = 1;
                for (int i = 1; i <= n; i ++){
                    for (int j = 0; j < a[i].b.size(); j ++){
                        for (int m = a[i].b[j] + 1; m < l[i]; m ++)
                            if (a[i].a[m] == c && m - a[i].b[j] + 1 <= k){
                                cout << 1 << endl;
                                flag = 0;
                                break;
                            }
                        if (flag == 0)
                            break;
                    }
                    if (flag == 0)
                        break;
                }
                if (flag == 1)
                    cout << 0 << endl;
            } else cout << 0 << endl;
        }
    }
    return 0;
}
