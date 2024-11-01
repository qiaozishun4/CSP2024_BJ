#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,p;
string sa[20]={
    "-1",
    "1",
    "7",
    "4",
    "2",
    "6",
    "8",
    "10",
    "18",
    "22",
    "20",
    "28",
    "68",
},sb[10]={
    "88",
    "188",
    "200",
    "208",
    "288",
    "688",
    "888"
};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>p;
        if(p<14){
            cout<<sa[p-1]<<endl;
        }
        else{
            cout<<sb[(p-1)%7];
            for(int i=0;i<=p-21;i+=7){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}