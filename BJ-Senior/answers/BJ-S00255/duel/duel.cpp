#include <bits/stdc++.h>
using namespace std;

vector<int> monsters;
int n;
int in_;
int weak=0;
int strong=0;

int main() {

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> in_;
        monsters.push_back(in_);
    }

    sort(monsters.begin(), monsters.end());


    int i=0;
    int mem=monsters[0];


    while(!(monsters[i]>mem) && i<monsters.size()) {
        weak ++;
        i ++;
    }
    mem = monsters[i];

    while (i<monsters.size()) {

        while(!(monsters[i]>mem) && i<monsters.size()) {
            strong ++;
            i++;
        }
        mem = monsters[i];

        if (strong>=weak) {
            weak = strong;
        }
        strong =0;

    }


    cout << weak << endl;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
