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

    // Part 2
    vector<vector<bool>> middle(lines.size(), vector<bool>(lines[0].size(), false)); 
    string target2 = "MAS";
    string target3 = "SAM";
    int suma2 = 0;
    string temp = "";
     for (int row = 0; row < lines.size(); row++){
        for (int col = 0; col < lines[0].size(); col++){
            if (lines[row][col] == 'M'){
                
                // lewy-gorny kwadrat
                if (row - 2 >= 0 && col - 2 >= 0){
                    if (lines[row-1][col-1] == 'A' && lines[row-2][col-2] == 'S' && !middle[row-1][col-1]){
                        temp.push_back(lines[row-2][col]);
                        temp.push_back(lines[row-1][col-1]);
                        temp.push_back(lines[row][col-2]); 
                        if (temp == target2 || temp == target3){
                            middle[row-1][col-1] = true;
                            suma2++;
                        }
                        temp = "";
                    }
                }

                // prawy-gorny kwadrat
                if (row - 2 >= 0 && col + 2 < lines[row].size()){
                    if (lines[row-1][col+1] == 'A' && lines[row-2][col+2] == 'S' && !middle[row-1][col+1]){
                        temp.push_back(lines[row-2][col]);
                        temp.push_back(lines[row-1][col+1]);
                        temp.push_back(lines[row][col+2]); 
                        if (temp == target2 || temp == target3){
                            middle[row-1][col+1] = true;
                            suma2++;
                        }
                        temp = "";
                    }
                }

                // lewy-dolny kwadrat
                if (row + 2 < lines.size() && col - 2 >= 0){
                    if (lines[row+1][col-1] == 'A' && lines[row+2][col-2] == 'S' && !middle[row+1][col-1]){
                        temp.push_back(lines[row+2][col]);
                        temp.push_back(lines[row+1][col-1]);
                        temp.push_back(lines[row][col-2]); 
                        if (temp == target2 || temp == target3){
                            middle[row+1][col-1] = true;
                            suma2++;
                        }
                        temp = "";
                    }
                }

                // prawy-dolny kwadrat
                if (row + 2 < lines.size() && col + 2 < lines[row].size() ){
                    if (lines[row+1][col+1] == 'A' && lines[row+2][col+2] == 'S' && !middle[row+1][col+1]){
                        temp.push_back(lines[row+2][col]);
                        temp.push_back(lines[row+1][col+1]);
                        temp.push_back(lines[row][col+2]); 
                        if (temp == target2 || temp == target3){
                            middle[row+1][col+1] = true;
                            suma2++;
                        }
                        temp = "";
                    }
                }
            }
        }
    }
    cout<<suma<<endl;
    cout<<suma2<<endl;
}