#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int num[] = {1, 5, 2, 2, 3, 2, 1, 4, 0, 1};
//int num[] = {6,2,5,5,4,5,6,3,7,6};
string cost[6] = {"8", "069", "235", "4", "7", "1"};
string number;
bool dfs(int l, int w, int nw){
    if (l < 0) return false;

    if (nw == w){
        if (l >= 0 && l <= 5){
            if (nw == 1 && l == 1){
                number += '6';
            }else{
                number += cost[l][0];
            }
            return true;
        }else{
            return false;
        }
    }
    else{
        for (int i = 0; i <= 9; i++){
            if (nw == 1 && i == 0) continue;
            if (dfs(l-num[i], w, nw+1)){
                number += i+'0';
                return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        number = "";
        int w = (n%7==0 ? n/7 : n/7+1);
        int l = (7*w-n);
        if (dfs(l, w, 1)){
            for (int i = number.size()-1; i >= 0; i--) cout << number[i];
            cout << endl;
        }
        else cout << -1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
