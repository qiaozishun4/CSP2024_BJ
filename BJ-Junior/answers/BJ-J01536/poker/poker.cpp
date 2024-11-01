#include<bits/stdc++.h>
using namespace std;
int n,a[5][14],sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        int case1,case2;
        if(s[0]=='D')case1=1;
        else if(s[0]=='C')case1=2;
        else if(s[0]=='H')case1=3;
        else case1=4;
        if(s[1]>='2'&&s[1]<='9')case2=s[1]-'0';
        else if(s[1]=='T')case2=10;
        else if(s[1]=='A')case2=1;
        else if(s[1]=='J')case2=11;
        else if(s[1]=='Q')case2=12;
        else case2=13;
        a[case1][case2]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0)sum++;
        }
    }
    cout<<sum;
    return 0;
}
