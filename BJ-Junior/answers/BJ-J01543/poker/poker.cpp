#include <bits/stdc++.h>
using namespace std;
int s[100][100];
char a,b;
int ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D'){
            if('2'<=b<='9')
                s[1][b-'0']++;
            if(b=='A')
                s[1][1]++;
            if(b=='T')
                s[1][10]++;
            if(b=='J')
                s[1][11]++;
            if(b=='Q')
                s[1][12]++;
            if(b=='K')
                s[1][13]++;
        }
        if(a=='C'){
            if('2'<=b<='9')
                s[2][b-'0']++;
            if(b=='A')
                s[2][1]++;
            if(b=='T')
                s[2][10]++;
            if(b=='J')
                s[2][11]++;
            if(b=='Q')
                s[2][12]++;
            if(b=='K')
                s[2][13]++;
        }
        if(a=='H'){
            if('2'<=b<='9')
                s[3][b-'0']++;
            if(b=='A')
                s[3][1]++;
            if(b=='T')
                s[3][10]++;
            if(b=='J')
                s[3][11]++;
            if(b=='Q')
                s[3][12]++;
            if(b=='K')
                s[3][13]++;
        }
        if(a=='S'){
            if('2'<=b<='9')
                s[4][b-'0']++;
            if(b=='A')
                s[4][1]++;
            if(b=='T')
                s[4][10]++;
            if(b=='J')
                s[4][11]++;
            if(b=='Q')
                s[4][12]++;
            if(b=='K')
                s[4][13]++;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(s[i][j]>0)
                ans++;
        }
    }
    cout<<52-ans;
    return 0;
}
