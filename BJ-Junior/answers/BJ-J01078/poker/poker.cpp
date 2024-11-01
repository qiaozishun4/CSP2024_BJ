#include<iostream>
#include<map>
using namespace std;
map<string,int>mp;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        string t=s;
        if(s[0]!='D'&&s[0]!='C'&&s[0]!='H'&&s[0]!='S'){
            s[0]=t[1],s[1]=t[0];
        }
        mp[s]++;
    }
    cout<<52-mp.size();
    return 0;
}
