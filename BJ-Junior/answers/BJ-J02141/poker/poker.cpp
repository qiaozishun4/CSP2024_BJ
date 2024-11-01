#include<bits/stdc++.h>
using namespace std;
int n,fp[120],ch[120],ht[120],hot[120],sum=52;
char s[103][3];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        if(s[i][1]=='D'&&fp[s[i][2]]>0){
            continue;
        }else if(s[i][1]=='C'&&ch[s[i][2]]>0){
            continue;
        }else if(s[i][1]=='H'&&hot[s[i][2]]>0){
            continue;
        }else if(s[i][1]=='S'&&ht[s[i][2]]>0){
            continue;
        }
        if(s[i][1]=='D'){
            fp[s[i][2]]++;
            sum--;
        }else if(s[i][1]=='C'){
            ch[s[i][2]]++;
            sum--;
        }else if(s[i][1]=='H'){
            hot[s[i][2]]++;
            sum--;
        }else if(s[i][1]=='S'){
            ht[s[i][2]]++;
            sum--;
        }
    }
    cout<<sum;
    return 0;
}
