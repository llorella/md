#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> extractCodeBlocks(const string& content) {
    vector<string> blocks;
    size_t start = 0;
    const string delimiterStart = "```";
    const string delimiterEnd = "\n";
    
    while ((start = content.find(delimiterStart, start)) != string::npos) {
        start += delimiterStart.length(); 
        
        size_t endOfLang = content.find(delimiterEnd, start);
        if (endOfLang != string::npos) {
            start = endOfLang + delimiterEnd.length();
        }
        
        size_t end = content.find(delimiterStart, start);
        if (end == string::npos) break; 
        blocks.push_back(content.substr(start, end - start));
        start = end + delimiterStart.length();
    }
    return blocks;
}

int main(int argc, char* argv[]) {
    string content;
    int index = -1; 
    
    if (argc > 1) index = stoi(argv[1]); 

    content.assign((istreambuf_iterator<char>(cin)), (istreambuf_iterator<char>()));
    
    auto blocks = extractCodeBlocks(content);
    
    if (blocks.empty()) {
        cerr << "No code blocks found." << endl;
        return 1;
    }

    if (index == -1 || index > static_cast<int>(blocks.size())) {
        cout << blocks.back(); 
    } else {
        int adjustedIndex = (index <= 0) ? static_cast<int>(blocks.size()) - 1 : index - 1;
        if (adjustedIndex >= 0 && adjustedIndex < static_cast<int>(blocks.size())) {
            cout << blocks[adjustedIndex];
        } else {
            cerr << "Code block index out of range." << endl;
            return 1;
        }
    }
    
    return 0;
}