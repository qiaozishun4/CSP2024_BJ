#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a;
    cin>>n;
    vector<int> cards;
    for(int i = 0;i < n;i++){
        cin>>a;
        cards.push_back(a);
    }

    sort(cards.begin(),cards.end());
    int counter = 0;
    for(int i = 0;i < n;i++){
        if(cards[i] > cards[counter]){
            counter++;
        }
    }
    cout<<n-counter;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
