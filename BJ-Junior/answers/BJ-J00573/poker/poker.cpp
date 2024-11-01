#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string str;
map<string,bool>a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(a[str]==false){
            cnt++;
        }
        a[str]=true;
    }
    cout<<52-cnt;
    return 0;
}
