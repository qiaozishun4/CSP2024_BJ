#include<bits/stdc++.h>
using namespace std;

const int maxn=101;
int n,a[maxn][maxn],cnt=0;
char s[maxn];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int x,y;
        if(s[0]=='D') x=1;
        else if(s[0]=='C') x=2;
        else if(s[0]=='H') x=3;
        else x=4;

        if(s[1]=='A') y=1;
        else if(s[1]>='2' && s[1]<='9') y=s[1]-48;
        else if(s[1]=='T') y=10;
        else if(s[1]=='J') y=11;
        else if(s[1]=='Q') y=12;
        else y=13;
        if(!a[x][y]){
            a[x][y]=1;
            cnt++;
        }
    }
    printf("%d\n",52-cnt);
    return 0;
}