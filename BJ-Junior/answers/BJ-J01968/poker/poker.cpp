#include<bits/stdc++.h>
using namespace std;
int f1(char x){
    if(x=='D')return 0;
    if(x=='C')return 1;
    if(x=='H')return 2;
    return 3;
}
int f2(char x){
    if(x=='A')return 0;
    if(x>='2'&&x<='9')return x-'0'-1;
    if(x=='T')return 9;
    if(x=='J')return 10;
    if(x=='Q')return 11;
    return 12;
}
int n,poker[52]={},ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        char opt1,opt2;
        cin>>opt1>>opt2;
        poker[f1(opt1)*13+f2(opt2)]++;
    }
    for(int i=0;i<52;i++)if(!poker[i])ans++;
    cout<<ans;
    return 0;
}
