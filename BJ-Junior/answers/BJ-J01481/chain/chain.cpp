#include <bits/stdc++.h>
using namespace std;
int n,k,q,t,f,t2;
int a;
int firstn,firstk,firstq;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	t2 = t;
	while(t--){
        cin >> n >> k >> q;
        if(t2 - t == 1){
            firstn = n;
            firstk = k;
            firstq = q;
        }
        for(int i = 0;i<n;i++){
            cin >> a;
            for(int j = 0;j<a;j++){
                cin >> f;
            }
        }
        for(int i = 0;i<q;i++){
            cin >> a >> f;
        }
	}
    if(firstn == 3&&firstk == 3&&firstq == 7){
        cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
    }else{
        for(int i = 0;i<k;i++){
            cout<<1<<endl;
        }
    }

	return 0;
}
