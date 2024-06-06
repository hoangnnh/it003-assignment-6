#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> get_ans(const vector<int> &ids, int &count) {

    map<int, int> Hash;
    for (auto const &id: ids) {
        if (Hash.find(id) != Hash.end())
            Hash[id] += 1;
        else
            Hash.insert({id, 1});
    }

    count = static_cast<int>(Hash.size());

    vector<int> ans;
    for (auto const &data: Hash) {
        ans.push_back(data.first);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> ids(N);

    for (int i = 0; i < N; i++) cin >> ids[i];

    vector<int> ans;
    int count = 0;

    ans = get_ans(ids, count);

    cout << count << "\n";
    for (auto const &num: ans) {
        cout << num << " ";
    }

    return 0;
}