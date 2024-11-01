#include<bits/stdc++.h>
using namespace std;
bool a[55]={0};
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n; cin>>n; int tempp ;string temp;
for(int i =1;i<=n;i++){
    tempp=0;
    cin>>temp;
    if(temp[0]=='D')
   {
       tempp=1;
   }
    else if(temp[0]=='C')
   {
       tempp=14;
   }
   else if(temp[0]=='H')
   {
       tempp=27;
   }
    else
   {
       tempp=40;
   }

   if(temp[1]>='2'&&temp[1]<='9'){

      tempp+=temp[1]-'0'-1;


   }

   else if(temp[1]=='T'){
     tempp +=9;
   }
   else if(temp[1]=='J'){
     tempp +=10;
   }
   else if(temp[1]=='Q'){
     tempp +=11;
   }
   else if(temp[1]=='K'){
     tempp+=12;
   }
   a[tempp]=1;
}
int sum=0;
for(int i=1;i<=52;i++){
    if(a[i]==0){
        sum++;

    }
}
cout<<sum;
return 0;
}
