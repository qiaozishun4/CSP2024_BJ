#include<bits/stdc++.h>
using namespace std;
char s[100][2];
int vis[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= 52;i++) vis[i] = 0;
    for(int i = 1;i <= n;i++){
        cin >> s[i][0] >> s[i][1];
        int num1 = 0,num2;
        if(s[i][0] == 'C') num1 = 13;
        if(s[i][0] == 'H') num1 = 26;
        if(s[i][0] == 'S') num1 = 39;

        if(s[i][1] == 'A') num2 = 1;
        else if(s[i][1] == 'T') num2 = 10;
        else if(s[i][1] == 'J') num2 = 11;
        else if(s[i][1] == 'Q') num2 = 12;
        else if(s[i][1] == 'K') num2 = 13;
        else num2 = s[i][1] - '0';
        vis[num1 + num2] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= 52;i++) if(!vis[i]) ans++;
    cout << ans;
    return 0;
}
