#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN
#define MAXM
int n,k;
map<string,int> p;
void work(){
    cout<<52-k<<endl;
    return ;
}
void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        if(!p.count(a)){
            k++;
            p[a]=1;
        }
    }
    work();
    return ;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    return 0;
}