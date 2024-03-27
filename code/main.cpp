/* Name: Kaighla VanSant_ cs 135_ lab 6a
description: outputs the min max average sum of the numbers in the file
input: file name
output: information
*/
#include <iostream>
#include <fstream>
#include <climits> // Include this for INT_MAX and INT_MIN
using namespace std;

int main() {
    const int arraySize = 10;
    int arr[arraySize];
    ifstream iFile;
    string inputFileName = " ";

    do {
        cout << "Enter file name" << endl;
        cout << "**";
        getline(cin, inputFileName);
        iFile.open(inputFileName);
        cout << endl;

        if (iFile.fail()) {
            iFile.clear();
            iFile.ignore();
            cout << "Error: Invalid file name" << endl;
            continue;
        }
    } while (!iFile.is_open());

    int cnt = 0;
    int sum = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    while (cnt < arraySize && iFile >> arr[cnt]) {
        if (!iFile) {
            if (!iFile.eof()) {
                iFile.clear();
                iFile.ignore(100, '\n');
                cout << "Error: Invalid input in file\n";
                cout << endl;
            }
            continue;
        }

        sum += arr[cnt];

        if (arr[cnt] < minVal) {
            minVal = arr[cnt];
        }

        if (arr[cnt] > maxVal) {
            maxVal = arr[cnt];
        }

        cnt++;
    }

    iFile.close();

    cout << "Amount of Elements Read In: " << cnt << endl;
    cout << "Forward: ";
    for (int i = 0; i < cnt; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Backward: ";
    for (int i = cnt - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (cnt > 0) {
        cout << "Min: " << minVal << endl;
        cout << "Max: " << maxVal << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << static_cast<double>(sum) / cnt << endl;
    } else {
        cout << "No valid data to calculate statistics." << endl;
    }

    return 0;
}