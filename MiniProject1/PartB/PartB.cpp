#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    void GenerateSwaps() {
        swaps_.clear();
        // Starting from the middle of the array, we iterate backwards 
        // and sift down each element to its correct position in the heap
        for (int i = data_.size() / 2; i >= 0; --i) {
            SiftDown(i);
        }
    }

    void SiftDown(int i) {
        int minIndex = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < data_.size() && data_[leftChild] < data_[minIndex]) {
            minIndex = leftChild;
        }
        if (rightChild < data_.size() && data_[rightChild] < data_[minIndex]) {
            minIndex = rightChild;
        }
        if (i != minIndex) {
            swap(data_[i], data_[minIndex]);
            swaps_.push_back(make_pair(i, minIndex));
            SiftDown(minIndex);
        }
    }


public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
