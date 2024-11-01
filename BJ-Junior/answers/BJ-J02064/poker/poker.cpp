#include<bits/stdc++.h>
using namespace std;

int a[53][5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 0; i <= n-1; i++){
        string t;
        cin>>t;
        char x = t[1],y = t[0];
        int y1;
        int x1;
        if(y == 'D'){
            y1 = 1;
        }
        else if(y == 'C'){
            y1 = 2;
        }
        else if(y == 'H'){
            y1 = 3;
        }
        else if(y == 'S'){
            y1 = 4;
        }
        if(x >= '1' && x <= '9'){
            x1 = x-'0';
        }
        else if(x == 'T'){
            x1 = 10;
        }
        else if(x == 'J'){
            x1 = 11;
        }
        else if(x == 'Q'){
            x1 = 12;
        }
        else if(x == 'K'){
            x1 = 13;
        }
        else if(x == 'A'){
            x1 = 1;
        }
        a[x1][y1]++;
    }
    int ans = 0;
    for(int i = 1; i <= 13; i++){
        for(int j = 1; j <= 4; j++){
            if(a[i][j] == 0){
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
