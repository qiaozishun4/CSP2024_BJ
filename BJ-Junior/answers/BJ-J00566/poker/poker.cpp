#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long n;
map<string,bool> m;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        string s;
        cin>>s;
        m[s]=1;
    }
    cout<<52-m.size();
    return 0;
}
