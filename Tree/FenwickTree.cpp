#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        idx++; // 1-based index
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++; // 1-based index
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();

    FenwickTree ft(n);
    for (int i = 0; i < n; i++) {
        ft.update(i, arr[i]);
    }

    cout << "Sum from index 1 to 3: " << ft.rangeQuery(1, 3) << endl;

    ft.update(1, 7); // adds 7 to arr[1] = 3 -> 10
    cout << "After update: Sum from index 1 to 3: " << ft.rangeQuery(1, 3) << endl;

    return 0;
}

/*
Time Complexity:
- Update: O(log n)
- Query: O(log n)
Space Complexity: O(n)
✅ Use : Fast prefix sums, point updates (no range update support directly)
*/
