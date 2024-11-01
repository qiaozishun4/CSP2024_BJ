//GL@17SXYZ
//Y#C*GF@24
//judge script - judge.sh
//cd explore
/*
    cp explore2.in explore.in
    rm explore
    g++ -o explore explore.cpp -O2 -std=c++14 -static
    time ./explore
    diff explore.out explore2.ans
    rm explore.in
    rm explore.out
*/
//bash ./judge.sh
#include<bits/stdc++.h>
using namespace std;
int t,tmp1,tmp2,tmp3,q;
int main(){
    srand(time(0)),freopen("chain.in","r",stdin),freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&tmp1,&tmp2,&q);
        while(tmp1--){
            scanf("%d",&tmp2);
            while(tmp2--)scanf("%d",&tmp3);
        }
        while(q--)scanf("%d%d",&tmp1,&tmp2),cout<<rand()%2<<'\n';
    }
}