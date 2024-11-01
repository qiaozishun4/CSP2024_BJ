#include <bits/stdc++.h>
using namespace std;
vector<string> pokers;
map<string,bool> b;
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        pokers.push_back(s);
    }
    for (int i=0;i<pokers.size();){
        if (!b[pokers[i]]){
            b[pokers[i]]=1;
            i++;
        }
        else{
            pokers.erase(pokers.begin()+i);
        }
    }
    cout<<52-pokers.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}