class MKAverage {
public:
    const int nax = 1e5 + 1;
    vector<int> arr;
    vector<pair<long long, long long>> tree;
    long long total = 0;
    int size;
    int m, k;
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        size = 1;
        while (size < nax) {
            size *= 2;
        }
        tree = vector<pair<long long, long long>> (2 * size - 1);
    }
    void operation(int pos, bool flag) {
        if (flag) {
            tree[pos + size - 1].first -= pos;
            --tree[pos + size - 1].second;
        }
        else {
            tree[pos + size - 1].first += pos;
            ++tree[pos + size - 1].second;
        }
        for (int i = (size - 1 + pos - 1) / 2; i > 0; i = (i - 1) / 2) {
            tree[i].first = tree[2 * i + 1].first + tree[2 * i + 2].first;
            tree[i].second = tree[2 * i + 1].second + tree[2 * i + 2].second;
        }
        if (size != 1) {
            tree[0].first = tree[1].first + tree[2].first;
            tree[0].second = tree[1].second + tree[2].second;
        }
    }
   int sum(int root, int l, int r, int left, int right, bool flag) {
        if (right < l || left > r) return 0;
        if (left >= l && right <= r) {
            if (flag) {
                return tree[root].second;
            }
            else {
                return tree[root].first;
            }
        }
        int mid = (left + right) / 2;
        return sum(2 * root + 1, l, r, left, mid, flag) + sum(2 * root + 2, l, r, mid + 1, right, flag);
    }
    int getValue(int total, bool flag) {
        int low = 0;
        int high = nax;
        int sol = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = 0;
            if (flag) {
                val = sum(0, 0, mid, 0, size - 1, true);
            }
            else {
                val = sum(0, mid, size - 1, 0, size - 1, true);
            }
            if (val >= total) {
                sol = mid;
                if (flag) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (flag) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return sol;
    }
    void addElement(int num) {
        arr.push_back(num);
        if ((int) arr.size() > m) {
            operation(arr.end()[-m - 1], true);
        }
        operation(arr.end()[-1], false);
    }
    int getFreq(int value) {
        return tree[value + size - 1].second;
    }
    int calculateMKAverage() {
        if ((int) arr.size() < m) return -1;
        int v1 = getValue(k, true);
        int v2 = getValue(k, false);
        long long total = sum(0, v1, v2, 0, size - 1, false);
        int l = k - sum(0, 0, v1 - 1, 0, size - 1, true);
        int r = k - sum(0, v2 + 1, size - 1, 0, size - 1, true);
        long long div = m - 2 * k;
        total -= v1 * l;
        total -= v2 * r;
        return total / div;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */