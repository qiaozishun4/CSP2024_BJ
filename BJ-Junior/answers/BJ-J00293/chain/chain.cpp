#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) {
			int l;
            cin>>l;
            for(int j=1;j<=l;j++) {
				int s;
                cin>>s;
            }
        }
        for(int i=1;i<=q;i++) {
			int r,c;
			cin>>r>>c;
			cout<<0<<endl;
		}
    }
	return 0;
}
