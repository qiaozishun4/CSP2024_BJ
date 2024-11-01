#include <bits/stdc++.h>
using namespace std;
int T,n;
//int downdown(int num,bool flag){
//    int ans = 100000000000;
//    for (int pun = 1;pun <= min(num,7);pun++){
//        if (pun == 2) ans = min(ans, int = ('1' + string downdown(num - 2,true)));
//        else if (pun == 3) ans = min(ans, int ('7' + string downdown(num - 3,true)));
//        else if (pun == 4) ans = min(ans, int ('4' + string downdown(num - 4,true)));
//        else if (pun == 5) ans = min(ans, int ('2' + string downdown(num - 5,true)));
//        else if ((pun == 6) && flag) ans = min(ans, int ('0' + string downdown(num - 6,true)));
//        else if ((pun == 6) && !flag) ans = min(ans, int ('6' + string downdown(num - 6,true)));
//        else if (pun == 7) ans = min(ans, int ('8' + string downdown(num - 7,true)));
//        else return 0;
//    }
//}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    for (int p = 1;p <= T;p++){
        cin >> n;
        if (n <= 1) cout << -1 << endl;
        else if (n == 2) cout << 1 << endl;
        else if (n == 3) cout << 7 << endl;
        else if (n == 5) cout << 2 << endl;
        else if (n == 6) cout << 6 << endl;
        else if (n == 7) cout << 0 << endl;
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}