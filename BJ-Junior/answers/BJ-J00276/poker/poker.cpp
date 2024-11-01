#include <iostream>
#include <cstring>
using namespace std;
int n,tot;
string t,s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>t;
        bool f=true;
        for(int i=0;i<s.length();i+=2){
            if(s[i]==t[0]&&s[i+1]==t[1]){
                f=false;
                break;
            }
        }
        if(f){
            s+=t;
            tot++;
        }
    }
    cout<<52-tot<<endl;
}
