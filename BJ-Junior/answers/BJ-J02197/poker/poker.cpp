#include <bits/stdc++.h>
using namespace std;
int D[13]={},C[13]={},H[13]={},S[13]={};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        if(a[1]=='A'){
            if(a[0]='D'){
                D[1]+=1;
            }
            else if(a[0]='C'){
                C[1]+=1;
            }
            else if(a[0]='H'){
                H[1]+=1;
            }
            else if(a[0]='S'){
                S[1]+=1;
            }
        }
        else if(a[1]>='2' && a[1]<='9'){
            if(a[0]='D'){
                D[int(a[1]-'0')]+=1;
            }
            else if(a[0]='C'){
                C[int(a[1]-'0')]+=1;
            }
            else if(a[0]='H'){
                H[int(a[1]-'0')]+=1;
            }
            else if(a[0]='S'){
                S[int(a[1]-'0')]+=1;
            }
        }
        else if(a[1]=='T'){
            if(a[0]='D'){
                D[10]+=1;
            }
            else if(a[0]='C'){
                C[10]+=1;
            }
            else if(a[0]='H'){
                H[10]+=1;
            }
            else if(a[0]='S'){
                S[10]+=1;
            }
        }
        else if(a[1]=='J'){
            if(a[0]='D'){
                D[11]+=1;
            }
            else if(a[0]='C'){
                C[11]+=1;
            }
            else if(a[0]='H'){
                H[11]+=1;
            }
            else if(a[0]='S'){
                S[11]+=1;
            }
        }
        else if(a[1]=='Q'){
            if(a[0]='D'){
                D[12]+=1;
            }
            else if(a[0]='C'){
                C[12]+=1;
            }
            else if(a[0]='H'){
                H[12]+=1;
            }
            else if(a[0]='S'){
                S[12]+=1;
            }
        }
        if(a[1]=='K'){
            if(a[0]='D'){
                D[13]+=1;
            }
            else if(a[0]='C'){
                C[13]+=1;
            }
            else if(a[0]='H'){
                H[13]+=1;
            }
            else if(a[0]='S'){
                S[13]+=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=13;i++){
        if(D[i]<1){
            cnt+=1;
        }
        if(C[i]<1){
            cnt+=1;
        }
        if(H[i]<1){
            cnt+=1;
        }
        if(S[i]<1){
            cnt+=1;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}