#include <iostream>
using namespace std;
int a[5][14],s,ans=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>s;
    for(int i=1;i<=s;i++){
        char t1,t2;
        int d1,d2;
        cin>>t1>>t2;
        if(t1=='D')d1=1;
        if(t1=='C')d1=2;
        if(t1=='H')d1=3;
        if(t1=='S')d1=4;
        if(t2=='A')d2=1;
        else if(t2=='T')d2=10;
        else if(t2=='J')d2=11;
        else if(t2=='Q')d2=12;
        else if(t2=='K')d2=13;
        else d2=int(t2-'0');
        if(!a[d1][d2]){
            ans--;
            a[d1][d2]=1;
        }
    }
    cout<<ans;
    return 0;
}