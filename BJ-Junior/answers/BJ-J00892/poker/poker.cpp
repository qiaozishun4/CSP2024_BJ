#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bool S[20],H[20],C[20],D[20];
string ch;
int main(){
   freopen("poker.in","r",stdin);
   freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>ch;
        if(ch[0]=='S'){
            if(ch[1]=='A'){
                S[1]=1;
            }else if(ch[1]>='2'&&ch[1]<='9'){
                S[ch[1]-'0']=1;
            }else if(ch[1]=='T'){
                S[10]=1;
            }else if(ch[1]=='J'){
                S[11]=1;
            }else if(ch[1]=='Q'){
                S[12]=1;
            }else if(ch[1]=='K'){
                S[13]=1;
            }
        }else if(ch[0]=='H'){
            if(ch[1]=='A'){
                H[1]=1;
            }else if(ch[1]>='2'&&ch[1]<='9'){
                H[ch[1]-'0']=1;
            }else if(ch[1]=='T'){
                H[10]=1;
            }else if(ch[1]=='J'){
                H[11]=1;
            }else if(ch[1]=='Q'){
                H[12]=1;
            }else if(ch[1]=='K'){
                H[13]=1;
            }
        }else if(ch[0]=='C'){
            if(ch[1]=='A'){
                C[1]=1;
            }else if(ch[1]>='2'&&ch[1]<='9'){
                C[ch[1]-'0']=1;
            }else if(ch[1]=='T'){
                C[10]=1;
            }else if(ch[1]=='J'){
                C[11]=1;
            }else if(ch[1]=='Q'){
                C[12]=1;
            }else if(ch[1]=='K'){
                C[13]=1;
            }
        }else if(ch[0]=='D'){
            if(ch[1]=='A'){
                D[1]=1;
            }else if(ch[1]>='2'&&ch[1]<='9'){
                D[ch[1]-'0']=1;
            }else if(ch[1]=='T'){
                D[10]=1;
            }else if(ch[1]=='J'){
                D[11]=1;
            }else if(ch[1]=='Q'){
                D[12]=1;
            }else if(ch[1]=='K'){
                D[13]=1;
            }
        }
    }
    for(int i=1;i<=13;++i){
        if(S[i]){
            cnt++;
        }
        if(H[i]){
            cnt++;
        }
        if(C[i]){
            cnt++;
        }
        if(D[i]){
            cnt++;
        }
    }
    cout<<52-cnt;
}
