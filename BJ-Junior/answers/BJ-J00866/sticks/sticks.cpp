#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int sl[10]={6,2,5,5,4,5,6,3,7,6},mi;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
		mi=1000000;
        if(a[i]==1){
            cout<<-1<<endl;
            continue;
        }
        for(int j=0;j<=9;j++){
            if(a[i]==sl[j]&&sl[j]<mi){
                mi=j;
            }
        }
        cout<<mi<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
