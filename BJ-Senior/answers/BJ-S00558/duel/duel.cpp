#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n a[N],s;
bool h[N]=1,g[N]=0;
int main(){
freopen("duel.in","w",stdin);
freopen("duel.out","r",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
    if(a[i]>a[i-1]){
    h[i-1]=0;
    }else{
    for(int j=1;j<i;j++){
     if(h[j]!=0&&a[i]>a[j]){
        h[j]=0;
        break;
     }
    }
    }
}
for(int i=1;i<=n;i++){
    if(h[i]!=0){
    s++;
    }
}
cout<<s;
	/*for(int i=1;i<=n;i++){
		if(h[i]==0){
			contiune;
		}
		for(int j=1;j<=n;j++){
		if(a[i]>a[j]){
			h[j]=0;
			g[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
	if(h[i]==1){
		s++;
	}
	}
	cout<<s;*/
    return 0;
}
