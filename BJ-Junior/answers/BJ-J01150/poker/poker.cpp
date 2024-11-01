#include<bits/stdc++.h>
using namespace std;
int pkr[11][101]={0},n;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D') {
            if(s[1]>='2'&&s[1]<='9'){
                pkr[1][s[1]-'0']++;
            }
            else if(s[1]=='A'){
                pkr[1][1]++;
            }
            else if(s[1]=='T'){
                pkr[1][10]++;
            }
            else if(s[1]=='J'){
                pkr[1][11]++;
            }
            else if(s[1]=='Q'){
                pkr[1][12]++;
            }
            else{
                pkr[1][13]++;
            }
        }
        if(s[0]=='C') {
            if(s[1]>='2'&&s[1]<='9'){
                pkr[2][s[1]-'0']++;
            }
            else if(s[1]=='A'){
                pkr[2][1]++;
            }
            else if(s[1]=='T'){
                pkr[2][10]++;
            }
            else if(s[1]=='J'){
                pkr[2][11]++;
            }
            else if(s[1]=='Q'){
                pkr[2][12]++;
            }
            else{
                pkr[2][13]++;
            }
        }
        if(s[0]=='H') {
            if(s[1]>='2'&&s[1]<='9'){
                pkr[3][s[1]-'0']++;
            }
            else if(s[1]=='A'){
                pkr[3][1]++;
            }
            else if(s[1]=='T'){
                pkr[3][10]++;
            }
            else if(s[1]=='J'){
                pkr[3][11]++;
            }
            else if(s[1]=='Q'){
                pkr[3][12]++;
            }
            else{
                pkr[3][13]++;
            }
        }
        if(s[0]=='S') {
            if(s[1]>='2'&&s[1]<='9'){
                pkr[4][s[1]-'0']++;
            }
            else if(s[1]=='A'){
                pkr[4][1]++;
            }
            else if(s[1]=='T'){
                pkr[4][10]++;
            }
            else if(s[1]=='J'){
                pkr[4][11]++;
            }
            else if(s[1]=='Q'){
                pkr[4][12]++;
            }
            else{
                pkr[4][13]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(pkr[i][j]>0) ans++;
        }
    }
    cout<<52-ans<<"\n";
    return 0;
}
