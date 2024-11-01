#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int h[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        int num=0;
        if(s[0]=='C')num+=13;
        if(s[0]=='H')num+=26;
        if(s[0]=='S')num+=39;
        char c=s[1];
        if(c=='A')num++;
        if(c>='0'&&c<='9'){
            num+=(int)(c-'0');
        }
        if(c=='T')num+=10;
        if(c=='J')num+=11;
        if(c=='Q')num+=12;
        if(c=='K')num+=13;
        h[num]++;
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(h[i])ans++;
    }
    cout<<52-ans;
    return 0;
}