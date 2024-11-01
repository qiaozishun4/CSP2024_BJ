#include<bits/stdc++.h>
using namespace std;
int n,poker[52];
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D'){
            if(b=='A') poker[0]++;
            else if(b=='T') poker[9]++;
            else if(b=='J') poker[10]++;
            else if(b=='Q') poker[11]++;
            else if(b=='K') poker[12]++;
            else poker[b-'0']++;
        }
        else if(a=='C'){
            if(b=='A') poker[13]++;
            else if(b=='T') poker[22]++;
            else if(b=='J') poker[23]++;
            else if(b=='Q') poker[24]++;
            else if(b=='K') poker[25]++;
            else poker[b-'0'+12]++;
        }
        else if(a=='H'){
            if(b=='A') poker[26]++;
            else if(b=='T') poker[35]++;
            else if(b=='J') poker[36]++;
            else if(b=='Q') poker[37]++;
            else if(b=='K') poker[38]++;
            else poker[b-'0'+25]++;
        }
        else if(a=='S'){
            if(b=='A') poker[39]++;
            else if(b=='T') poker[48]++;
            else if(b=='J') poker[49]++;
            else if(b=='Q') poker[50]++;
            else if(b=='K') poker[51]++;
            else poker[b-'0'+38]++;
        }
    }
    int sum=0;
    for(int i=0;i<52;i++)
        if(poker[i]>0) sum++;
    cout<<52-sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}