#include<iostream>
#include<set>
using namespace std;
set<string> s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string x;
        cin>>x;
        s.insert(x);
    }
    int si=s.size();
    cout<<52-si;
    return 0;
}
