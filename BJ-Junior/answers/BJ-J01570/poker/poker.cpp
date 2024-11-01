#include<bits/stdc++.h>
using namespace std;
bool have[5][15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int j=0;
        if(s[0]=='D') j=4;
        else if(s[0]=='H') j=3;
        else if(s[0]=='S') j=2;
        else j=1;

        if(s[1]=='A') have[j][1]=1;
        else if(s[1]=='T') have[j][10]=1;
        else if(s[1]=='J') have[j][11]=1;
        else if(s[1]=='Q') have[j][12]=1;
        else if(s[1]=='K') have[j][13]=1;
        else have[j][s[1]-'0']=1;
    }
    int sum=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!have[i][j]){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
