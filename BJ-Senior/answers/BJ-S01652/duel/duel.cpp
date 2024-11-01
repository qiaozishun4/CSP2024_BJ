#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
long long a[N];
bool b[N];
bool c[N];
int n;
int ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=true;
        c[i]=true;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]&&c[i]==true&&b[j]==true){
                c[i]=false;
                b[j]=false;
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
