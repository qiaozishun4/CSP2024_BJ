#include<iostream>
#include<set>
using namespace std;
set<pair<char,char> > v;
int n;
char t1,t2;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>t1>>t2;
        v.insert(make_pair(t1,t2));
    }
    cout<<52-v.size();
}
