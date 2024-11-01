#include<bits/stdc++.h>
using namespace std;
int pkp[52];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char x,y;
        cin>>x>>y;
        if(x=='D'){
            if(y=='A')pkp[0]++;
            else if(y=='T') pkp[9]++;
            else if(y=='J') pkp[10]++;
            else if(y=='Q') pkp[11]++;
            else if(y=='K') pkp[12]++;
            else{
                pkp[int(y-'0')-1]++;
            }
        }
        else if(x=='C'){
            if(y=='A')pkp[13]++;
            else if(y=='T') pkp[22]++;
            else if(y=='J') pkp[23]++;
            else if(y=='Q') pkp[24]++;
            else if(y=='K') pkp[25]++;
            else{
                pkp[int(y-'0')-1+13]++;
            }
        }
        else if(x=='H'){
            if(y=='A')pkp[26]++;
            else if(y=='T') pkp[35]++;
            else if(y=='J') pkp[36]++;
            else if(y=='Q') pkp[37]++;
            else if(y=='K') pkp[38]++;
            else{
                pkp[int(y-'0')-1+26]++;
            }
        }
        else if(x=='F'){
            if(y=='A')pkp[39]++;
            else if(y=='T') pkp[48]++;
            else if(y=='J') pkp[49]++;
            else if(y=='Q') pkp[50]++;
            else if(y=='K') pkp[51]++;
            else{
                pkp[int(y-'0')-1+39]++;
            }
        }
    }
    int sum=0;
    for(int i=0;i<52;i++){
        if(pkp[i]==0) sum++;
    }
    cout<<sum;
    return 0;
}