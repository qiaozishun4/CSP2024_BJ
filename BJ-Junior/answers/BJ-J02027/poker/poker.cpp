#include<bits/stdc++.h>
using namespace std;
int n,len = 0,sum = 52;
string a[100000],b[53],s;
bool ymy(string s,string b,int len){
    for(int i = 0; i < len;i++){
        if(b[i] == s){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        s = a[i];
        if(ymy(s,b,len)){
            b[len] = s;
            len++;
            sum--;
        }
    }
    cout<<sum;
    return 0;
}