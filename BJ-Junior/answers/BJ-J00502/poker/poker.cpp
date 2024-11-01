#include <iostream>
using namespace std;

int n;
int a[20][20];
char b,c;
int b1,c1;
int ans;

int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> c >> b;
        if(b == 'A')b1 = 1;
        if(b == '2')b1 = 2;
        if(b == '3')b1 = 3;
        if(b == '4')b1 = 4;
        if(b == '5')b1 = 5;
        if(b == '6')b1 = 6;
        if(b == '7')b1 = 7;
        if(b == '8')b1 = 8;
        if(b == '9')b1 = 9;
        if(b == 'T')b1 = 10;
        if(b == 'J')b1 = 11;
        if(b == 'Q')b1 = 12;
        if(b == 'K')b1 = 13;
        if(c == 'D')c1 = 1;
        if(c == 'C')c1 = 2;
        if(c == 'H')c1 = 3;
        if(c == 'S')c1 = 4;
        a[b1][c1]++;
    }
    for(int i = 1;i <= 13;i++){
        for(int j = 1;j <= 4;j++){
            if(a[i][j] == 0)ans++;
        }
    }
    cout << ans;
    return 0;
}
