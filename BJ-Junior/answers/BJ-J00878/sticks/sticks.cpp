#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T --){
        int num;
        cin >> num;
        if(num % 7 == 0) for(int i = 0;i < (num / 7);i ++) cout << 8;
        else if(num < 2) cout << -1;
        else if(num < 7){
            if(num == 2) cout << 1;
            else if(num == 3) cout << 7;
            else if(num == 4) cout << 4;
            else if(num == 5) cout << 2;
            else if(num == 6) cout << 6;
        }else if(num % 7 == 1){
            cout << 10;
            for(int i = 0;i < ((num - 8) / 7);i ++) cout << 8;
        }else if(num % 7 == 2){
            cout << 1;
            for(int i = 0;i < ((num - 2) / 7);i ++) cout << 8;
        }else if(num % 7 == 3){
            cout << 22;
            for(int i = 0;i < ((num - 10) / 7);i ++) cout << 8;
        }else if(num % 7 == 4){
            cout << 20;
            for(int i = 0;i < ((num - 11) / 7);i ++) cout << 8;
        }else if(num % 7 == 5){
            cout << 2;
            for(int i = 0;i < ((num - 5) / 7);i ++) cout << 8;
        }else if(num % 7 == 6){
            cout << 6;
            for(int i = 0;i < ((num - 6) / 7);i ++) cout << 8;
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
