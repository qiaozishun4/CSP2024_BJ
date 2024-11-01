#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int w[] = {6,2,5,5,4,5,6,3,7,6},ans[] = {-1,-1,1,7,4,2,6,8,10,18,40,20,28,68,88,108,188,200,208,288,688};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        bool flag = 0;
        if (n <= 7) cout << ans[n];
        else if (n % 7 == 0){
            int num = n / 7;
            for (int i = 1; i <= num ; i++){
                cout << "8";
            }
        }
        else if (n % 7 == 1){
            int num = 0;
            while(n > 8){
                num++;
                n -= 7;
            }
            cout << "10";
            for (int i = 1 ;i <= num ; i++){
                cout << "8";
            }
        }
        else{
            int ans1,ans2,ans3,minn = 1e9;
            for (int i = 1 ; i <= 9 ; i++){
                int num = n - w[i];
                int e_num = num % 6;
                int z_num = max(0,(num - e_num * 7) / 6);
                if ((w[i]+ e_num * 7 + z_num * 6) == n){
                    flag = 1;
                    if (1 + e_num + z_num < minn) {
                        ans1 = i, ans2 = z_num, ans3 = e_num;
                        minn = 1 + e_num + z_num;
                    }
                }
            }
            if (flag){
                cout << ans1;
                for (int i = 1 ; i <= ans2; i++) cout << "0";
                for (int i = 1 ; i <= ans3 ; i++) cout << "8";
            }
            if (!flag) cout << -1;
        }
        cout << endl;
    }
    return 0;
}
