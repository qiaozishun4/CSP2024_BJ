include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            cout << -1 << endl;
            continue;
        }else if(x == 3){
            cout << 7 << endl;
            continue;
        }else if(x == 4){
            cout << 4 << endl;
            continue;
        }else if(x == 5){
            cout << 2 << endl;
            continue;
        }else if(x == 6){
            cout << 6 << endl;
            continue;
        }
        int a = x%7;
        int b = x/7+1;
        if(a == 0){
            b--;
        }
        const int o = b;
        int m[o];
        for(int i = 0;i < b;i++){
            m[i] = 8;
        }
        if(a == 1){
            m[0] = 1;
            m[1] = 0;
        }else if(a == 2){
            m[0] = 1;
        }else if(a == 3){
            m[0] = 2;
            m[1] = 2;
        }else if(a == 4){
            m[0] = 2;
            m[1] = 0;
        }else if(a == 5){
            m[0] = 2;
            m[1] = 8;
        }else if(a == 6){
            m[0] = 6;
            m[1] = 8;
        }
        for(int i = 0;i< b;i++){
            cout <<m[i];
        }
        cout << endl;
    }
    return 0;
}