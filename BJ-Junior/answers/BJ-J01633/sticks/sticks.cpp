#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
const int N=1e5+1;
int a[N];
int num[10]={6,2,5,5,4,5,6,3,7,6};
int sum;
int tot;
int imp(int x,int i){
    while(1){
            if(x==1) return -1;
        sum=i;
        while(sum>0){
            tot+=num[sum%10];
            sum/=10;
        }
        if(tot==x)
            return i;
        tot=0;
        i++;
    }
}
int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<imp(a[i],1)<<endl;
    }

    fclose(stdin);
    fclose(stdout);
   return 0;
}
