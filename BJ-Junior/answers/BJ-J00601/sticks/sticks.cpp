#include<bits/stdc++.h>
using namespace std;
int T,n;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        if(n <= 1){ cout << -1 <<endl;}
        if(n == 3){ cout << 7 <<endl; }
        if(n == 4) {cout << 4 <<endl; }
        if(n % 7 == 0){
            int cnt = n / 7;
            for(int i = 1; i <= cnt; i ++) cout << 8;
        }
        else if(n % 7 == 1 &&n > 1){
            int cnt = n /7 - 1;
            cout << 10;
            for(int i = 1; i <= cnt; i ++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 2){
            int cnt = n/7;
            cout << 1;
            for(int i = 1; i <= cnt; i ++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 3 && n >3){
            int cnt = n / 7;
            cout << 22;
            for(int i = 1; i <= cnt; i ++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 4 && n >4){
            int cnt = n / 7 - 1;
            cout << 20;
            for(int i = 1; i <= cnt;i ++) cout << 8;
            cout <<endl;
        }
        else if(n % 7 == 5){
            int cnt = n / 7;
            cout <<2;
            for(int i = 1; i <= cnt;i ++) cout <<8;
            cout << endl;
        }
        else if(n % 7 == 6){
            int cnt = n / 7;
            cout << 6;
            for(int i = 1; i <= cnt; i ++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}
