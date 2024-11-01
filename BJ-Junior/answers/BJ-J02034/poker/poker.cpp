#include <bits/stdc++.h>
using namespace std;
int x[5][20],ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char a,b;
        scanf(" %c %c",&a,&b);
        int c;
        if(b>='2'&&b<='9')c=b-'0';
        if(b=='A')c=1;
        if(b=='T')c=10;
        if(b=='J')c=11;
        if(b=='Q')c=12;
        if(b=='K')c=13;
        if(a=='C')x[1][c]++;
        if(a=='D')x[2][c]++;
        if(a=='H')x[3][c]++;
        if(a=='S')x[4][c]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(x[i][j]==0)ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
