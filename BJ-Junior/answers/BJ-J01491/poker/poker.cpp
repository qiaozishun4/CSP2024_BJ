#include <bits/stdc++.h>
using namespace std;

bool D[24];
bool C[24];
bool H[24];
bool S[24];
//A 2 3 4 5 6 7 8 9 T  J  Q  K
//1 2 3 4 5 6 7 8 9 10 11 12 13

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        int temp;
        switch(b){
            case 'A': temp=1; break;
            case '2': temp=2; break;
            case '3': temp=3; break;
            case '4': temp=4; break;
            case '5': temp=5; break;
            case '6': temp=6; break;
            case '7': temp=7; break;
            case '8': temp=8; break;
            case '9': temp=9; break;
            case 'T': temp=10; break;
            case 'J': temp=11; break;
            case 'Q': temp=12; break;
            case 'K': temp=13; break;
        }
        switch(a){
            case 'D': D[temp]=1; break;
            case 'C': C[temp]=1; break;
            case 'H': H[temp]=1; break;
            case 'S': S[temp]=1; break;
        }
    }
    int s=0;
    for(int i=1;i<=13;i++) if(D[i]==0) s+=1;
    for(int i=1;i<=13;i++) if(C[i]==0) s+=1;
    for(int i=1;i<=13;i++) if(H[i]==0) s+=1;
    for(int i=1;i<=13;i++) if(S[i]==0) s+=1;
    cout<<s;
    return 0;
}