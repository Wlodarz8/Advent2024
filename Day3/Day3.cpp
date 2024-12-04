#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;

int main(){
    ifstream file("input3.txt");

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
    file.close();

    regex pattern(R"(mul\((\d+),(\d+)\))");
    sregex_iterator currentMatch(content.begin(), content.end(), pattern);
    sregex_iterator endMatch;

    int suma = 0;

    while (currentMatch != endMatch) {
        smatch match = *currentMatch;

        int int1 = stoi(match[1].str());
        int int2 = stoi(match[2].str());

        suma += int1 * int2;

        currentMatch++;
    }
    
    regex dontDoPattern(R"(don't\(\)[\s\S]*?do\(\))");
    content = regex_replace(content, dontDoPattern, "");
    sregex_iterator currentMatch2(content.begin(), content.end(), pattern);

    int suma2 = 0;

    while (currentMatch2 != endMatch) {
        smatch match = *currentMatch2;

        int int1 = stoi(match[1].str());
        int int2 = stoi(match[2].str());

        suma2 += int1 * int2;

        currentMatch2++;
    }

    cout<<suma<<endl;
    cout<<suma2<<endl;
}