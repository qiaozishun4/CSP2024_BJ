#include<bits/stdc++.h>
using namespace std;
bool aahave[200][200];
int c2i(char x){
    if(x=='A') return 1;
    if('2'<=x && x<='9'){
        return (x-'0');
    }
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int aan;
    cin>>aan;
    for(int aai=1;aai<=aan;aai++){
        string aas;
        cin>>aas;
        int aaj;
        if(aas[0]=='D'){
            aaj=1;
        }
        else if(aas[0]=='C'){
            aaj=2;
        }
        else if(aas[0]=='H'){
            aaj=3;
        }
        else if(aas[0]=='S'){
            aaj=4;
        }
        aahave[aaj][c2i(aas[1])]=1;
    }
    int cnt=0;
    for(int aai=1;aai<=4;aai++){
        for(int aaj=1;aaj<=13;aaj++){
            if(aahave[aai][aaj]==0){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}