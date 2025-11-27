#include <iostream>
#include <vector>

using namespace std;

int order = 0;
int numOfSave = 100000000;
void merge_sort(vector<int>& target_array, int left, int right);
void merge(vector<int>& target_array, int left, int mid, int right);


int main() {
    int sizeOfArray = 500000;

    cin >> sizeOfArray >> numOfSave;
    vector<int> arr(sizeOfArray);
    for (int i = 0 ; i < arr.size() ; i ++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, sizeOfArray - 1);
    if (order < numOfSave) {
        cout << -1;
    }
    return 0;
}

void merge_sort(vector<int>& target_array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(target_array, left, mid);
        merge_sort(target_array, mid + 1, right);
        merge(target_array, left, mid, right);
    }
}

void merge(vector<int>& target_array, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (target_array[i] <= target_array[j]) {
            temp.push_back(target_array[i]);
            i++;
        }
        else {
            temp.push_back(target_array[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(target_array[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(target_array[j]);
        j++;
    }
    for (int i = left ; i <= right ; i++) {
        target_array[i] = temp[i - left];
        order++;
        if (order == numOfSave) {
            cout << temp[i - left];
        }
    }
}