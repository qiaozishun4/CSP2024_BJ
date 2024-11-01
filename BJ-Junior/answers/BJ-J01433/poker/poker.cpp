#include <bits/stdc++.h>
using namespace std;
int cnt[20][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int ans = 0;
    int n;
    cin >> n;
    while (n--){
        string nn;
        cin >> nn;


        char a = nn[0];
        char b = nn[1];

        int k;
        if (b >= 'A' and b <= 'Z'){
            if (b == 'A'){
                k = 1;
            }
            if (b == 'T'){
                k = 10;
            }
            if (b == 'J'){
                k = 11;
            }
            if (b == 'Q'){
                k = 12;
            }
            if (b == 'K'){
                k = 13;
            }
        }
        else{
            k = b-'0';
        }
        int j;
        if (a == 'D'){
            j = 1;
        }
        if (a == 'C'){
            j = 2;
        }
        if (a == 'H'){
            j = 3;
        }
        if (a == 'S'){
            j = 4;
        }
        cnt[j][k] ++;
    }
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 13; j++){
            if (cnt[i][j]){
                ans++;
            }
        }
    }
    cout << 52-ans;
    return 0;
}

