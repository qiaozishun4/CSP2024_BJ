#include <cstdio>
#include <time.h>
#include <iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,q1,l,s,q,r,c;
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            scanf("%d",&l);
            for(int i=0;i<l;i++)scanf("%d",&s);
            scanf("%d",&q1);
            for(int i=0;i<q;i++)scanf("%d%d",&r,&c),printf("%d\n",rand()|1);
        }
    }
    return 0;
}
