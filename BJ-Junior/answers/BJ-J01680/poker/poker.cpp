#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string poker[n+1];
    string a;
    int x = 0;
    for (int i = 0; i < n; i++){
        cin >> a;
        if(i > 0){
            if (poker[x-1] != a){
                poker[x] = a;
                x++;
            }
        }
        if (x == 0) {
            poker[x] = a;
            x ++;
        }
    }
    cout << 52-x;
    fclose(stdin);
    fclose(stdout);

    return 0;
}