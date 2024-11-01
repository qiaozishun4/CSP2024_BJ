#include <iostream>
using namespace std;

bool a[53];

int main(){
    if(freopen("poker.in", "r", stdin) == NULL) return 1;
    if(freopen("poker.out", "w", stdout) == NULL) return 1;

    for(int i = 1; i <= 52; i++) a[i] = 0;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        char c, num; cin >> c >> num;
        int t;
        switch(c){
            case 'D':{
                t = 13 * 0;
                break;
            }
            case 'C':{
                t = 13 * 1;
                break;
            }
            case 'H':{
                t = 13 * 2;
                break;
            }
            case 'S':{
                t = 13 * 3;
                break;
            }
        }
        if(num == 'A') t += 1;
        else if(num == 'T') t += 10;
        else if(num == 'J') t += 11;
        else if(num == 'Q') t += 12;
        else if(num == 'K') t += 13;
        else t += (num - '0');
        a[t] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= 52; i++){
        if(!a[i]){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
