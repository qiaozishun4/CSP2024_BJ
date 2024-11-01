#include<bits/stdc++.h>
using namespace std;
int cnt[15] = {6,2,5,5,4,5,6,3,7,6},tmp[10] = {0,0,1,7,4,2,6,8},n;
//17420(6)8
//23456   7
/*
1.全填8
2：看余数
=0/2/5/6:不调整
=1：-1/1088……
=3：7/22/20088……
=4：4/2088……
*/
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int tmp2 = n % 7;
        if(tmp2 == 0){
            while(n > 0){
                cout << 8;
                n -= 7;
            }
        }else if(tmp2 == 2 || tmp2 == 5 || tmp2 == 6){
            cout << tmp[tmp2];
            n -= tmp2;
            while(n > 0){
                cout << 8;
                n -= 7;
            }
        }else if(tmp2 == 1){
            if(n == 1){
                cout << -1;
            }else{
                cout << 10;
                n -= 8;
                while(n > 0){
                    cout << 8;
                    n -= 7;
                }
            }
        }else if(tmp2 == 3){
            if(n == 3){
                cout << 7;
            }else if(n == 10){
                cout << 22;
            }else{
                cout << 200;
                n -= 17;
                while(n > 0){
                    cout << 8;
                    n -= 7;
                }
            }
        }else{
            if(n == 4){
                cout << 4;
            }else{
                cout << 20;
                n -= 11;
                while(n > 0){
                    n -= 7;
                    cout << 8;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
