class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        int slow = a[0], fast = a[0];
        do {
            slow = a[slow];
            fast = a[a[fast]];
        }while(slow != fast);
        fast = a[0];
        while(slow != fast) {
            slow = a[slow];
            fast = a[fast];
        }
        return slow;
    }
};

// 1 3 4 2 2
// 0 1 2 3 4