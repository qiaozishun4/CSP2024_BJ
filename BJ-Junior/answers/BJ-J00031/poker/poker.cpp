#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n;
    cin>>n;
    vector<ll>d(15,0);
    vector<ll>c(15,0);
    vector<ll>h(15,0);
    vector<ll>s2(15,0);
    string s;
    for(ll i=1;i<=n;++i){
        cin>>s;
        if(s[0]=='D'){
            if(isdigit(s[1])) ++d[s[1]-'0'];
            else{
                if(s[1]=='A') ++d[1];
                else if(s[1]=='T') ++d[10];
                else if(s[1]=='J') ++d[11];
                else if(s[1]=='Q') ++d[12];
                else if(s[1]=='K') ++d[13];
            }
        }
        else if(s[0]=='C'){
            if(isdigit(s[1])) ++c[s[1]-'0'];
            else{
                if(s[1]=='A') ++c[1];
                else if(s[1]=='T') ++c[10];
                else if(s[1]=='J') ++c[11];
                else if(s[1]=='Q') ++c[12];
                else if(s[1]=='K') ++c[13];
            }
        }
        else if(s[0]=='H'){
            if(isdigit(s[1])) ++h[s[1]-'0'];
            else{
                if(s[1]=='A') ++h[1];
                else if(s[1]=='T') ++h[10];
                else if(s[1]=='J') ++h[11];
                else if(s[1]=='Q') ++h[12];
                else if(s[1]=='K') ++h[13];
            }
        }
        else if(s[0]=='S'){
            if(isdigit(s[1])) ++s2[s[1]-'0'];
            else{
                if(s[1]=='A') ++s2[1];
                else if(s[1]=='T') ++s2[10];
                else if(s[1]=='J') ++s2[11];
                else if(s[1]=='Q') ++s2[12];
                else if(s[1]=='K') ++s2[13];
            }
        }
    }
    ll sum=0;
    for(ll i=1;i<=13;++i){
        if(d[i]==0) ++sum;
        if(c[i]==0) ++sum;
        if(h[i]==0) ++sum;
        if(s2[i]==0) ++sum;
    }
    cout<<sum<<endl;
    return 0;
}
