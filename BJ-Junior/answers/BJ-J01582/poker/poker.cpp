#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,c=52;
    cin>>n;
    vector<string> s;
    while(n--){
        string sb;
        cin>>sb;
        int t = 1;
        for(int i = 0;i<s.size();i++){
            if(s[i]==sb){
                t=0;
                break;
            }
        }
        if(t){
            s.push_back(sb);
            c--;
        }
    }
    cout<<c<<endl;
    return 0;
}