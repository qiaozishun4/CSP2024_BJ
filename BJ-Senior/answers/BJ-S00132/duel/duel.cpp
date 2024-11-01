#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

ifstream fin("duel.in");
ofstream fout("duel.out");

int n;
int a[maxn];

map<int,int> mp;

int main(){
    ios::sync_with_stdio(0);
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    
    for(int i=1;i<=n;i++)
        mp[a[i]]++;
    
    int cnt=0,k=0;
    for(auto t:mp){
        int d=min(cnt,t.second);
        cnt-=d;
        k+=d;
        cnt+=t.second;
    }
    fout<<n-k<<endl;

    return 0;
}
// g++ duel.cpp -o duel.exe -std=c++14 -O2 -Wall && ./duel.exe