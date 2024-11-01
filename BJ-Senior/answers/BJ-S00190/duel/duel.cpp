#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int min_surviving_monsters(const vector<int>& monsters) {
    int n = monsters.size();
    vector<bool> survived(n, true); // 记录怪兽是否存活
    int count = 0;

    // 对怪兽的攻击力/防御力排序
    vector<int> sorted_monsters = monsters;
    sort(sorted_monsters.begin(), sorted_monsters.end());

    // 从攻击力高到低遍历
    for (int i = n - 1; i >= 0; --i) {
        if (survived[i]) { // 如果当前怪兽还在场
            for (int j = i - 1; j >= 0; --j) {
                if (survived[j] && sorted_monsters[i] > sorted_monsters[j]) { // 当前怪兽攻击目标怪兽
                    survived[j] = false; // 目标怪兽退出
                    break; // 一次攻击结束
                }
            }
        }
    }

    // 统计剩下的怪兽数量
    for (int i = 0; i < n; ++i) {
        if (survived[i]) count++;
    }
    return count;
}

int main() {
    ifstream infile("duel.in");
    ofstream outfile("duel.out");

    int n;
    infile >> n;
    vector<int> monsters(n);
    for (int i = 0; i < n; ++i) {
        infile >> monsters[i];
    }

    int result = min_surviving_monsters(monsters);
    outfile << result << endl;

    return 0;
}