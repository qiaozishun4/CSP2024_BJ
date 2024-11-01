#include<bits/stdc++.h>
using namespace std;
int t, n, k, q;
string S[100007];

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    int l, ch, r;
    while(t--){
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++){
            cin >> l;
            for(int j = 1; j <= l; j++){
                cin >> ch;
                S[i] += char(ch+'0');
            }
        }
        while(q--){
            cin >> r >> ch;
            char c = char(ch+'0');
            //string cc = c;
            //cout << cc << endl;
            int pos = 0, flag = 0;
            for(int i = 1; i <= n; i++){
                pos = 0;
                while(S[i].find("1", pos) != string::npos){
                        pos = S[i].find("1", pos) + 1;
                    if(S[i].find(c, pos) != string::npos && S[i].find(c, pos) - pos + 2 <= k){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            cout << flag << endl;
        }
    }
    return 0;
}
