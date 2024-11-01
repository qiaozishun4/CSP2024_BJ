#include <iostream>
#include <cstdio>
using namespace std;
int data[5][15];
int getkind(char in) {
    if(in=='D')return 0;
    if(in=='C')return 1;
    if(in=='H')return 2;
    if(in=='S')return 3;
}
int getnum(char in) {
    if(in=='A')return 1;
    if(in=='T')return 10;
    if(in=='J')return 11;
    if(in=='Q')return 12;
    if(in=='K')return 13;
    else return in-'0';
}
void notehave() {
    string in;
    cin>>in;
    data[getkind(in[0])][getnum(in[1])]=1;
}
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int num=0;
    for(int i=0;i<n;i++) notehave();
    for(int i=0;i<=3;i++) {
        for(int j=1;j<=13;j++) {
            if(data[i][j]==0) num++;
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
