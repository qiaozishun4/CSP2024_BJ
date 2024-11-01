#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int a,b[4][13]={0},ans=0;
    cin >> a;
    const int a1=a;
    string c[a1]={};
    for(int i=0;i<a1;i++){
        cin >> c[i];
        int d,e;
        switch(c[i][0]){
        case 'D':
            d=0;
            break;
        case 'C':
            d=1;
            break;
        case 'H';
            d=2;
            break;
        case 'S':
            d=3;
            break;
        }
        switch(c[i][1]){
        case 'A':
            e=0;
            break;
        case 'T':
            e=9;
            break;
        case 'J':
            e=10;
            break;
        case 'Q':
            e=11;
            break;
        case 'K':
            e=12;
            break;
        default:
            e=c[i][1]-'1';
        }
        if(b[d][e]==0){
            ans++;
        }
        b[d][e]=1;
    }
    cout << 52-ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
