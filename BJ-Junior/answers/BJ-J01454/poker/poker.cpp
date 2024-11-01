#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 52 + 10;
string s[maxn];
int f[maxn];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        if(s[i][0] == 'D'){
            f[i] = 1000 + s[i][1];
        } else if(s[i][0] == 'C'){
            f[i] = 2000 + s[i][1];
        } else if(s[i][0] == 'S'){
            f[i] = 3000 + s[i][1];
        } else{
            f[i] = 4000 + s[i][1];
        }
    }
    sort(f + 1, f + n + 1);
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(f[i] == f[i + 1]){
            int j;
            for(j = i + 1; j <= n; j++){
                if(f[i] == f[j]) cnt++;
                else break;
            }
            i = j;
        }
    }
    int ans = 52 - n + cnt;
    cout << ans;
    return 0;
}
