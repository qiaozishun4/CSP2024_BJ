#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int check(char num){
    if(num=='A'){
        return 1;
    }
    else if(num=='T'){
        return 10;
    }
    else if(num=='J'){
        return 11;
    }
    else if(num=='Q'){
        return 12;
    }
    else if(num=='K'){
        return 13;
    }
    return (int)num;
}
int32_t main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    vector<vector<bool>> card(5,vector<bool>(14));
    int ans=52;
    for(int i=0;i<n;i++){
        char flower,num;
        cin >> flower >> num;
        int where=check(num);
        if(flower=='D'){
            if(!card[0][where]){
                card[0][where]=true;
                ans--;
            }
        }
        else if(flower=='C'){
            if(!card[1][where]){
                card[1][where]=true;
                ans--;
            }
        }
        else if(flower=='H'){
            if(!card[2][where]){
                card[2][where]=true;
                ans--;
            }
        }
        else{//S
            if(!card[3][where]){
                card[3][where]=true;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
