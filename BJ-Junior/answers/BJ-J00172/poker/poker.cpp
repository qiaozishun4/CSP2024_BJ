#include<bits/stdc++.h>
using namespace std;
string a;
map<string,bool>b;
long long n,ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(b[a]!=1){
           ans++;
           b[a]=1;
        }
    }
    cout<<52-ans;
    return 0;
}
