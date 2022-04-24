// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int a[], int b[], int n) {
        map<int, int> X;

    // To store Frequency of all distinct Yi
    map<int, int> Y;

    // To store Frequency of all distinct
    // points (Xi, Yi);
    map<pair<int, int>, int> XY;

    for (int i = 0; i < n; i++) {
        int xi = a[i];
        int yi = b[i];

        // Hash xi coordinate
        X[xi]++;

        // Hash yi coordinate
        Y[yi]++;

        // Hash the point (xi, yi)
        XY[{a[i],b[i]}]++;
    }

    int xAns = 0, yAns = 0, xyAns = 0;

    // find pairs with same Xi
    for (auto xCoordinatePair : X) {
        int xFrequency = xCoordinatePair.second;

        // calculate ((xFrequency) C2)
        int sameXPairs
            = (xFrequency * (xFrequency - 1)) / 2;
        xAns += sameXPairs;
    }

    // find pairs with same Yi
    for (auto yCoordinatePair : Y) {
        int yFrequency = yCoordinatePair.second;

        // calculate ((yFrequency) C2)
        int sameYPairs
            = (yFrequency * (yFrequency - 1)) / 2;
        yAns += sameYPairs;
    }

    // find pairs with same (Xi, Yi)
    for (auto XYPair : XY) {
        int xyFrequency = XYPair.second;

        // calculate ((xyFrequency) C2)
        int samePointPairs
            = (xyFrequency * (xyFrequency - 1)) / 2;
        xyAns += samePointPairs;
    }

    return (xAns + yAns - (2 * xyAns));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends