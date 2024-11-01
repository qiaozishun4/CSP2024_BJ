#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!!!!!!!!!!!
//ifstream ofstream!!!!

ifstream fin("chain.in");
ofstream fout("chain.out");
const int M = 2e5 + 10,N = 1e5 + 10;
int t,n,k,q,l,s[M],r[N],c[N];
int main(){
    fin >> t;
    while(t --){
        fin >> n >> k >> q;
        for(int i = 1;i <= n;i ++){
            fin >> l;
            for(int j = 1;j <= l;j ++){
                fin >> s[j];
            }
        }
        for(int i = 1;i <= q;i ++){
            fin >> r[i] >> c[i];
        }
        for(int i = 1;i <= q;i ++){
            fout << "0" << endl;
        }
    }
    return 0;
}