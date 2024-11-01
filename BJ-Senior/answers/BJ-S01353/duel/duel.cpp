#include<fstream>
#include<algorithm>

using namespace std;

ifstream cin("duel.in");
ofstream cout("duel.out");

int n,arr[100001];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mini=1;
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        int cur=1;
        while(arr[i]==arr[i+1]){
            cur++;
            i++;
        }
        if(cur>mini)mini=cur;
    }
    cout<<mini<<endl;
    return 0;
}