#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ifstream file("input2.txt");

    vector<vector<int>> allRows;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int number;

        while (ss >> number) {
            row.push_back(number);
        }

        allRows.push_back(row);
    }

    // Part 1
    int safes = 0;
    for (vector<int> row : allRows){
        // jaki = 0 - rosnący, jaki = 1 - malejący, jaki = -1 inny (unsafe)
        int jaki; 
        if (row[0] + 3 >= row[1] && row[0] < row[1]){
            jaki = 0;
        }
        else if (row[0] > row[1] && row[0] <= row[1] + 3){
            jaki = 1;
        }
        else{
            continue;
        }
        for (int i = 1; i < row.size() - 1; i++){
            if (row[i+1] <= row[i] + 3 && row[i+1] > row[i] && jaki == 0){ // kolejny większy - rosnący
                continue;
            }
            if (row[i+1] + 3 >= row[i]  && row[i+1] < row[i] && jaki == 1){ // kolejny mniejszy - malejący
                continue;
            }
            else{
                jaki = -1;
                break;
            }
        }
        if (jaki == 0 || jaki == 1){
            safes++;
        }
    }
    cout<<safes;
}