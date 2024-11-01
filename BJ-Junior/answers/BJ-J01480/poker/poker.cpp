#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,s=52;
string a[53];
string d;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d;
        bool w=true;
        for(int j=1;j<i;j++){
            if(a[j]==d){
                w=false;
                break;
            }
        }
        if(w){
            s--;
            a[i]=d;
        }
    }
    cout<<s;
    return 0;
}
