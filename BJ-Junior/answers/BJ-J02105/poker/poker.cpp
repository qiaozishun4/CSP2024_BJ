#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("poker.in");
    ofstream fout("poker.out");
    map<string,bool> tong;
    long long a,b,c,d,e,f,g,h,i,n;
    fin>>n;
    b=52;
    for(a=1;a<=n;a++){
        string s;
        fin>>s;
        if(!tong[s]){
            b--;
            tong[s]=1;
        }
    }
    fout<<b;
    return 0;
}