#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int n;
string s;
int x,y;
int cards[4][13];
int needed;
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        if(s[0]=='D') {
            x=0;
        } else if(s[0]=='C') {
            x=1;
        } else if(s[0]=='H') {
            x=2;
        } else if(s[0]=='S') {
            x=3;
        }
        if(s[1]=='A') {
            y=1;
        } else if(s[1]>='2' && s[1]<='9'){
            y=s[1]-'0';
        } else if(s[1]=='T') {
            y=10;
        } else if(s[1]=='J') {
            y=11;
        } else if(s[1]=='Q') {
            y=12;
        } else if(s[1]=='K') {
            y=0;
        }
        cards[x][y]=1;
    }
    for(int i=0;i<4;i++) {
        for(int j=0;j<13;j++) {
            needed+=(1-cards[i][j]);
        }
    }
    cout<<needed<<endl;
    return 0;
}
