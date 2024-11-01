#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int i1e5=100009;

#define int ll
void test(){
    int n,a[1000];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxres=0;
    for (int k=0;k<1<<n;k++) {
        int res=0;
        for (int i=1;i<=n;i++){
            int curr=1<<(n-i);
            for(int j=i-1, left=1<<(n-j);
                j >= 1;
                left<<=1, --j){
                    //cout<<(k&left)<<" "<<(k&curr)<<endl;
                    //cout<<k<<",,"<<(((k&left)==0))<<",,"<<((k&curr)==0)<<endl;
                if(((k&left)==0) == ((k&curr)==0)) {
                    //cout<<"rept:"<<i<<" "<<j<<endl;
                    if (a[i]==a[j]) {
                        res+=a[i];
                    }
                    break;
                }
            }
        }
        maxres = max(maxres,res);
    }
    cout<<maxres<<endl;
}
#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("color.in","r", stdin);
    freopen("color.out","w", stdout);

    int T;
    cin>>T;
    while (T--) test();

    return 0;
}
