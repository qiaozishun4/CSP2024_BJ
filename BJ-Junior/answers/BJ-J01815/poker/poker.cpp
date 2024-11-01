#include<bits/stdc++.h>
using namespace std;
bool p[4][13]={false};
string shus="A23456789TJQK";
string huas="DCHS";
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,s=52;
    cin>>n;
    while(n--){
        getchar();
        char hua=getchar(),shu=getchar();
        if(!p[huas.find(hua)][shus.find(shu)])
            s--;
        p[huas.find(hua)][shus.find(shu)]=true;
    }
    cout<<s;
    return 0;
}
