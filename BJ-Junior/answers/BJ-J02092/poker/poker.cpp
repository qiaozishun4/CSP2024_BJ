#include<bits/stdc++.h>
using namespace std;
int D[10000],C[1000],H[1000],S[1000];
int main(){
    int w=52,n;
    freopen("poker2.in","r",stdin);
    freopen("poker2.out","w",stdout);

    cin>>n;
    string a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<51;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(a[i][0]=='D'){
            if(a[i][1]>'0'&&a[i][1]<'9'&& D[a[i][1]]!=1){
                D[a[i][1]]=1;
                w-=1;
            }else {
        }
                 if(D[a[i][1]]!=1){
                    if(a[i][1]=='A'){
                        D[1]=1;
                        w-=1;
                    }
                    if(a[i][1]=='J'){
                        D[11]=1;
                        w-=1;
                    }if(a[i][1]=='Q'){
                        D[12]=1;
                        w-=1;
                    }if(a[i][1]=='K'){
                        D[13]=1;
                        w-=1;
                    }
                }
            }if(a[i][0]=='C'){
            if(a[i][1]>'0'&&a[i][1]<'9'&& C[a[i][1]]!=1){
                C[a[i][1]]=1;
                w-=1;
            }else {
            }
                if(C[a[i][1]]!=1){
                    if(a[i][1]=='A'){
                        C[1]=1;
                        w-=1;
                    }
                    if(a[i][1]=='J'){
                        C[11]=1;
                        w-=1;
                    }if(a[i][1]=='Q'){
                        C[12]=1;
                        w-=1;
                    }if(a[i][1]=='K'){
                        C[13]=1;
                        w-=1;
                    }
                }
            }if(a[i][0]=='H'){
            if(a[i][1]>'0'&&a[i][1]<'9'&& H[a[i][1]]!=1){
                H[a[i][1]]=1;
                w-=1;
            }else {
            }
                if(H[a[i][1]]!=1){
                    if(a[i][1]=='A'){
                        H[1]=1;
                        w-=1;
                    }
                    if(a[i][1]=='J'){
                        H[11]=1;
                        w-=1;
                    }if(a[i][1]=='Q'){
                        H[12]=1;
                        w-=1;
                    }if(a[i][1]=='K'){
                        H[13]=1;
                        w-=1;
                    }
                }
            }if(a[i][0]=='S'){
            if(a[i][1]>'0'&&a[i][1]<'9'&& S[a[i][1]]!=1){
                S[a[i][1]]=1;
                w-=1;
            }else {
            }
                if(S[a[i][1]]!=1){
                    if(a[i][1]=='A'){
                        S[1]=1;
                        w-=1;
                    }
                    if(a[i][1]=='J'){
                        S[11]=1;
                        w-=1;
                    }if(a[i][1]=='Q'){
                        S[12]=1;
                        w-=1;
                    }if(a[i][1]=='K'){
                        S[13]=1;
                       w-=1;
                    }
                }
            }
        }
    if(w<0){
        cout<<0;
    }
else{
    cout<<w;
}

    return 0;
}
