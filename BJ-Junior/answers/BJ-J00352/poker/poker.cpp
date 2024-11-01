# include <bits/stdc++.h>

using namespace std;
map<string,int> a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,j=0;
    string b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b;
        if(a[b]==0){
            a[b]=1;
            j++;
        }
    }
    cout<<52-j;



    return 0;
}
