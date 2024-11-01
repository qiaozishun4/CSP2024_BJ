#include<bits/stdc++.h>
using namespace std;
long long n, f[10][110], c, d, o;
char a, b;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a>>b;
        if(a == 'D'){
            c = 1;
        }else if(a == 'C'){
            c = 2;
        }else if(a == 'H'){
            c = 3;
        }else{
            c = 4;
        }
        if(b == 'A'){
            d = 1;
        }else if(b == '2'){
            d = 2;
        }else if(b == '3'){
            d = 3;
        }else if(b == '4'){
            d = 4;
        }else if(b == '5'){
            d = 5;
        }else if(b == '6'){
            d = 6;
        }else if(b == '7'){
            d = 7;
        }else if(b == '8'){
            d = 8;
        }else if(b == '9'){
            d = 9;
        }else if(b == 'T'){
            d = 10;
        }else if(b == 'J'){
            d = 11;
        }else if(b == 'Q'){
            d = 12;
        }else{
            d = 13;
        }
        if(f[c][d] == 0){
            o++;
            f[c][d] = 1;
        }
    }
    cout<<52 - o;
    return 0;
}
