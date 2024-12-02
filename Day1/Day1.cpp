#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ifstream file("input1.txt");

    vector<int> left;
    vector<int> right;

    int first, second;
    while (file >> first >> second) {
        left.push_back(first);
        right.push_back(second);
    }

    file.close();

    // Part 1
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int suma = 0;
    for (int i = 0; i < left.size(); i++){
        suma += abs(left[i] - right[i]);
    }

    cout << suma << endl;

    // Part 2
    int suma2 = 0;
    for (int i = 0; i < left.size(); i++){
        int lewy = left[i];
        int counter = 0;
        for (int j = 0; j < right.size(); j++){
            if (lewy == right[j]){
                counter++;
            }
        }
        suma2 += lewy * counter;
    }
    cout << suma2;
    return 0;
}