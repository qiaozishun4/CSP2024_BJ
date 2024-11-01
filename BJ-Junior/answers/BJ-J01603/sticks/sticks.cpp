#include<iostream>
using namespace std;
int t, n;
void special(int k) {
    if (k == 1)
        cout << -1 << endl;
    else if (k == 2)
        cout << 1 << endl;
    else if (k == 3)
        cout << 7 << endl;
    else if (k == 4)
        cout << 4 << endl;
    else if (k == 5)
        cout << 2 << endl;
    else if (k == 6)
        cout << 6 << endl;
    else
        cout << 8 << endl;
    return ;
}
void normal(int k) {
    int ws = k/7;
    if (k % 7 == 0) {
        for (int i = 0; i < ws; i++)
            cout << 8;
    }
    else if (k % 7 == 1) {
        cout << 10;
        for (int i = 1; i < ws; i++)
            cout << 8;
    }
    else if (k % 7 == 2) {
        cout << 1;
        for (int i = 0; i < ws; i++)
            cout << 8;
    }
    else if (k % 7 == 3) {
        if (k == 10){
            cout << 22;
            for (int i = 1; i < ws; i++)
                cout << 8;
        }
        else {
            cout << 200;
            for (int i = 2; i < ws; i++)
                out << 8;
        }
    }
    else if (k % 7 == 4) {
        cout << 20;
        for (int i = 1; i < ws; i++)
            cout << 8;
    }
    else if (k % 7 == 5) {
        cout << 2;
        for (int i = 0; i < ws; i++)
            cout << 8;
    }
    else {
        cout << 6;
        for (int i = 0; i < ws; i++)
            cout << 8;
    }
    cout << endl;
    return ;

}
int main() {
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 7)
            special(n);
        else
            normal(n);
    }
    return 0;
}
