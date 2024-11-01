#include<bits/stdc++.h>
using namespace std;
int n,cnt,mp[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='D'){
            x=1;
        }else if(s[0]=='C'){
            x=2;
        }else if(s[0]=='H'){
            x=3;
        }else{
            x=4;
        }
        if(s[1]>='2'&&s[1]<='9'){
            y=s[1]-'0';
        }else if(s[1]=='A'){
            y=1;
        }else if(s[1]=='T'){
            y=10;
        }else if(s[1]=='J'){
            y=11;
        }else if(s[1]=='Q'){
            y=12;
        }else{
            y=13;
        }
        if(!mp[x][y]){
            cnt++;
            mp[x][y]=1;
        }
    }
    cout<<52-cnt;
    return 0;
}
