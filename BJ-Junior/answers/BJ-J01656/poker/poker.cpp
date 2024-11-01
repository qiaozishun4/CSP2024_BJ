#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=52;
bool c[60];
int ct(char b){
    if(b=='A')return 1;
    if(b=='2')return 2;
    if(b=='3')return 3;
    if(b=='4')return 4;
    if(b=='5')return 5;
    if(b=='6')return 6;
    if(b=='7')return 7;
    if(b=='8')return 8;
    if(b=='9')return 9;
    if(b=='T')return 10;
    if(b=='J')return 11;
    if(b=='Q')return 12;
    if(b=='K')return 13;
}
void pd(char a,char b){
    if(a=='D'){
        c[ct(b)]=true;
    }else if(a=='C'){
        c[ct(b)+13]=true;
    }else if(a=='H'){
        c[ct(b)+26]=true;
    }else if(a=='S'){
        c[ct(b)+39]=true;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        pd(a,b);
    }
    for(int i=1;i<=52;i++){
        if(c[i])cnt--;
    }
    cout<<cnt<<endl;
    return 0;
}
