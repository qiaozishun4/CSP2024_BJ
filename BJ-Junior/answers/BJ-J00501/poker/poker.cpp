#include<bits/stdc++.h>
using namespace std;
map<string,bool>l;
string s;
long long n,t;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>s;
        if(!l[s]){
            l[s]=1;
            t++;
        }
    }
    cout<<52-t<<endl;
    return 0;
}
