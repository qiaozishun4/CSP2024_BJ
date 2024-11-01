#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int n, t=0;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(mp[s]==0) t++, mp[s]=1;
    }
    return printf("%d",52-t)&0;
}