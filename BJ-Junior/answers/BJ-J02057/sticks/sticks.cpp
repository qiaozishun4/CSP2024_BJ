#include <iostream>
using namespace std;
int main(){
    freeopen("poker.in","r",stdin);
    freeopen("poker.out","w",stdout);
    int n,cnt=0;
    cin >> n;
    int stick[]={0};
    for(int i=1; i<=n; i++){
        cin >> stick[i];
    }
    int num[]={6,2,5,5,4,5,6,3,7,6};
    for(int i=0; i<n; i++){
        for(int j=0; j<=9; j++){
            if(stick[i]==num[j]){
                cout << j << endl;
                cnt++;
                break;
            }
        }
        if(cnt==0){
            cout << "-1" << endl;
        }
    }

    return 0;
}
