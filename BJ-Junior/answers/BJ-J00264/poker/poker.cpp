#include<bits/stdc++.h>
using namespace std;
bool a[5][15];
int n,c;
string b;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        cin >> b;
        int q=0,p=0;
        if(b[0]=='D')q=1;
        else if(b[0]=='C')q=2;
        else if(b[0]=='H')q=3;
        else if(b[0]=='S')q=4;
        if('2'<=b[1] &&b[1]<='9')p=b[1]-'0';
        else if(b[1]=='A')p=1;
        else if(b[1]=='T')p=10;
        else if(b[1]=='J')p=11;
        else if(b[1]=='Q')p=12;
        else if(b[1]=='K')p=13;
        a[q][p]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j])c++;
        }
    }
    printf("%d", c);
}
