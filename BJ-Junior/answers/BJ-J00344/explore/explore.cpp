#include<bits/stdc++.h>
using namespace std;
int a[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long n, ans = 0;
long long s;
int main(){
    cin >> n;
    for(int i = 1; i <= 100; i++){
        cin >> s;

        if(s < 2){
            cout << "-1"  << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 0 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 1 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 2  << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 3 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 4 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 5 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 6 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 7 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 8 << endl;
            continue;
        }
        else if(s == a[i]){
            cout << 9 << endl;
            continue;
        }
        else if(s > 7 && s < 100){
            for(int i = 1; i <= s; i++){
                for(int j = 1; j <= s; j++){
                    if(a[i] + a[j] == s && a[i] < a[j]){
                        cout << a[i] << a[j] << endl;
                        break;
                    }

                }
            }

        }
        cout << ans << endl;
    }

    return 0;
}
