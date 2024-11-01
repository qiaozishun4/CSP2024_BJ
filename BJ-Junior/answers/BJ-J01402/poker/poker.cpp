#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long LL;
const LL maxn = 55;
LL n,ans;
bool pock[maxn][maxn];
LL num(char x){
    if(x == 'A')
        return 1;
    else if(x == 'T')
        return 10;
    else if(x == 'J')
        return 11;
    else if(x == 'Q')
        return 12;
    else if(x == 'K')
        return 13;
    else
        return x - '0';
}
LL col(char x){
    if(x == 'D')
        return 1;
    else if(x == 'C')
        return 2;
    else if(x == 'H')
        return 3;
    else if(x == 'S')
        return 4;
}
int main(){
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    cin >> n;
    for(LL i = 1; i <= n; i++){
        string pok;
        cin >> pok;
        pock[col(pok[0])][num(pok[1])] = true;
    }
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 13; j++)
            if(!pock[i][j])
                ans++;
    cout << ans;
    return 0;
}
