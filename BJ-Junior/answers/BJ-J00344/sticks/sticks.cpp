#include<bits/stdc++.h>
using namespace std;
int a[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long n, ans = 0, sss = 10000, xxx = 10000, uuu = 10000, yyy = 10000;
long long s;
int main(){
    cin >> n;
    for(int i = 1; i <= 100; i++){
        cin >> s;

        if(s < 2){
            cout << "-1"  << endl;
            continue;
        }
        else if(s == 2){
            cout << 1 << endl;
            continue;
        }
        else if(s == 5){
            cout << 2  << endl;
            continue;
        }
        else if(s == 5){
            cout << 3 << endl;
            continue;
        }
        else if(s == 4){
            cout << 4 << endl;
            continue;
        }
        else if(s == 5){
            cout << 5 << endl;
            continue;
        }
        else if(s == 6){
            cout << 6 << endl;
            continue;
        }
        else if(s == 3){
            cout << 7 << endl;
            continue;
        }
        else if(s == 7){
            cout << 8 << endl;
            continue;
        }
        else if(s == 6){
            cout << 9 << endl;
            continue;
        }
        else if(s > 7 && s < 1000){
            for(int i = 1; i <= 9; i++){
                for(int j = 0; j <= 9; j++){
                        for(int k =  1; k <= 9; k++){
                    if(a[i] + a[j] + a[k] == s && a[i] < a[j] && a[j] < a[k]){
                        if(sss > i && xxx > j && uuu > k && a[i] != a[j] && a[j] != a[k] && a[k] != a[i]){
                            sss = i;
                            xxx = j;
                            uuu = k;
                        }
                        }

                        }

                }
            }
        cout << sss << xxx << uuu;
        break;
        }
        else if(s > 999 && s < 10000){
            for(int i = 1; i <= 9; i++){
                for(int j = 0; j <= 9; j++){
                        for(int k =  0; k <= 9; k++){
                                for(int p = 0; p <= 9; p++){
                    if(a[i] + a[j] + a[k] + a[p] == s && a[i] < a[j] && a[j] < a[k] && a[k] < a[p]){
                        if(sss > i && xxx > j && uuu > k && a[i] != a[j] && a[j] != a[k] && a[k] != a[p] && a[p] != a[i]){
                            sss = i;
                            xxx = j;
                            uuu = k;
                            yyy = p;
                        }
                        }
                                }
                        }

                }
            }
        cout << sss << xxx << uuu << yyy;
        break;
        }
        cout << ans << endl;
    }

    return 0;
}
