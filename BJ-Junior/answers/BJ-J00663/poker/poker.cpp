#include<bits/stdc++.h>
using namespace std;
int n;char a,c;
int b[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        if(a=='D'){
            if(c=='T')b[10]=1;
            else if(c=='A')b[1]=1;
            else if(c=='J')b[11]=1;
            else if(c=='Q')b[12]=1;
            else if(c=='K')b[13]=1;
            else b[c-'0']=1;
        }
        else if(a=='C'){
            if(c=='T')b[23]=1;
            else if(c=='A')b[14]=1;
            else if(c=='J')b[24]=1;
            else if(c=='Q')b[25]=1;
            else if(c=='K')b[26]=1;
            else b[c-'0'+13]=1;
        }
        else if(a=='H'){
            if(c=='T')b[36]=1;
            else if(c=='A')b[27]=1;
            else if(c=='J')b[37]=1;
            else if(c=='Q')b[38]=1;
            else if(c=='K')b[39]=1;
            else b[c-'0'+26]=1;
        }
        else if(a=='S'){
            if(c=='T')b[49]=1;
            else if(c=='A')b[40]=1;
            else if(c=='J')b[50]=1;
            else if(c=='Q')b[51]=1;
            else if(c=='K')b[52]=1;
            else b[c-'0'+39]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(b[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}
