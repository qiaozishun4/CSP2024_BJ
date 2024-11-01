#include <bits/stdc++.h>
using namespace std;
int poker[54];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        int c=0;
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='T')c+=10;
            else if(s[1]=='J')c+=11;
            else if(s[1]=='Q')c+=12;
            else if(s[1]=='K')c+=13;
            else{
                int p=s[1]-'0';
                c+=p;
            }
            poker[c]++;
        }
        else if(s[0]=='C'){
            c+=13;
            if(s[1]=='T')c+=10;
            else if(s[1]=='J')c+=11;
            else if(s[1]=='Q')c+=12;
            else if(s[1]=='K')c+=13;
            else{
                int p=s[1]-'0';
                c+=p;
            }
            poker[c]++;
        }
        else if(s[0]=='H'){
            c+=26;
            if(s[1]=='T')c+=10;
            else if(s[1]=='J')c+=11;
            else if(s[1]=='Q')c+=12;
            else if(s[1]=='K')c+=13;
            else{
                int p=s[1]-48;
                c+=p;
            }
            poker[c]++;
        }
        else if(s[0]=='S'){
            c+=39;
            if(s[1]=='T')c+=10;
            else if(s[1]=='J')c+=11;
            else if(s[1]=='Q')c+=12;
            else if(s[1]=='K')c+=13;
            else if(s[1]=='A')c+=1;
            else{
                int p=s[1]-48;
                c+=p;
            }
            poker[c]++;
        }
    }
    for(int i=1;i<=52;i++){
        if(poker[i]==0)
            ans++;
    }
    cout<<ans;
    return 0;
}
