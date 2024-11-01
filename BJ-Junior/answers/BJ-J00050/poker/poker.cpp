#include<bits/stdc++.h>
using namespace std;
char a[53];
char b[53];
char d[53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",&a[i]);
    }
    int c=0;
    for(int i=1;i<=n;i++){
        d[i]=a[i];
        for(int j=i+1;j<=n;j++){
        if(a[j]==d[i]) b[j]="x";
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]=="x") c++;
    }
    int s=52-n+c;
    printf("%d",&s);
    return 0;
}