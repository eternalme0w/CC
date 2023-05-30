#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

bool isTimeFormatValid(const string& input) {

    regex timeRegex(R"(^([01]\d|2[0-3]):[0-5]\d:[0-5]\d$)");
    return regex_match(input, timeRegex);
}

bool isVariableName(const string& str) {

    regex variableNameRegex("^[a-zA-Z_][a-zA-Z0-9_]{0,63}$");
    return regex_match(str, variableNameRegex);
    
}

void out(ifstream& file, bool (*regExFunc)(const string&)) {

    string line;

    while (getline(file, line)) {

        if (regExFunc(line)) 
            cout << line << " +" << endl;
         else 
            cout << line << " -" << endl;
    }

}

void findSentences(const string& text, vector<string>& sentences) {


    regex sentenceRegex(R"([A-Z][^.!?]*[.!?])");

    smatch match;
    string::const_iterator textIt = text.cbegin();


    while (regex_search(textIt, text.cend(), match, sentenceRegex)) {
        sentences.push_back(match.str());
        textIt = match.suffix().first;
    }
}

void printSentences(ifstream& file) {

    string line;
    vector<string> sentences;

    while (getline(file, line))
        findSentences(line, sentences);

    for (string s : sentences)
        cout << s << "\n";
    
}

string fixIncorrectCommas(const string& str) {

    regex commaRegex(R"((\s+,\s*|,\s{2,}|,(?=[^\s])))");
    string result = regex_replace(str, commaRegex, ", ");
    return result;
}

void printFixedCommas(ifstream& file) {

    string line;
    string result;

    while (getline(file, line)) {

        result = fixIncorrectCommas(line);
        cout << line << " fixed: " << result << "\n";
    }

}

int main() {

    ifstream timeData("time.txt");
    ifstream sentencesData("sentences.txt");
    ifstream variablesData("variables.txt");
    ifstream commasData("commas.txt");

    //out(timeData, isTimeFormatValid);
    //printSentences(sentencesData);
    //out(variablesData, isVariableName);


    printFixedCommas(commasData);



    timeData.close();

    return 0;
}