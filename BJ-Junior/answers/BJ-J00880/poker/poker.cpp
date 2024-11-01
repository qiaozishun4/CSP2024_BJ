#include<bits/stdc++.h>
using namespace std;
int n,a[10][20],type,num,cnt;//4zhonghuase 13zhongpai
char s[3];
int judge(char a){
    if(a=='C')return 1;
    if(a=='D')return 2;
    if(a=='H')return 3;
    return 4;
}
int judge2(char a){
    if(a=='A')return 1;
    if(a == 'T')return 10;
    if(a=='J')return 11;
    if(a=='K')return 13;
    if(a=='Q')return 12;
    return a-'0';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",&s);//CDHS
        type = judge(s[0]);
        num = judge2(s[1]);
        a[type][num] = 1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j])cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
