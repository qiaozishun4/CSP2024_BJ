#include<iostream>
using namespace std;
int h[7][55];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='A') h[1][1]++;
            else if(s[1]=='T') h[1][10]++;
            else if(s[1]=='J') h[1][11]++;
            else if(s[1]=='Q') h[1][12]++;
            else if(s[1]=='K') h[1][13]++;
            else h[1][s[1]-'0']++;
        }
        else if(s[0]=='C'){
            if(s[1]=='A') h[2][1]++;
            else if(s[1]=='T') h[2][10]++;
            else if(s[1]=='J') h[2][11]++;
            else if(s[1]=='Q') h[2][12]++;
            else if(s[1]=='K') h[2][13]++;
            else h[2][s[1]-'0']++;
        }
        else if(s[0]=='H'){
            if(s[1]=='A') h[3][1]++;
            else if(s[1]=='T') h[3][10]++;
            else if(s[1]=='J') h[3][11]++;
            else if(s[1]=='Q') h[3][12]++;
            else if(s[1]=='K') h[3][13]++;
            else h[3][s[1]-'0']++;
        }
        else{
            if(s[1]=='A') h[4][1]++;
            else if(s[1]=='T') h[4][10]++;
            else if(s[1]=='J') h[4][11]++;
            else if(s[1]=='Q') h[4][12]++;
            else if(s[1]=='K') h[4][13]++;
            else h[4][s[1]-'0']++;
        }
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!h[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

//finish time: 8:44
//luogu uid 453759
//BJ-J01371
//qwqawa
//IAKIOI
