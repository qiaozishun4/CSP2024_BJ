#include <iostream>
#include <cstdio>
using namespace std;
bool D[100],C[100],H[100],S[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c[5];
        cin>>c;
        if(c[0]=='D'){
            if(c[1]=='A'){
                D[1]=true;
            }else if(c[1]=='T'){
                D[10]=true;
            }else if(c[1]=='J'){
                D[11]=true;
            }else if(c[1]=='Q'){
                D[12]=true;
            }else if(c[1]=='K'){
                D[13]=true;
            }else{
                D[c[1]-'0']=true;
            }
        }
        if(c[0]=='C'){
            if(c[1]=='A'){
                C[1]=true;
            }else if(c[1]=='T'){
                C[10]=true;
            }else if(c[1]=='J'){
                C[11]=true;
            }else if(c[1]=='Q'){
                C[12]=true;
            }else if(c[1]=='K'){
                C[13]=true;
            }else{
                C[c[1]-'0']=true;
            }
        }
        if(c[0]=='H'){
            if(c[1]=='A'){
                H[1]=true;
            }else if(c[1]=='T'){
                H[10]=true;
            }else if(c[1]=='J'){
                H[11]=true;
            }else if(c[1]=='Q'){
                H[12]=true;
            }else if(c[1]=='K'){
                H[13]=true;
            }else{
                H[c[1]-'0']=true;
            }
        }
        if(c[0]=='S'){
            if(c[1]=='A'){
                S[1]=true;
            }else if(c[1]=='T'){
                S[10]=true;
            }else if(c[1]=='J'){
                S[11]=true;
            }else if(c[1]=='Q'){
                S[12]=true;
            }else if(c[1]=='K'){
                S[13]=true;
            }else{
                S[c[1]-'0']=true;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(D[i]==false){
            ans++;
        }
        if(C[i]==false){
            ans++;
        }
        if(H[i]==false){
            ans++;
        }
        if(S[i]==false){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
