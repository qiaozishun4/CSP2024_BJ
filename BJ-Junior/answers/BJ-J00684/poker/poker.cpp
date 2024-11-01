#include<iostream>
using namespace std;
bool p[4][13]={};
int n;
int r(char c) {
    if(c=='D') return 0;
    if(c=='C') return 1;
    if(c=='H') return 2;
    if(c=='S') return 3;
    if(c=='A') return 0;
    if(c=='T') return 9;
    if(c=='J') return 10;
    if(c=='Q') return 11;
    if(c=='k') return 12;
    return c-'1';
}
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) {
        char c1,c2;
        cin>>c1>>c2;
        p[r(c1)][r(c2)]=true;
    }
    int cnt=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<13;j++) {
            if(!p[i][j]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
