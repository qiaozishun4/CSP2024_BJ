// D 代表方片,字符 C 代表草花,字符 H 代表红桃,字符 S 代表黑桃,
// 这样每张牌可以通过一个长度为 2 的字符串表示,其中第一个字
// 符表示这张牌的花色,第二个字符表示这张牌的点数,例如 CA 表示草花 A,ST 表示黑
// 桃 T(黑桃 10)。
#include<bits/stdc++.h>

using namespace std;

int cnt[15], n, ans;
char hs, ds;
bool flag[15][6];

int trans(char ch){
    if(ch == 'A') return 1;
    if(ch == 'T') return 10;
    if(ch == 'J') return 11;
    if(ch == 'Q') return 12;
    if(ch == 'K') return 13;
    return ch - '0';
}

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--){
       cin >> hs >> ds;
       int d = trans(ds);
       switch(hs){
            case 'D':
                if(!flag[d][1])
                    flag[d][1] = true,
                    ans++; // valid pokers nums + 1
                break;
            case 'C':
                if(!flag[d][2])
                    flag[d][2] = true,
                    ans++; // valid pokers nums + 1
                break;
            case 'H':
                if(!flag[d][3])
                    flag[d][3] = true,
                    ans++; // valid pokers nums + 1
                break;
            case 'S':
                if(!flag[d][4])
                    flag[d][4] = true,
                    ans++; // valid pokers nums + 1
                break;
       }
    }
    cout << 52 - ans;
    return 0;
}
