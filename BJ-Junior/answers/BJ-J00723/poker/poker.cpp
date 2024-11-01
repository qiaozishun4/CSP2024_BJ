#include <cstdio>
#include <iostream>

using namespace std;

bool f[255][255];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
       // cout << s[0] << " " << s[1] << endl;
        if(f[s[0]][s[1]] == false) {
            f[s[0]][s[1]] = true;
            sum++;
        }
    }
    printf("%d", 52 - sum);
    return 0;
}
