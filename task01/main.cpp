#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void initializeArray(int* arr, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
}


string arrayToString(int* arr, int size) {
    string result = " ";
    for (int i = 0; i < size; i++) {
        result += to_string(arr[i]) + " ";
    }
    return result;
}


int findMinAbsValue(int* arr, int size) {
    if (size == 0) return 0;
    int minAbs = abs(arr[0]);
    int minValue = arr[0];
    for (int i = 1; i < size; i++) {
        int currentAbs = abs(arr[i]);
        if (currentAbs < minAbs) {
            minAbs = currentAbs;
            minValue = arr[i];
        }
    }
    return minValue;
}


int findMaxAbsValue(int* arr, int size) {
    if (size == 0) return 0;
    int maxAbs = abs(arr[0]);
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        int currentAbs = abs(arr[i]);
        if (currentAbs >= maxAbs) {
            maxAbs = currentAbs;
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int sumBetweenValues(int* arr, int size, int minValue, int maxValue) {
    int sum = 0;
    bool isBetween = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == minValue || arr[i] == maxValue) {
            isBetween = !isBetween;
            continue;
        }
        if (isBetween) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    

    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    int minVal, maxVal;

    cout << "Enter the minimum and maximum values for random initialization: ";
    cin >> minVal >> maxVal;

    if (minVal > maxVal) {
        int t = minVal;
        minVal = maxVal;
        maxVal = t;
    }

    int* arr = new int[size];
    initializeArray(arr, size, minVal, maxVal);

    cout << "Array: " << arrayToString(arr, size) << endl;

    int minValue = findMinAbsValue(arr, size);
    int maxValue = findMaxAbsValue(arr, size);

    int sum = sumBetweenValues(arr, size, minValue, maxValue);
    cout << "Sum between values " << minValue << " and " << maxValue << ": " << sum << endl;

    delete[] arr;
    return 0;
}