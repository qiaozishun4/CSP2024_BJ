#include<bits/stdc++.h>
using namespace std;
bool tong[114][114];
int n;
void get(string s){
    int ind1,ind2=s[1]-'0';
    if(s[0]=='D')ind1=1;
    if(s[0]=='C')ind1=2;
    if(s[0]=='H')ind1=3;
    if(s[0]=='S')ind1=4;
    if(s[1]=='A')ind2=1;
    if(s[1]=='T')ind2=10;
    if(s[1]=='J')ind2=11;
    if(s[1]=='Q')ind2=12;
    if(s[1]=='K')ind2=13;
    tong[ind1][ind2]=true;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        get(s);
    }
    int all=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            //cout << tong[i][j];
            if(tong[i][j])all--;
        }
        //cout << endl;
    }
    cout << all << endl;
    return 0;
}
