#include<bits/stdc++.h>
using namespace std;
int n, sum = 0;
int d[15];
int c[15];
int h[15];
int s[15];

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        string x;
        cin >> x;
        if(x[0] == 'D'){
            if(x[1] == 'A'){
                d[1]++;

            }
            else if(x[1] == 'T'){
                d[10]++;

            }
            else if(x[1] == 'J'){
                d[11]++;

            }
            else if(x[1] == 'Q'){
                d[12]++;

            }
            else if(x[1] == 'K'){
                d[13]++;

            }else{
                d[x[1] - '0']++;
            }
        }
        if(x[0] == 'C'){
            if(x[1] == 'A'){
                c[1]++;

            }
            else if(x[1] == 'T'){
                c[10]++;

            }
            else if(x[1] == 'J'){
                c[11]++;

            }
            else if(x[1] == 'Q'){
                c[12]++;

            }
            else if(x[1] == 'K'){
                c[13]++;

            }else{
                c[x[1] - '0']++;
            }
        }
        if(x[0] == 'H'){
            if(x[1] == 'A'){
                h[1]++;

            }
            else if(x[1] == 'T'){
                h[10]++;

            }
            else if(x[1] == 'J'){
                h[11]++;

            }
            else if(x[1] == 'Q'){
                h[12]++;

            }
            else if(x[1] == 'K'){
                h[13]++;

            }else{
                h[x[1] - '0']++;
            }
        }
        if(x[0] == 'S'){
            if(x[1] == 'A'){
                s[1]++;

            }
            else if(x[1] == 'T'){
                s[10]++;

            }
            else if(x[1] == 'J'){
                s[11]++;

            }
            else if(x[1] == 'Q'){
                s[12]++;

            }
            else if(x[1] == 'K'){
                s[13]++;

            }else{
                s[x[1] - '0']++;
            }
        }
    }
    for(int i = 1; i <= 13; i++){
        if(d[i] == 0){
            sum++;
        }
        if(c[i] == 0){
            sum++;
        }
        if(h[i] == 0){
            sum++;
        }
        if(s[i] == 0){
            sum++;
        }
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
