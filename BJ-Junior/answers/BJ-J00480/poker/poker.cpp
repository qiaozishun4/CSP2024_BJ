#include<bits/stdc++.h>//long long
using namespace std;
int a[100][100];
int hua(char c){
    if(c=='D'){
        return 1;
    }
    if(c=='C'){
        return 2;
    }
    if(c=='H'){
        return 3;
    }
    if(c=='S'){
        return 4;
    }
    return 0;
    //dchs
}
int pai(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }
    if(c=='A'){
        return 1;
    }
    if(c=='T'){
        return 10;
    }
    if(c=='J'){
        return 11;
    }
    if(c=='Q'){
        return 12;
    }
    if(c=='K'){
        return 13;
    }
    return 0;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char c1,c2;
    while(n--){
        cin>>c1>>c2;
        int tmp1=hua(c1);
        int tmp2=pai(c2);
        a[tmp1][tmp2]=1;
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0)cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
