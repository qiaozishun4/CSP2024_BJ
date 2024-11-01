#include <bits/stdc++.h>
using namespace std;

int p[30][30];

int main(){
   freopen("poker.in", "r", stdin);
   freopen("poker.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char a,b;
        cin >> a >>b;
        if(b - 'A' < 0 || b - 'A' > 25){
            p[a - 'A'][b - '1']++;
        }
        else{
            p[a - 'A'][b - 'A']++;
        }
    }
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 30; j++){
            if(p[i][j] > 0){
                ans++;
            }
        }
    }
    cout << 52 - ans;
    return 0;
}
