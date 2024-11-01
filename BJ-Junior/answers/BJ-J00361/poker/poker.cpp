#include<bits/stdc++.h>
using namespace std;
int poker[12][23];
int checkhua(string n){
    if(n[0]=='D')
        return 1;
    else if(n[0]=='C')
        return 2;
    else if(n[0]=='H')
        return 3;
    else
        return 4;
}
int checkbig(string n){
    if(n[1]=='A')
        return 1;
    else if(n[1]<='9'&&n[1]>='2')
        return n[1]-48;
    else if(n[1]=='T')
        return 10;
    else if(n[1]=='J')
        return 11;
    else if(n[1]=='Q')
        return 12;
    else if(n[1]=='K')
        return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,cnt=0;
    string temp;
    cin>>n;
    for(int i=0;i<n;poker[checkhua(temp)][checkbig(temp)]++,i++)
        cin>>temp;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!poker[i][j])
                cnt++;
    cout<<cnt;
    return 0;
}
