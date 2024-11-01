#include <iostream>
#include <stdio.h>
using namespace std;

bool v[4][13];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int ans = 0;
    cin >> n;
    char a,b;
    while (n--){
        cin >> a >> b;
        int x,y;
        switch(a){
            case 'D':
                x = 1;
                break;
            case 'C':
                x = 2;
                break;
            case 'H':
                x = 3;
                break;
            case 'S':
                x = 0;
                break;
        }
        switch(b){
            case 'A':
                y = 0;
                break;
            case 'T':
                y = 9;
                break;
            case 'J':
                y = 10;
                break;
            case 'Q':
                y = 11;
                break;
            case 'K':
                y = 12;
                break;
            default:
                y = b - 1;
        }
        if (!v[x][y]){
            ans++;
            v[x][y] = 1;
        }
    }
    cout << 52 - ans;
    return 0;
}
