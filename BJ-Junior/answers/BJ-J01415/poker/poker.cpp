#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int x,y,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            x=21;
        }else if(s[0]=='C'){
            x=22;
        }else if(s[0]=='H'){
            x=23;
        }else if(s[0]=='S'){
            x=24;
        }
        if(s[1]=='A'){
            y=1;
        }else if(s[1]=='T'){
            y=10;
        }else if(s[1]=='J'){
            y=11;
        }else if(s[1]=='Q'){
            y=12;
        }else if(s[1]=='K'){
            y=13;
        }else{
            y=s[1]-'0';
        }
        a[x][y]=1;
    }
    for(int i=21;i<=24;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
