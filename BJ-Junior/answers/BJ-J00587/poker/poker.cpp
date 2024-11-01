#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bool b[10][20];
int check(char c){
    switch(c){
        case 'D':case 'A':return 1;
        case 'C':return 2;
        case 'H':return 3;
        case 'S':return 4;
        case 'T':return 10;
        case 'J':return 11;
        case 'Q':return 12;
        case 'K':return 13;
        default:return c-'0';

    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int t1=check(s[0]),t2=check(s[1]);
        if(!b[t1][t2]){
            b[t1][t2]=true;
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}
