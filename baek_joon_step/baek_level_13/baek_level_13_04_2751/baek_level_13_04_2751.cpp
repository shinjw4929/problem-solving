#include <iostream>
#include <vector>


using namespace std;

vector<int> mergesort(vector<int> arr);
vector<int> merge(vector<int> arr1, vector<int> arr2);


int main() {
    vector<int> v;
    int size;
    cin >> size;
    for(int i = 0 ; i < size ; i++) {
        int input;//로컬변수로 input넣음
        cin >> input;
        v.push_back(input);
    }

    v = mergesort(v);


    for(int i = 0 ; i < size ; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}


vector<int> mergesort(vector<int> arr) {
    int size = arr.size();
    vector<int> arr1(arr.begin(), arr.begin() + size / 2);
    vector<int> arr2(arr.begin() + size / 2, arr.end());
    if(arr1.size() != 1) {
        arr1 = mergesort(arr1);
    }
    if(arr2.size() != 1) {
        arr2 = mergesort(arr2);
    }
    arr = merge(arr1, arr2);
    return arr;
}

vector<int> merge(vector<int> arr1, vector<int> arr2) {
    int size = arr1.size() + arr2.size();
    int i = 0, j = 0;
    vector<int> merged(size);
    for(int idx = 0 ; idx < size ; idx++) {
        if(i == arr1.size()) {
            merged[idx] = arr2[j];
            j++;
        }
        else if(j == arr2.size()) {
            merged[idx] = arr1[i];
            i++;
        }
        else if(arr1[i] <= arr2[j]) {
            merged[idx] = arr1[i];
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            merged[idx] = arr2[j];
            j++;
        }
    }
    return merged;
}