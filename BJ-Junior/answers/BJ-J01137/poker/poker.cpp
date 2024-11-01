#include <bits/stdc++.h>
using namespace std;

bool a[10][20];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin >> n;
    string s;
    int i, j;
    while(n--){
        cin >> s;
        i = (s[0] == 'D' ? 1 : (s[0] == 'C' ? 2 : (s[0] == 'H' ? 3 : (s[0] == 'S' ? 4 : 0))));
        j = (s[1] == 'A' ? 1 : (s[1] == 'T' ? 10 : (s[1] == 'J' ? 11 : (s[1] == 'Q' ? 12 : (s[1] == 'K' ? 13 : (s[1] - '0'))))));
        a[i][j] = true;
        // cout << i << " " << j << endl;
    }
    int cnt = 52;
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 13;j++){
            cnt -= a[i][j];
        }
    }
    cout << cnt;
    return 0;
}
