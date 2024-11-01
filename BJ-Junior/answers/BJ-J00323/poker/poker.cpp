#include <bits/stdc++.h>
using namespace std;
long long n;
int ans=52;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n<=1){
        ans-=n;
        cout<<ans<<endl;
        return 0;
    }
   
    
    for(int i=0;i<n;i++){
        cin>>s;
        ans--;
        
    }
    cout<<ans;
    return 0;
}

