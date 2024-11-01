#include <bits/stdc++.h>
#include <string>
using namespace std;
int n, ans = 0, title;
int cards[4][13];
string c;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> c;
        // 先判断一下花色
        if (c[0] == 'D') title = 0;
        else if (c[0] == 'C') title = 1;
        else if (c[0] == 'H') title = 2;
        else if (c[0] == 'S') title = 3;
        // 再判断一下数字
        if (c[1] == 'A') cards[title][0]++;
        else if (c[1] == '2') cards[title][1]++;
        else if (c[1] == '3') cards[title][2]++;
        else if (c[1] == '4') cards[title][3]++;
        else if (c[1] == '5') cards[title][4]++;
        else if (c[1] == '6') cards[title][5]++;
        else if (c[1] == '7') cards[title][6]++;
        else if (c[1] == '8') cards[title][7]++;
        else if (c[1] == '9') cards[title][8]++;
        else if (c[1] == 'T') cards[title][9]++;
        else if (c[1] == 'J') cards[title][10]++;
        else if (c[1] == 'Q') cards[title][11]++;
        else if (c[1] == 'K') cards[title][12]++;
    }
    for (int i = 0;i <= 3;i++){
        for (int j = 0;j <= 12;j++){
            //cout << cards[i][j] << endl;
            if (cards[i][j] == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}