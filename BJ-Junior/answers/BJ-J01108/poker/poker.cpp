#include <iostream>
#include <cstring>
using namespace std;

bool exists[5][14]; //D=1, C=2, H=3, S=4; A 2 3 4 5 6 7 8 9 T J Q K
int n, cnt;
string s;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        int a = 0, b = 0;
        if (s[0] == 'D') a = 1;
        if (s[0] == 'C') a = 2;
        if (s[0] == 'H') a = 3;
        if (s[0] == 'S') a = 4;
        if (s[1] >= '2' && s[1] <= '9') b = int(s[1]-'0');
        else{
            if (s[1] == 'A') b = 1;
            if (s[1] == 'T') b = 10;
            if (s[1] == 'J') b = 11;
            if (s[1] == 'Q') b = 12;
            if (s[1] == 'K') b = 13;
        }
        if (!exists[a][b]){
            cnt++;
            exists[a][b] = 1;
        }
    }
    cout << 52-cnt << "\n";
    return 0;
}
