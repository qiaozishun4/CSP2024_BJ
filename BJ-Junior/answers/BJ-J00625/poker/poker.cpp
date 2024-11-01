#include<bits/stdc++.h>
using namespace std;
int c[52][2];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int cnt=52;
    cnt-=n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D') c[i][1]=1;
        else if(s[0]=='C') c[i][1]=2;
        else if(s[0]=='H') c[i][1]=3;
        else c[i][1]=4;
        if('0'<s[1]&&s[1]<='9') c[i][2]=s[1]-'0';
        else if(s[1]=='T') c[i][2]=10;
        else if(s[1]=='J') c[i][2]=11;
        else if(s[1]=='Q') c[i][2]=12;
        else c[i][2]=13;
        for(int j=1;j<i;j++){
            if(c[i][1]==c[j][1]&&c[i][2]==c[j][2]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
