#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int E = 2e6 + 5;
int a[E];
int c[E];
int ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    int T;
    ans = 0;
    cin>>T;
    for(int i=0;i<T;i++){
		ans = 0;
		int si,sj,sii,sji;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        //sort(a,a+n);
        sii=0;//s的i的index
        sji=1;//s的j的index
		si=a[0];
		sj=0;
        for(int j=1;j<n;j++){
			if(a[j]!=si&&sii!=j&&a[sii+1]!=si&&a[sii+2]!=si&&sj!=a[j]&&a[sii+3]!=si){
				sii=j;
				si=a[j];
			}
	        if(a[j]!=sj&&sji!=i&&a[sji+1]!=sj&&a[sji+2]!=sj&&si!=a[j]&&a[sji+3]!=sj){
				sji=j;
				sj=a[j];
	        }
			if(a[j]==si&&j!=sii){
				ans+=a[j];
			}
			if(a[j]==sj&&j!=sji){
				ans+=a[j];
			}
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
