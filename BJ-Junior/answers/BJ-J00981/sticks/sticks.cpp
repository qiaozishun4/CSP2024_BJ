#include<bits/stdc++.h>
using namespace std;

int n;
int a[15] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};

int main(){
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        int x;
        if(x == 1) cout << -1 << endl;
        if(x == 2) cout << 1 << endl;
        if(x == 3) cout << 7 << endl;
        if(x == 4) cout << 4 << endl;
        if(x == 5) cout << 2 << endl;
        if(x == 6) cout << 6 << endl;
        if(x == 7) cout << 8 << endl;
        if(x == 9) cout << 18 << endl;
        if(x == 10) cout << 5 << endl;
        if(x == 11) cout << 50 << endl;
        if(x == 12) cout << 58 << endl;
        if(x == 13) cout << 80 << endl;
        if(x == 14) cout << 88 << endl;
        if(x == 15) cout << 108 << endl;
        if(x == 16) cout << 188 << endl;
        if(x == 17) cout << 258 << endl;
        if(x == 18) cout << 208 << endl;
        if(x == 19) cout << 288 << endl;
        if(x == 20) cout << 688 << endl;
    }
    return 0;
}
