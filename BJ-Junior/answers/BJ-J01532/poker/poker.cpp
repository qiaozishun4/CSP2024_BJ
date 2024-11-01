#include<iostream>
using namespace std;
int s[10][105] = { };
int n,ans = 52,j;
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(b >= '2' && b <= '9')
            j = b-'0';
        else if(b == 'A')
            j = 1;
        else if(b == 'T')
            j = 10;
        else if(b == 'J')
            j = 11;
        else if(b == 'Q')
            j = 12;
        else if(b == 'K')
            j = 13;
        if(a == 'D'){
            if(s[0][j] == 0){
                s[0][j] = 1;
                ans -= 1;
            }
        }
        else if(a == 'C'){
            if(s[1][j] == 0){
                s[1][j] = 1;
                ans -= 1;
            }
        }
        else if(a == 'H'){
            if(s[2][j] == 0){
                s[2][j] = 1;
                ans -= 1;
            }
        }
        else if(a == 'S'){
            if(s[3][j] == 0){
                s[3][j] = 1;
                ans -= 1;
            }
        }
    }
    cout << ans;
    return 0;
}
