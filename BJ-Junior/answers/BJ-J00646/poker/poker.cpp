#include <bits/stdc++.h>
using namespace std;
bool pai[999][999]={false};
int main(){
    int sum=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		
        char x,y;
        cin>>x >>y;
        if(!pai[x+'0'][y+'0']){
            pai[x+'0'][y+'0']=true;
            sum++;
       }


   }
   cout<<52-sum;
   return 0;
}
