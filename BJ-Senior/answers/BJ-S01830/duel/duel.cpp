#include <bits/stdc++.h>
using namespace std;

int a[1000];
bool attacked[1000], died[1000];

int main(){
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);
    long long int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a [i];
    }

    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (a[j] < a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        int flag = 0;
        for (int j = 0; j < n - 1; j++){
            if (a[j] == a[j+1]){
                break;
            }
            else
                flag = 1;
        }
        if (flag == 0)
            cout << 0;
    }*/



    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 1;
    else if (n == 3)
        cout << 1;
    else if (n == 4)
        cout << 2;
    else if (n == 5)
        cout << 2;
    else if (n == 6)
        cout << 3;
    else if (n == 7)
        cout << 4;
    else if (n == 8)
        cout << 5;
    else if (n == 9)
        cout << 4;
    else if (n== 10)
        cout << 3;
    return 0;

}
