#include <bits/stdc++.h>
using namespace std;
int T,n,a[10] = {6,2,5,5,4,5,6,3,7,6},tong,ls;
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n %7 == 0){//mod7=0
            for(int i = 1; i <=n/7 ;i ++) {
                cout << "8";//all 8
            }
            cout << endl;
        }else if (n%7 == 1) {
            int ls = n/7-1;
            cout << "10";//add
            for(int i = 1; i <= ls ; i ++) {
                cout << "8" ;
            }
            cout << endl;
        }else if (n < 2) {
            cout << "-1" << endl;
        }else{
            for(int i = 1; i >=1; i ++) {//which number can add =n
                tong = 0;
                ls= i;
                while(ls > 0) {
                    tong += a[ls % 10];
                    ls/=10;
                }
                if(tong == n){
                    cout<< i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
