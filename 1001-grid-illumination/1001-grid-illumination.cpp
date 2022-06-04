class Solution {
public:
   vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
  vector<int> res;
  unordered_map<int, int> x, y, a_d, d_d;
  unordered_map<int, unordered_set<int>> ls;
  for (auto l : lamps) {
    auto i = l[0], j = l[1];
    if (ls[i].insert(j).second) ++x[i], ++y[j], ++a_d[i + j], ++d_d[i - j];
  }
  for (auto q : queries) {
    auto i = q[0], j = q[1];
    if (x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
      res.push_back(1);
      for (auto li = i - 1; li <= i + 1; ++li)
        for (auto lj = j - 1; lj <= j + 1; ++lj){
          if (ls[li].erase(lj)) {
            --x[li], --y[lj], --a_d[li + lj], --d_d[li - lj];
          }
      }
    }
    else res.push_back(0);
  }
  return res;
}
};

// 0 -1
// 0 1
// 1 0
// -1 0
// 1 1
// -1 -1
// -1 1
// 1 -1