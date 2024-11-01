#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 55;
const int maxcol = 5;
bool vis[maxcol][maxn];
char ch[2];
int trans1(char a){
    if(a == 'D') return 1;
    if(a == 'C') return 2;
    if(a == 'H') return 3;
    if(a == 'S') return 4;
}
int trans2(char s){
    if(s >= '2' && s <= '9') return s-'0';
    if(s == 'A') return 1;
    if(s == 'T') return 10;
    if(s == 'J') return 11;
    if(s == 'Q') return 12;
    if(s == 'K') return 13;
}
int ans = 0;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    memset(vis, false, sizeof(vis));
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s", ch);
        if(vis[trans1(ch[0])][trans2(ch[1])] == false){
            ans++;
            vis[trans1(ch[0])][trans2(ch[1])] = true;
        }
    }
    printf("%d", 52-ans);
    return 0;
}