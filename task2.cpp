
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int> &A, int K) {
    map<int, int> Hash;
    vector<int> ans;

    for (const auto &num: A) {
        if (Hash.find(num) != Hash.end())
            Hash[num] += 1;
        else
            Hash.insert({num, 1});
    }

    int d = k - Hash.size();

    if (d == 0) {
        for (const auto &data: Hash)
            ans.push_back(data.first);
    } else if (d < 0) {
        for (int i = 0; i < k; i++)
            ans.push_back(Hash.at(i));
    } else {
        for (const auto &data: Hash) {
            ans.push_back(data.first);
            Hash[data.first] = data.second - 1;
            while (Hash[data.first] != 0 && d != 0) {
                ans.push_back(data.first);
                Hash[data.first] = data.second - 1;
                d--;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x: ans) cout << x << ' ';
    return 0;
}
