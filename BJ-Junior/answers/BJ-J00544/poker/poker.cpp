#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        s.insert(a);
    }
    cout<<52-s.size();
}
