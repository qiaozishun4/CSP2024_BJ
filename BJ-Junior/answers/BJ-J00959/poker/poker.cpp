#include <bits/stdc++.h>
using namespace std;

string inp;
bool pokers[5][20];
int ans = 0;

void myfunc(string s){
    int color, num;

    if (s[0] == 'D') color = 0;
    else if (s[0] == 'C') color = 1;
    else if (s[0] == 'H') color = 2;
    else if (s[0] == 'S') color = 3;

    if (s[1] == 'A') num = 1;
    else if (s[1] == '2') num = 2;
    else if (s[1] == '3') num = 3;
    else if (s[1] == '4') num = 4;
    else if (s[1] == '5') num = 5;
    else if (s[1] == '6') num = 6;
    else if (s[1] == '7') num = 7;
    else if (s[1] == '8') num = 8;
    else if (s[1] == '9') num = 9;
    else if (s[1] == 'T') num = 10;
    else if (s[1] == 'J') num = 11;
    else if (s[1] == 'Q') num = 12;
    else if (s[1] == 'K') num = 13;

    pokers[color][num] = 1;

}

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inp;
        myfunc(inp);
    }
    for(int i = 0; i <= 3; i++){
        for(int j = 1; j <= 13; j++){
            if (pokers[i][j] == 0)
                ans++;
        }
    }
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
