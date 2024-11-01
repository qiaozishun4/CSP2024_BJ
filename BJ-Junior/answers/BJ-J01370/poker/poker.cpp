#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<char> S;
set<char> D;
set<char> C;
set<char> H;
const int num=13;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(a=='D'){
            D.insert(b);
        }else if(a=='C'){
            C.insert(b);
        }else if(a=='H'){
            H.insert(b);
        }else if(a=='S'){
            S.insert(b);
        }
    }
    cout<<num-D.size()+num-C.size()+num-H.size()+num-S.size();
    return 0;
}
