#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long a[5][14]={};
    long long n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int b1;
        if(s[1]=='A') b1=1;
        else if(s[1]=='T') b1=10;
        else if(s[1]=='J') b1=11;
        else if(s[1]=='Q') b1=12;
        else if(s[1]=='K') b1=13;
        else b1=s[1]-'0';
        if(s[0]=='D') a[1][b1]=1;
        else if(s[0]=='C') a[2][b1]=1;
        else if(s[0]=='H') a[3][b1]=1;
        else a[4][b1]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}