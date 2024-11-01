#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
int n,ans=0;
vector<string>vec;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string t;cin>>t;
        vec.push_back(t);
    }
    sort(vec.begin(),vec.end());
    for(unsigned int i=0;i<vec.size();i++){
		if(vec[i]==vec[i+1]){
			vec.erase(vec.begin()+i,vec.begin()+i+1);
			i--;
		}
	}
    cout<<52-vec.size()<<endl;
    return 0;
}
