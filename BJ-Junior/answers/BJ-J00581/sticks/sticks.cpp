#include<bits/stdc++.h>
using namespace std;
long long n,temp;
vector<long long> a;
int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> n;
    for(long long i = 0; i<n;i++){
        cin >>temp;
        a.push_back(temp);
    }

    for(long long i =0 ;i<n;i++){

        if(a[i]<2){
            cout << -1 <<endl;
            continue;
        }

        cout << a[i];

    }

    return 0;
}
