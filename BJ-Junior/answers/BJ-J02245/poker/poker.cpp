#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
string s;
int n,a[10][20],ans = 0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        cin>>s;
        int t = 0;
        if(s[1] == 'A') t = 1;
        else if(s[1] == 'T') t = 10;
        else if(s[1] == 'J') t = 11;
        else if(s[1] == 'Q') t = 12;
        else if(s[1] == 'K') t = 13;
        else t = s[1] - '0';
        if(s[0] == 'D') ++a[1][t];
        else if(s[0] == 'C') ++a[2][t];
        else if(s[0] == 'H') ++a[3][t];
        else if(s[0] == 'S') ++a[4][t];
    }
    for(int i = 1;i <= 4;++i){
        for(int j = 1;j <= 13;++j){
            if(a[i][j] == 0) ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}
