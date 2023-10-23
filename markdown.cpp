#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <regex>
#include <limits> // Included for std::numeric_limits

std::map<std::string, std::string> codeBlockExtensions = {
        {"shell", ".sh"},
        {"python", ".py"},
        {"c", ".c"},
        {"c++", ".cpp"},
        {"javascript", ".js"},
        {"go", ".go"},
        {"latex", ".tex"},
        {"makefile", "Makefile"},
        {"html", ".html"},
        {"css", ".css"},
        {"java", ".java"},
        {"json", ".json"},
        {"markdown", ".md"},
        {"php", ".php"},
        {"ruby", ".rb"},
        {"rust", ".rs"},
        {"sql", ".sql"},
        {"xml", ".xml"},
        {"yaml", ".yaml"}
        // Add more as needed
    };

struct CodeBlock {
    std::string type;
    std::string code;
};

std::vector<CodeBlock> parseCodeBlocks(std::istream& input) {
    static const std::regex codeBlockPattern(R"(^```([a-zA-Z]*)$)");
    std::vector<CodeBlock> codeBlocks;
    std::string line;
    bool inCodeBlock = false;
    CodeBlock currentBlock;

    while (std::getline(input, line)) {
        std::smatch match;
        if (std::regex_match(line, match, codeBlockPattern)) {
            if (inCodeBlock) {
                codeBlocks.push_back(currentBlock);
                inCodeBlock = false;
            } else {
                inCodeBlock = true;
                currentBlock.type = match[1];
                currentBlock.code.clear();
            }
        } else if (inCodeBlock) {
            currentBlock.code += line;
            currentBlock.code.push_back('\n');
        }
    }
    
    if (inCodeBlock) {
        codeBlocks.push_back(currentBlock);
    }

    return codeBlocks;
}

int selectCodeBlock(const std::vector<CodeBlock>& matchingBlocks) {
    int choice = -1;
    while (true) {
        std::cout << "Matching code blocks found. Select one to proceed:\n";
        for (int i = 0; i < matchingBlocks.size(); ++i) {
            std::cout << (i + 1) << ". " << matchingBlocks[i].code << '\n';
        }
        std::cout << "Enter the number of the code block you want to use: ";
        std::cin >> choice;
        if (std::cin && choice >= 1 && choice <= matchingBlocks.size()) {
            return choice;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Fixed line
        std::cerr << "Invalid choice. Please try again.\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <type>\n", argv[0]);
        return 1;
    }

    std::string type = argv[1];
    std::vector<CodeBlock> codeBlocks = parseCodeBlocks(std::cin);

    std::vector<CodeBlock> matchingBlocks;
    auto it = codeBlockExtensions.end();  // Declare iterator for later use
    for (const CodeBlock& block : codeBlocks) {
        it = codeBlockExtensions.find(block.type);  // Store the iterator
        if (block.type == type || it == codeBlockExtensions.end()) {
            matchingBlocks.push_back(block);
        }
    }

    if (matchingBlocks.empty()) {
        std::cerr << "No matching code blocks found.\n";
        return 1;
    }

    int choice = selectCodeBlock(matchingBlocks);
    std::string code = matchingBlocks[choice - 1].code;

    // Reuse the iterator to prevent a second map lookup
    if (it == codeBlockExtensions.end()) {
        std::string extension;
        std::cout << "Unknown code block type. Please enter a file extension: ";
        std::cin >> extension;
        codeBlockExtensions[matchingBlocks[choice - 1].type] = extension;
    }

    std::cout << code;

    return 0;
}
