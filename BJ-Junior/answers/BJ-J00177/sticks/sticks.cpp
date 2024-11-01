#include <iostream>
#include <cstdio>
using namespace std;

int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void print8(int n)
{
    for(int i = 1; i <= n; i++) cout << 8;
    cout << endl;
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int m = n / 7;
        int k = n % 7;
        if(k == 0){
            print8(m);
        }else if(k == 1){
            if(m == 0){
                cout << -1 << endl;
            }else{
                cout << 10;
                print8(m-1);
            }
        }else if(k == 2){
            cout << 1;
            print8(m);
        }else if(k == 3){
            if(m == 0) cout << 7 << endl;
            else{
                cout << 23;
                print8(m-1);
            }
        }else if(k == 4){
            if(m == 0) cout << 4 << endl;
            else{
                cout << 20;
                print8(m-1);
            }
        }else if(k == 5){
            if(m == 0) cout << 2 << endl;
            else{
                cout << 28;
                print8(m-1);
            }
        }else if(k == 6){
            if(m == 0) cout << 6 << endl;
            else{
                cout << 80;
                print8(m-1);
            }
        }
        else cout << -1 << endl;
    }
    return 0;
}
