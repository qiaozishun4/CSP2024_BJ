#include<bits/stdc++.h>
using namespace std;

int vis[256][20];
//int t[256];
char t2[5] = {'D', 'C', 'H', 'S'};

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);  
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        char c1, c2; int x;
        cin >> c1 >> c2;
        if(c2 == 'T') x = 10;
        else if(c2 == 'J') x = 11;
        else if(c2 == 'Q') x = 12;
        else if(c2 == 'K') x = 13;
        else if(c2 == 'A') x = 1;
        else x = c2-'0';

        vis[c1][x] = 1;
    }   
    int ans = 0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(vis[t2[i]][j] == 0){
                ans ++;
            }
        }
    }      
    cout << ans;    
    return 0;
}