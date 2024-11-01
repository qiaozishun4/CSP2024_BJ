#include<bits/stdc++.h>
using namespace std;
int a[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,m;
    char t1,t2;
    scanf("%d\n",&n);m=n;
    for(int i=1;i<=n;i++){
        scanf("%c%c\n",&t1,&t2);
        if(t1=='H') t1=1;
        else if(t1=='S') t1=2;
        else if(t1=='D') t1=3;
        else t1=4;
        if(t2=='A') t2=1;
        else if(t2=='T') t2=10;
        else if(t2=='J') t2=11;
        else if(t2=='Q') t2=12;
        else if(t2=='K') t2=13;
        else t2-='0';
        a[t1][t2]++;
        if(a[t1][t2]>1) m--;
    }
    printf("%d",52-m);
    return 0;
}

