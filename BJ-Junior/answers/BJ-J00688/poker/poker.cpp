#include<bits/stdc++.h>
using namespace std;
bool check[60];
int n;
int ans=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
   for(int i=1;i<=n;i++){
        char aa,bb;
        int num;
        cin>>aa>>bb;
        if(bb=='A'){
            num=1;
        }
        else if(bb=='T'){
            num=10;
        }
        else if(bb=='J'){
            num=11;
        }
        else if(bb=='Q'){
            num=12;
        }
        else if(bb=='K'){
            num=13;
        }
        else{
            num=bb-'0';
        }
        if(aa=='D'){
            num*=1;
        }
        else if(aa=='C'){
            num+=13;
        }
        else if(aa=='H'){
            num+=26;
        }
        else if(aa=='S'){
            num+=39;
        }
        if(check[num]==0){
            check[num]=1;
            ans--;
        }
   }
   printf("%d",ans);
    return 0;
}
