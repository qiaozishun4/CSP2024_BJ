#include <bits/stdc++.h>
using namespace std;
int a[10][100]={0},cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        getchar();
        char k,num;
        cin>>k>>num;
        int k2,num2;
        if(k=='D') k2=1;
        else if(k=='C') k2=2;
        else if(k=='H') k2=3;
        else if(k=='S') k2=4;
        if(num=='A') num2=1;
        else if(num=='T') num2=10;
        else if(num=='J') num2=11;
        else if(num=='Q') num2=12;
        else if(num=='K') num2=13;
        else num2=num-'0';
        a[k2][num2]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}