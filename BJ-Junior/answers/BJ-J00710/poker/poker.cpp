#include<bits/stdc++.h>
using namespace std;
int hash_int[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]<='9'&&s[1]>='2'){
                hash_int[1][s[1]-'0']++;
            }
            else if(s[1]=='A') hash_int[1][1]++;
            else if(s[1]=='T') hash_int[1][10]++;
            else if(s[1]=='J') hash_int[1][11]++;
            else if(s[1]=='Q') hash_int[1][12]++;
            else if(s[1]=='K') hash_int[1][13]++;
        }
        if(s[0]=='C'){
            if(s[1]<='9'&&s[1]>='2'){
                hash_int[2][s[1]-'0']++;
            }
            else if(s[1]=='A') hash_int[2][1]++;
            else if(s[1]=='T') hash_int[2][10]++;
            else if(s[1]=='J') hash_int[2][11]++;
            else if(s[1]=='Q') hash_int[2][12]++;
            else if(s[1]=='K') hash_int[2][13]++;
        }
        if(s[0]=='H'){
            if(s[1]<='9'&&s[1]>='2'){
                hash_int[3][s[1]-'0']++;
            }
            else if(s[1]=='A') hash_int[3][1]++;
            else if(s[1]=='T') hash_int[3][10]++;
            else if(s[1]=='J') hash_int[3][11]++;
            else if(s[1]=='Q') hash_int[3][12]++;
            else if(s[1]=='K') hash_int[3][13]++;
        }
        if(s[0]=='S'){
            if(s[1]<='9'&&s[1]>='2'){
                hash_int[4][s[1]-'0']++;
            }
            else if(s[1]=='A') hash_int[4][1]++;
            else if(s[1]=='T') hash_int[4][10]++;
            else if(s[1]=='J') hash_int[4][11]++;
            else if(s[1]=='Q') hash_int[4][12]++;
            else if(s[1]=='K') hash_int[4][13]++;
        }
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(hash_int[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
