#include<bits/stdc++.h>
using namespace std;
int n;
int a[5][14];
int cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        int k;
        cin>>s;
        if(s[1]=='T')k=10;
        else if(s[1]=='J')k=11;
        else if(s[1]=='Q')k=12;
        else if(s[1]=='K')k=13;
        else if(s[1]=='A')k=1;
        else k=s[1]-'0';

        if(s[0]=='D'){
            a[1][k]=1;
        }
        else if(s[0]=='C'){
            a[2][k]=1;
        }
        else if(s[0]=='H'){
            a[3][k]=1;
        }
        else if(s[0]=='S')a[4][k]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]!=1)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
