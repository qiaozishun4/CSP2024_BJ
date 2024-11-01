#include<bits/stdc++.h>
using namespace std;
int n,a[5][14],cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        int p=5,l=0;
        cin>>s;
        if(s[0]=='D')p=0;
        if(s[0]=='C')p=1;
        if(s[0]=='H')p=2;
        if(s[0]=='S')p=3;


        if(s[1]=='A')l=1;
        if(s[1]=='2')l=2;
        if(s[1]=='3')l=3;
        if(s[1]=='4')l=4;
        if(s[1]=='5')l=5;
        if(s[1]=='6')l=6;
        if(s[1]=='7')l=7;
        if(s[1]=='8')l=8;
        if(s[1]=='9')l=9;
        if(s[1]=='T')l=10;
        if(s[1]=='J')l=11;
        if(s[1]=='Q')l=12;
        if(s[1]=='K')l=13;

        a[p][l]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
