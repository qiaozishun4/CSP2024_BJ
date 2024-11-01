#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,L=1e3+5;
int a[N][L];
int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int T;
    cin>>T;

    while(T--) {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) {
            int l;
            cin>>l;
            for(int j=1;j<=l;j++) {
                cin>>a[i][j];
            }
        }
        while(q--) {
            int r,c;
            cin>>r>>c;
            if(r==1) {
                bool f=false;
                for(int i=1;i<=n;i++) {
                    int idx=-1;
                    for(int j=2;j<=k;j++) {
                        if(a[i][j]==1) {
                            idx=j;
                            break;
                        }
                    }
                    if(idx!=-1) {
                        if(c==1) {
                            int cnt=0;
                            for(int j=2;j<=k;j++) {
                                if(a[i][j]==1) {
                                    cnt++;
                                }
                            }
                            if(cnt>1) {
                                cout<<1<<endl;
                                f=true;
                            }
                            break;
                        }
                        else {
                            for(int j=2;j<=k;i++) {
                                if(a[i][j]==c&&i>idx) {
                                    cout<<1<<endl;
                                    f=true;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(!f) {
                    cout<<0<<endl;
                }
            }
        }
    }

	return 0;
}
