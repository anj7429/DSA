#include <iostream>
#include <vector>
using namespace std;

void sumOfSubsets(vector<int>& set, vector<int>& subset, int index, int n, int currSum, int target) {
    if (currSum == target) {
        cout << "Subset found: ";
        for (int val : subset)
            cout << val << " ";
        cout << endl;
        return;
    }

    if (currSum > target || index == n)
        return;

    // Include the current element
    subset.push_back(set[index]);
    sumOfSubsets(set, subset, index + 1, n, currSum + set[index], target);

    // Exclude the current element
    subset.pop_back();
    sumOfSubsets(set, subset, index + 1, n, currSum, target);
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> set[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;
    cout << "Subsets that sum to " << target << " are:\n";
    sumOfSubsets(set, subset, 0, n, 0, target);

    return 0;
}
