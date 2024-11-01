#include<bits/stdc++.h>

using namespace std;

int n, cnt = 52;
string s;
char a, b;
map<char,int> mp;
bool D[20], C[20], H[20], S[20];

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    mp['A'] = 1, mp['T'] = 10, mp['J'] = 11, mp['Q'] = 12, mp['K'] = 13;

    cin >> n;
    while (n--){
        cin >> s;
        a = s[0], b = s[1];

        int t;
        if ('0' < b && b <= '9') t = b - '0';
        else t = mp[b];

        if (a == 'D'){
            if (!D[t]){
                D[t] = true;
                cnt --;
            }
        }
        if (a == 'C'){
            if (!C[t]){
                C[t] = true;
                cnt --;
            }
        }
        if (a == 'H'){
            if (!H[t]){
                H[t] = true;
                cnt --;
            }
        }
        if (a == 'S'){
            if (!S[t]){
                S[t] = true;
                cnt --;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
