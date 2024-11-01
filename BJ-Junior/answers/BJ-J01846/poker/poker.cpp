#include<bits/stdc++.h>
#define ll long long

using namespace std;

//TO NAME
string p;
int n, D[15], C[15], H[15], S[15];

int main(){

    //TO DO
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--){
        cin >> p;
        if(p[0] == 'D'){
            if(p[1] == 'A') D[1]++;
            else if(p[1] == 'T') D[10]++;
            else if(p[1] == 'J') D[11]++;
            else if(p[1] == 'Q') D[12]++;
            else if(p[1] == 'K') D[13]++;
            else D[p[1] - '0']++;
        }
        if(p[0] == 'C'){
            if(p[1] == 'A') C[1]++;
            else if(p[1] == 'T') C[10]++;
            else if(p[1] == 'J') C[11]++;
            else if(p[1] == 'Q') C[12]++;
            else if(p[1] == 'K') C[13]++;
            else C[p[1] - '0']++;
        }
        if(p[0] == 'H'){
            if(p[1] == 'A') H[1]++;
            else if(p[1] == 'T') H[10]++;
            else if(p[1] == 'J') H[11]++;
            else if(p[1] == 'Q') H[12]++;
            else if(p[1] == 'K') H[13]++;
            else H[p[1] - '0']++;
        }
        if(p[0] == 'S'){
            if(p[1] == 'A') S[1]++;
            else if(p[1] == 'T') S[10]++;
            else if(p[1] == 'J') S[11]++;
            else if(p[1] == 'Q') S[12]++;
            else if(p[1] == 'K') S[13]++;
            else S[p[1] - '0']++;
        }
    }
    int ans = 0;
    for(int i = 1;i <= 13;i++){
        if(D[i] == 0){
            ans++;
        }
        if(C[i] == 0){
            ans++;
        }
        if(H[i] == 0){
            ans++;
        }
        if(S[i] == 0){
            ans++;
        }
    }
    printf("%d", ans);

    return 0;
}
