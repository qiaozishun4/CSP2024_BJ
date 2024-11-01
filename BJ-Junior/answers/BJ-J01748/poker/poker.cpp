#include <bits/stdc++.h>
using namespace std;
map<string,int>a;
int n;
int sum=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        a[s]++;
        if(a[s]==1){
            sum--;
        }
    }cout<<sum;
    fclose(stdin);
    fclose(stdout);

return 0;
}
