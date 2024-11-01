#include <iostream>

using namespace std;
const int N=1e5+5;
int n;
string a[60];
int main()
{
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt=n;
    for (int i=0;i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[i]==a[j]) cnt--;
        }

    }
    cout <<(52-cnt);
    return 0;
}
