#include<iostream>
using namespace std;
#define ll long long
ll t;
ll n;
ll a[8] = {-1,-1,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n;
        if (n <= 7){
            cout << a[n] << endl;
        }
        else{
            if (n % 7 == 0){//A
                n /= 7;
            }
            else if (n%7 == 1){//B
                n /= 7;
                cout << 12;
                n--;
            }
            else if (n % 7 == 2){
                n/= 7;
                n--;
                cout << 18;
            }
            else if (n % 7 == 3){
                n /= 7;
                n--;
                cout << 22;
            }
            else if (n % 7 == 4){
                n /= 7;
                n--;
                cout << 20;
            }
            else if (n%7 == 5){
                n /= 7;
                n--;
                cout << 28;
            }
            else if (n%7 == 6){
                n /= 7;
                n--;
                cout << 80;
            }
            for (int i = 1;i <= n;i++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
//不要保龄，球球了
