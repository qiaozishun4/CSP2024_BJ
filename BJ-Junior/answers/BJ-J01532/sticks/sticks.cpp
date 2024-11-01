#include <iostream>
using namespace std;
int n[10] = {6,2,5,5,4,5,6,3,7,6};
int z,ans;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        ans = 0;
        cin >> z;
        if(z < 2)
            cout << -1 << endl;
        else if(z == 2)
            cout << 1 << endl;
        else if(z == 3)
            cout << 7 << endl;
        else if(z == 4)
            cout << 4 << endl;
        else if(z == 6)
            cout << 0 << endl;
        else if(z == 10)
            cout << 22 << endl;
        else if(z % 7 == 0){
            ans = z/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
        else if(z % 7 == 1){
            cout << 10;
            ans = (z-8)/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
        else if(z % 7 == 2){
            cout << 1;
            ans = (z-2)/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
        else if(z % 7 == 3){
            cout << 200;
            ans = (z-17)/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
        else if(z % 7 == 4){
            cout << 20;
            ans = (z-11)/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
        else if(z % 7 == 5){
            cout << 2;
            ans = (z-5)/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
        else if(z % 7 == 6){
            cout << 6;
            ans = (z-6)/7;
            while(ans--)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
