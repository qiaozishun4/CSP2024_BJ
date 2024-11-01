#include<bits/stdc++.h>
using namespace std;
map<char,int> huase,dianshu;
bool a[35][15];
inline void init() {
    huase['D']=1;
    huase['C']=2;
    huase['H']=3;
    huase['S']=4;
    dianshu['A']=1;
    dianshu['2']=2;
    dianshu['3']=3;
    dianshu['4']=4;
    dianshu['5']=5;
    dianshu['6']=6;
    dianshu['7']=7;
    dianshu['8']=8;
    dianshu['9']=9;
    dianshu['T']=10;
    dianshu['J']=11;
    dianshu['Q']=12;
    dianshu['K']=13;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        char x,y;
        cin>>x>>y;
        a[huase[x]][dianshu[y]]=1;
    }
    int cnt=0;
    for (int i=1;i<=4;i++) {
        for (int j=1;j<=13;j++) {
            if (!a[i][j]) {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
