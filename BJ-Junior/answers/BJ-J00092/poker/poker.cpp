#include <bits/stdc++.h>
using namespace std;
int n,cnt;
char c,b;
char a[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>c>>b;
        if(c == 'D'){
            if(b == 'A')
                a[0][0]++;
            else if(b == 'T')
                a[0][9]++;
            else if(b == 'J')
                a[0][10]++;
            else if(b == 'Q')
                a[0][11]++;
            else if(b == 'K')
                a[0][12]++;
            else
                a[0][(b - '0')]++;
        }if(c == 'C'){
            if(b == 'A')
                a[1][0]++;
            else if(b == 'T')
                a[1][9]++;
            else if(b == 'J')
                a[1][10]++;
            else if(b == 'Q')
                a[1][11]++;
            else if(b == 'K')
                a[1][12]++;
            else
                a[1][(b - '0')]++;
        }if(c == 'H'){
            if(b == 'A')
                a[2][0]++;
            else if(b == 'T')
                a[2][9]++;
            else if(b == 'J')
                a[2][10]++;
            else if(b == 'Q')
                a[2][11]++;
            else if(b == 'K')
                a[2][12]++;
            else
                a[2][(b - '0')]++;
        }if(c == 'S'){
            if(b == 'A')
                a[3][0]++;
            else if(b == 'T')
                a[3][9]++;
            else if(b == 'J')
                a[3][10]++;
            else if(b == 'Q')
                a[3][11]++;
            else if(b == 'K')
                a[3][12]++;
            else
                a[3][(b - '0')]++;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            if(a[i][j] == 0)
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
