#include <iostream>
using namespace std;
#define ll long long
ll cc = 52, q;
bool tong[62];
string str;
int main(){
    freopen("pocker.in", "r", stdin);
    freopen("pocker.out", "w", stdout);
    cin >> q;
    while(q --;){
        ll tmp = 0;
        ll t = 0;
        cin >> str;
        if(str[0] == 'D'){
            tmp = 1;
        }
        if(str[0] == 'C'){
            tmp = 14;
        }
        if(str[0] == 'H'){
            tmp = 27;
        }
        if(str[0] == 'S'){
            tmp = 40;
        }
        if(str[1] == 'A'){
            t = 0;
        }
        if(str[1] == '2'){
            t = 1;
        }
        if(str[1] == '3'){
            t = 2;
        }
        if(str[1] == '4'){
            t = 3;
        }
        if(str[1] == '5'){
            t = 4;
        }
        if(str[1] == '6'){
            t = 5;
        }
        if(str[1] == '7'){
            t = 6;
        }
        if(str[1] == '8'){
            t = 7;
        }
        if(str[1] == '9'){
            t = 8;
        }
        if(str[1] == 'T'){
            t = 9;
        }
        if(str[1] == 'J'){
            t = 10;
        }
        if(str[1] == 'Q'){
            t = 11;
        }
        if(str[1] == 'K'){
            t = 12;
        }
        if(tong[t + tmp]){
            continue;
        }
        tong[t + tmp] = true;
        cc --;
    }
    cout << cc;
    return 0;
}
