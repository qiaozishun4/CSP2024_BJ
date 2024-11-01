
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        string s1;
        cin>>s1;
        if(int(s.find(s1))==-1){
            sum++;
            s+=" ";
            s+=s1;
        }

    }
    cout<<52-sum;
    return 0;
}
