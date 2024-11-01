#include <bits/stdc++.h>

using namespace std;

int ans = 0, n, num[100001];
bool x[100];

void help(int t){
    if (t == n + 1){
        int l = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i - 1; j >= 1; j--)
                if (x[j] == x[i])
                    if (num[i] == num[j]){
                        l += num[i];
                        break;
                    }
                    else
                        break;
        }
        ans = max(ans, l);
        return;
    }
    x[t] = true;
    help(t + 1);
    x[t] = false;
    help(t + 1);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> num[i];
        help(0);
        cout << ans << endl;
    }
    return 0;
}