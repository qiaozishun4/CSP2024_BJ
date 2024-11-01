#include <iostream>
#include <cstdio>
using namespace std;

int need[] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
const int N = 2e4 + 10;
string f[110] , base[N];
void mn(string &s , string t){
    if (s.size() > t.size())s = t;
    else if (s.size() == t.size() && s > t)s = t;
}
string ans(int x){
    if (x == 1)return "-1";
    string ans = base[20000];
    int pre = x / 7 , lst = x % 7;
    for (int i = 1; i <= 5; i++){
        if (lst != 1)mn(ans , f[lst] + base[pre]);
        if (pre == 0)break;
        pre--;
        lst += 7;
    }
    return ans;
}
int main(){
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    base[0] = "";
    for (int i = 1; i <= 2e4; i++)base[i] = base[i-1] + "8";
    for (int i = 1; i <= 100; i++)f[i] = base[20];
    f[1] = "-1";
    for (int i = 1; i < 10; i++){
        string ttt = "";
        ttt += char(i + 48);
        mn(f[need[i]] , ttt);
    }
    for(int i = 2; i <= 100; i++)
        for(int j = 0; j < 10; j++)
            if(i - need[j] > 1)
                mn(f[i] , f[i-need[j]] + char(j + 48));
    int T;
    cin >> T;
    while (T--){
        int x;
        cin >> x;
        cout << ans(x) << '\n';
    }
    return 0;
}
//10.42