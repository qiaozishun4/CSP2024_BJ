#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int hs;
        int ds;
        if(s[0]=='D')hs=1;
        else if(s[0]=='C')hs=2;
        else if(s[0]=='H')hs=3;
        else if(s[0]=='S')hs=4;
        if(s[1]=='A')ds=1;
        else if(s[1]=='T')ds=10;
        else if(s[1]=='J')ds=11;
        else if(s[1]=='Q')ds=12;
        else if(s[1]=='K')ds=13;
        else ds=s[1]-'0';
        a[hs][ds]++;
    }
    int sum=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j])sum--;
        }
    }
    if(sum<0)sum=0;
    cout<<sum;
    return 0;
}
