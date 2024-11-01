#include <bits/stdc++.h>
using namespace std;
int n=0,ans=0;
int D[14],C[14],H[14],S[14];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            if((s[1]-'0')<=9){
                D[s[1]-'0']+=1;
            }else if(s[1]='T'){
                D[10]+=1;
                }
            else if(s[1]='J'){
                D[11]+=1;
            }
            else if(s[1]='Q'){
                D[12]+=1;
            }else if(s[1]=='A'){
                D[1]+=1;
            }
            else {
                D[13]+=1;
            }
        }else if(s[0]=='C'){
            if((s[1]-'0')<=9){
                    C[s[1]-'0']+=1;
                }else if(s[1]='T'){
                    C[10]+=1;
                    }
                else if(s[1]='J'){
                    C[11]+=1;
                }
                else if(s[1]='Q'){
                    C[12]+=1;
                }else if(s[1]=='A'){
                C[1]+=1;
            }
                else {
                    C[13]+=1;
                }

        }else if(s[0]=='H'){
            if((s[1]-'0')<=9){
                H[s[1]-'0']+=1;
            }else if(s[1]='T'){
                H[10]+=1;
                }
            else if(s[1]='J'){
                H[11]+=1;
            }
            else if(s[1]='Q'){
                H[12]+=1;
            }else if(s[1]=='A'){
                H[1]+=1;
            }
            else {
                H[13]+=1;
            }

        }else{
            if((s[1]-'0')<=9){
                S[s[1]-'0']+=1;
            }else if(s[1]='T'){
                S[10]+=1;
                }
            else if(s[1]='J'){
                S[11]+=1;
            }
            else if(s[1]='Q'){
                S[12]+=1;
            }else if(s[1]=='A'){
                S[1]+=1;
            }
            else {
                S[13]+=1;
            }
        }
    }
    for(int i=1;i<=13;i++){
        if(D[i]<=0)ans+=1;
    }
    for(int i=1;i<=13;i++){
        if(C[i]<=0)ans+=1;
    }for(int i=1;i<=13;i++){
        if(H[i]<=0)ans+=1;
    }for(int i=1;i<=13;i++){
        if(S[i]==0)ans+=1;
    }
    cout<<ans;
}
