#include<bits/stdc++.h>
using namespace std;
struct q{
    string a;
}p[1001];
int main(){
    int n,j,t=0;
    bool f=true;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<=i;j++){
            if(p[j].a==str){
                f=false;
                break;
            }
        }
        if(f){
                p[t].a=str;
                t++;
            }
        f=true;

    }
    cout<<52-t;
    return 0;
}

