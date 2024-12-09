#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int countPatternOccurrences(const string& text, const string& pattern) {
    int textLength = text.size();
    int patternLength = pattern.size();
    int count = 0;

    for (int i = 0; i <= textLength - patternLength; ++i) {
        bool match = true;
        for (int j = 0; j < patternLength; ++j) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            ++count;
        }
    }

    return count;
}

int main(){
    ifstream file("input4.txt");
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    string target = "MAS";
    int suma = 0;

    for (int row = 0; row < lines.size(); row++){
        for (int col = 0; col < lines[0].size(); col++){
            if (lines[row][col] == 'X'){
                string rest = "";
                // w prawo
                if (col + 3 < lines[0].size()){
                    rest.push_back(lines[row][col+1]);
                    rest.push_back(lines[row][col+2]);
                    rest.push_back(lines[row][col+3]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // prawa góra
                if (col + 3 < lines[0].size() && row - 3 >= 0){
                    rest.push_back(lines[row-1][col+1]);
                    rest.push_back(lines[row-2][col+2]);
                    rest.push_back(lines[row-3][col+3]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // prawy dol
                if (col + 3 < lines[0].size() && row + 3 < lines.size()){
                    rest.push_back(lines[row+1][col+1]);
                    rest.push_back(lines[row+2][col+2]);
                    rest.push_back(lines[row+3][col+3]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // dol
                if (row + 3 < lines.size()){
                    rest.push_back(lines[row+1][col]);
                    rest.push_back(lines[row+2][col]);
                    rest.push_back(lines[row+3][col]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // gora
                if (row - 3 >= 0){
                    rest.push_back(lines[row-1][col]);
                    rest.push_back(lines[row-2][col]);
                    rest.push_back(lines[row-3][col]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // lewo
                if (col - 3 >= 0){
                    rest.push_back(lines[row][col-1]);
                    rest.push_back(lines[row][col-2]);
                    rest.push_back(lines[row][col-3]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // lewa gora
                if (row - 3 >= 0 && col-3 >= 0){
                    rest.push_back(lines[row-1][col-1]);
                    rest.push_back(lines[row-2][col-2]);
                    rest.push_back(lines[row-3][col-3]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }

                // lewy dol
                if (row + 3 < lines.size() && col - 3 >= 0){
                    rest.push_back(lines[row+1][col-1]);
                    rest.push_back(lines[row+2][col-2]);
                    rest.push_back(lines[row+3][col-3]);
                    if (rest == target){
                        suma++;
                    }
                    rest = "";
                }
            }
        }
    }

    cout<<suma<<endl;
}