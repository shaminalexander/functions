/******************
* Шамин Александр *
* ПИ-261          *
* Вариант 35      *
*******************/

#include <iostream>

using namespace std;

bool calculatePositiveAverage(const double values[], int count, double& average) {
    double positiveSum = 0.0;
    int positiveCount = 0;

    for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
        if (values[elementIndex] > 0.0) {
            positiveSum += values[elementIndex];
            ++positiveCount;
        }
    }

    if (positiveCount == 0) {
        average = 0.0;
        return false;
    }

    average = positiveSum / positiveCount;
    return true;
}

void replaceNegativeElements(double values[], int count, double average) {
    for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
        if (values[elementIndex] < 0.0) {
            values[elementIndex] = average;
        }
    }
}

int main() {
    constexpr int maxArraySize = 100;
    constexpr double maxElementMagnitude = 1000.0;

    int sizeS;
    int sizeD;

    double arrayS[maxArraySize];
    double arrayD[maxArraySize];

    double averageS;
    double averageD;

    bool hasPositiveS;
    bool hasPositiveD;

    cout << "Enter sizes of arrays S and D: ";
    cin >> sizeS >> sizeD;

    if (sizeS < 1 || sizeS > maxArraySize ||
        sizeD < 1 || sizeD > maxArraySize) {
        cout << "INVALID";
        return 0;
    }

    cout << "Enter elements of array S:" << endl;
    for (int elementIndex = 0; elementIndex < sizeS; ++elementIndex) {
        cin >> arrayS[elementIndex];

        if (arrayS[elementIndex] < -maxElementMagnitude ||
            arrayS[elementIndex] > maxElementMagnitude) {
            cout << "INVALID";
            return 0;
        }
    }

    cout << "Enter elements of array D:" << endl;
    for (int elementIndex = 0; elementIndex < sizeD; ++elementIndex) {
        cin >> arrayD[elementIndex];

        if (arrayD[elementIndex] < -maxElementMagnitude ||
            arrayD[elementIndex] > maxElementMagnitude) {
            cout << "INVALID";
            return 0;
        }
    }

    cout << "\nOriginal array S: ";
    for (int elementIndex = 0; elementIndex < sizeS; ++elementIndex) {
        cout << arrayS[elementIndex] << " ";
    }

    cout << "\nOriginal array D: ";
    for (int elementIndex = 0; elementIndex < sizeD; ++elementIndex) {
        cout << arrayD[elementIndex] << " ";
    }

    hasPositiveS = calculatePositiveAverage(arrayS, sizeS, averageS);
    hasPositiveD = calculatePositiveAverage(arrayD, sizeD, averageD);

    if (hasPositiveS) {
        replaceNegativeElements(arrayS, sizeS, averageS);
    }

    if (hasPositiveD) {
        replaceNegativeElements(arrayD, sizeD, averageD);
    }

    cout << "\n\nModified array S: ";
    for (int elementIndex = 0; elementIndex < sizeS; ++elementIndex) {
        cout << arrayS[elementIndex] << " ";
    }

    cout << "\nModified array D: ";
    for (int elementIndex = 0; elementIndex < sizeD; ++elementIndex) {
        cout << arrayD[elementIndex] << " ";
    }

    return 0;
}
