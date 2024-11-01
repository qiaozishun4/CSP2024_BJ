#include <bits/stdc++.h>
using namespace std;
int n,a[4][13];
char s2[13]="A23456789TJQK";
char s1[4]="DCHS";
int change1(char c){
    for(int i=0;i<4;i++){
        if(s1[i]==c) return i;
    }
}
int change2(char c){
    for(int i=0;i<13;i++){
        if(s2[i]==c) return i;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char h,s;
        scanf(" %c%c ",&h,&s);
        a[change1(h)][change2(s)]=1;
    }
    int cnt=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(m[i][j]==0) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
