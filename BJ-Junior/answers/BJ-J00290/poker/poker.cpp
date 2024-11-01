#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 55;
int n, ans;
char a[N][3];
bool b[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf(" %d",&n);
    for(int i = 1; i <= n; i++){
        scanf(" %s",&a[i]);
        int hua, num;
        if(a[i][0] == 'D') hua = 1;
        else if(a[i][0] == 'C') hua = 2;
        else if(a[i][0] == 'H') hua = 3;
        else if(a[i][0] == 'S') hua = 4;
        if(a[i][1] == 'A') num = 1;
        else if(a[i][1] >= '1' && a[i][1] <= '9') num = (int)a[i][1] - 48;
        else if(a[i][1] == 'T') num = 10;
        else if(a[i][1] == 'J') num = 11;
        else if(a[i][1] == 'Q') num = 12;
        else if(a[i][1] == 'K')num = 13;
        b[hua][num] = true;
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(b[i][j]) ans++;
        }
    }
    printf("%d\n",52-ans);

    return 0;
}
