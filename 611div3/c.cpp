#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
int friends[200010];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> friends[i];
    unordered_set<int> connect;
    unordered_set<int> available;
    for (int i = 1; i <= N; i++) { available.insert(i); }
    for (int i = 0; i < N; i++) {
        if (friends[i] == 0)
            connect.insert(i + 1);
        else
            available.erase(friends[i]);
    }
    vector<int> same, diff, wait;
    for (const auto& it : connect) {
        if (available.count(it))
            same.push_back(it);
        else
            diff.push_back(it);
    }
    
    for (const auto& it : available) {
        if (!connect.count(it))
            wait.push_back(it);
    }


    for (int i = 0; i < same.size(); i++) {
        friends[same[i] - 1] = i == 0 ? same.back() : same[i - 1];
    }
    for (int i = 0; i < diff.size(); i++) {
        friends[diff[i] - 1] = wait[i];
    }
    if (same.size() == 1) {
        swap(friends[same[0] - 1], friends[diff[0] - 1]);
    }
    for (int i = 0; i < N; i++)
        cout << friends[i] << " ";
    return 0;
}