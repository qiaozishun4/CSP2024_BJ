#include<bits/stdc++.h>
using namespace std;

int t , n , m , k , x , y , d;
string s[1010];

int main(){
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    scanf("%d" , &t);
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d" , &n , &m , & k);
        scanf("%d%d%d" , &x , &y , &d);
        for(int j = 1; j <= n; j++){
            cin >> s[j];
        }
        if(n == 1 && m <= 2 && k == 1){
            cout << 1 << endl;
        }
        else{
            if(k == 1){
                if(d == 0){
                    if(y + 1 <= m && s[x][y + 1] == '.'){
                        cout << 2 << endl;
                    }
                    else{
                        cout << 1 << endl;
                    }
                }
                if(d == 1){
                    if(x + 1 <= n && s[x + 1][y] == '.'){
                        cout << 2 << endl;
                    }
                    else{
                        cout << 1 << endl;
                    }
                }
                if(d == 2){
                    if(y - 1 >= 1 && s[x][y - 1] == '.'){
                        cout << 2 << endl;
                    }
                    else{
                        cout << 1 << endl;
                    }
                }
                if(d == 3){
                    if(x - 1 >= 1 && s[x - 1][y] == '.'){
                        cout << 2 << endl;
                    }
                    else{
                        cout << 1 << endl;
                    }
                }
            }
        }
    }
    return 0;
}
