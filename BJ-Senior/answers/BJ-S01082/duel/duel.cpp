#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=n,b[n+5],a[100005],min=100005,min2=100000,max=0;
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	a[x]++;
    	if(x>max){
   	    max=x;
    	}
    }
    c=1;
    for(int i=1;i<=max;i++){
    	if(a[i]>0){ 
    	    b[c]=a[i];
    	    c++;
    	}
    } 
    for(int i=2;i<=c;i++){
    	if(a[i-1]<a[i]){
    	    sum=sum-a[i-1];
    	}else{
    	    sum=sum-a[i];
    	}
    }
    return 0;
}