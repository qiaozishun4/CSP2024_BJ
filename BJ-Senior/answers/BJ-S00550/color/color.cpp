#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    for (int t=0; t<T; ++t){
        int n, same=0, sum=0;
        cin >> n;
        for (int i=0; i<n; ++i){
            cin >> a[i];
            sum+=a[i];
            for (int j=0; j<i; ++j)
                same+=a[i]==a[j];
        }
        if (same == 0) cout << 0 << endl;
        else if (same == 1){
            bool unfinnish=1;
            for (int i=0; i<n && unfinnish; ++i)
                for (int j=0; j<i && unfinnish; ++j)
            if (a[i] == a[j]){
                unfinnish = 0;
                cout << a[i] << endl;
            }
        }else cout << sum/3 << endl;
    }
    return 0;
}
