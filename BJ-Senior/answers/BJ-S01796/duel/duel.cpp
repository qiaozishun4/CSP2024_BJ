#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int i[100005];
    for(int j=1;j<=n;j++){
        cin>>i[j];
    }
    for(int j=1;j<=n;j++){
	for(int k=1;k<=n;k++){
		if(i[j]>=i[k]) continue;
		else{ i[k]=i[j]; n--;}
	}
    }
    cout<<n;
    return 0;
}