#include <bits/stdc++.h>
using namespace std;
int n, ans=52;
bool pk[5][14];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        char x=s[0], y=s[1];
        if(x=='D'){
            if(y>='2' and y<='9'){
                int z=y-'0';
                if(!pk[1][z]){
                    pk[1][z]=1;
                    ans--;
                }
            }else if(y=='T'){
                int z=10;
                if(!pk[1][z]){
                    pk[1][z]=1;
                    ans--;
                }
            }else if(y=='J'){
                int z=11;
                if(!pk[1][z]){
                    pk[1][z]=1;
                    ans--;
                }
            }else if(y=='Q'){
                int z=12;
                if(!pk[1][z]){
                    pk[1][z]=1;
                    ans--;
                }
            }else if(y=='K'){
                int z=13;
                if(!pk[1][z]){
                    pk[1][z]=1;
                    ans--;
                }
            }else if(y=='A'){
                int z=1;
                if(!pk[1][z]){
                    pk[1][z]=1;
                    ans--;
                }
            }
        }else if(x=='C'){
            if(y>='2' and y<='9'){
                int z=y-'0';
                if(!pk[2][z]){
                    pk[2][z]=1;
                    ans--;
                }
            }else if(y=='T'){
                int z=10;
                if(!pk[2][z]){
                    pk[2][z]=1;
                    ans--;
                }
            }else if(y=='J'){
                int z=11;
                if(!pk[2][z]){
                    pk[2][z]=1;
                    ans--;
                }
            }else if(y=='Q'){
                int z=12;
                if(!pk[2][z]){
                    pk[2][z]=1;
                    ans--;
                }
            }else if(y=='K'){
                int z=13;
                if(!pk[2][z]){
                    pk[2][z]=1;
                    ans--;
                }
            }else if(y=='A'){
                int z=1;
                if(!pk[2][z]){
                    pk[2][z]=1;
                    ans--;
                }
            }
        }else if(x=='H'){
            if(y>='2' and y<='9'){
                int z=y-'0';
                if(!pk[3][z]){
                    pk[3][z]=1;
                    ans--;
                }
            }else if(y=='T'){
                int z=10;
                if(!pk[3][z]){
                    pk[3][z]=1;
                    ans--;
                }
            }else if(y=='J'){
                int z=11;
                if(!pk[3][z]){
                    pk[3][z]=1;
                    ans--;
                }
            }else if(y=='Q'){
                int z=12;
                if(!pk[3][z]){
                    pk[3][z]=1;
                    ans--;
                }
            }else if(y=='K'){
                int z=13;
                if(!pk[3][z]){
                    pk[3][z]=1;
                    ans--;
                }
            }else if(y=='A'){
                int z=1;
                if(!pk[3][z]){
                    pk[3][z]=1;
                    ans--;
                }
            }
        }else if(x=='S'){
            if(y>='2' and y<='9'){
                int z=y-'0';
                if(!pk[4][z]){
                    pk[4][z]=1;
                    ans--;
                }
            }else if(y=='T'){
                int z=10;
                if(!pk[4][z]){
                    pk[4][z]=1;
                    ans--;
                }
            }else if(y=='J'){
                int z=11;
                if(!pk[4][z]){
                    pk[4][z]=1;
                    ans--;
                }
            }else if(y=='Q'){
                int z=12;
                if(!pk[4][z]){
                    pk[4][z]=1;
                    ans--;
                }
            }else if(y=='K'){
                int z=13;
                if(!pk[4][z]){
                    pk[4][z]=1;
                    ans--;
                }
            }else if(y=='A'){
                int z=1;
                if(!pk[4][z]){
                    pk[4][z]=1;
                    ans--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
