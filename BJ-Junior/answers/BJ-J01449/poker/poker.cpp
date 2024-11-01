#include<bits/stdc++.h>
using namespace std;

int n,cnt;
string s;
bool mp[20][300];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    char type;
    int v;
    while(n--){
        cin>>s;
        type=s[0];
        if(s[1]>='0'&&s[1]<='9')v=s[1]-'0';
        else{
            if(s[1]=='A')v=1;
            else if(s[1]=='T')v=10;
            else if(s[1]=='J')v=11;
            else if(s[1]=='Q')v=12;
            else v=13;
        }
        if(!mp[v][type]){
            cnt++;
            mp[v][type]=1;
        }

    }
    cout<<52-cnt;
    return 0;
}
