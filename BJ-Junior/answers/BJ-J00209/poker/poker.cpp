#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,bool>mp;
string pok[52]={
"DA",
"CA",
"HA",
"SA",
"D2",
"C2",
"H2",
"S2",
"D3",
"C3",
"H3",
"S3",
"D4",
"C4",
"H4",
"S4",
"D5",
"C5",
"H5",
"S5",
"D6",
"C6",
"H6",
"S6",
"D7",
"C7",
"H7",
"S7",
"D8",
"C8",
"H8",
"S8",
"D9",
"C9",
"H9",
"S9",
"DT",
"CT",
"ST",
"HT",
"DJ",
"CJ",
"HJ",
"SJ",
"DQ",
"CQ",
"HQ",
"SQ",
"DK",
"CK",
"HK",
"SK",
};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    string str[n];
    for(int i=0;i<n;i++){
        cin>>str[i];
        mp[str[i]]=true;
    }
    int ans=0;
    for(int i=0;i<52;i++){
        if(!mp[pok[i]])ans++;
    }
    printf("%d",ans);
    return 0;
}
