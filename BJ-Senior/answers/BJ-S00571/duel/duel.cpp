#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(l);i>=(r);i--)
using namespace std;
const int maxn=1e5+5;
int a1[maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int in;
    cin>>in;
    rep(v1,1,in)scanf("%d",a1+v1);
    sort(a1+1,a1+in+1);
    int p1=1,p2=1;
    while(p1<=in){
        // cout<<p1<<' '<<p2<<endl;
        while(p2<in&&a1[p2]<=a1[p1])p2++;
        if(a1[p2]<=a1[p1])break;
        p1++;
        p2++;
    }
    cout<<in-p1+1<<endl;
    return 0;
}