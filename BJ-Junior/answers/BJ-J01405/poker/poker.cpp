#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,m=0;
    cin>>n;
    string a[n];
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        bool p=true;
        for (int j=0;j<m;j++) if (a[j]==s){
            p=false;
            break;
        }
        if (p){
            a[m]=s;
            m++;
        }
    }
    cout<<52-m;
    return 0;
}