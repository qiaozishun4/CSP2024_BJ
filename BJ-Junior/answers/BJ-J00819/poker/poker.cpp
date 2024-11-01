#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
bool D[14],C[14],H[14],S[14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='T'){
                D[10]=true;
            }
            else if(s[1]=='A'){
                D[1]=true;
            }
            else if(s[1]=='J'){
                D[11]=true;
            }
            else if(s[1]=='Q'){
                D[12]=true;
            }
            else if(s[1]=='K'){
                D[13]=true;
            }
            else{
                D[s[1]-'0']=true;
            }
        }
        else if(s[0]=='C'){
            if(s[1]=='T'){
                C[10]=true;
            }
            else if(s[1]=='A'){
                C[1]=true;
            }
            else if(s[1]=='J'){
                C[11]=true;
            }
            else if(s[1]=='Q'){
                C[12]=true;
            }
            else if(s[1]=='K'){
                C[13]=true;
            }
            else{
                C[s[1]-'0']=true;
            }
        }
        else if(s[0]=='H'){
            if(s[1]=='T'){
                H[10]=true;
            }
            else if(s[1]=='A'){
                H[1]=true;
            }
            else if(s[1]=='J'){
                H[11]=true;
            }
            else if(s[1]=='Q'){
                H[12]=true;
            }
            else if(s[1]=='K'){
                H[13]=true;
            }
            else{
                H[s[1]-'0']=true;
            }
        }
        else if(s[0]=='S'){
            if(s[1]=='T'){
                S[10]=true;
            }
            else if(s[1]=='A'){
                S[1]=true;
            }
            else if(s[1]=='J'){
                S[11]=true;
            }
            else if(s[1]=='Q'){
                S[12]=true;
            }
            else if(s[1]=='K'){
                S[13]=true;
            }
            else{
                S[s[1]-'0']=true;
            }
        }
        n--;
    }
    for(int i=1;i<=13;i++){
        if(!D[i]){
            ans++;
        }
        if(!C[i]){
            ans++;
        }
        if(!H[i]){
            ans++;
        }
        if(!S[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

