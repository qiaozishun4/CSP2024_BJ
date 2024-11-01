#include <bits/stdc++.h>
using namespace std;
string ans1[15]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
string ans2[7]={"888","108","188","200","208","288","688"};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string ans;
        if (n <= 14) ans = ans1[n];
        else if (n <= 20) ans = ans2[n-14];
        else if (n == 21) ans = "888";
        else {
            ans = ans2[n % 7];
            for (int i = 21;i <= n;i += 7){
                ans += "8";
            }
        }
        cout << ans << endl;
    }
}