#include<bits/stdc++.h>

using namespace std;

const char X[]={'D','C','H','S'} , Y[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'} ;

int n,res;
map<pair<char,char>,bool> mp;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char x,y;
        cin>>x>>y;
        if(mp.find({x,y})==mp.end()){
            mp.insert({{x,y},true});
        }
    }
    for(char i:X){
        for(char j:Y){
            if(mp.find({i,j})==mp.end()){
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
// zhu wo AC