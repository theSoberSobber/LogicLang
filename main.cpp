#include <iostream>
#include <cstdlib>
#include <memory>
#include <cstring>

#define DEBUG_ALL

#ifdef DEBUG_ALL
#define DEBUG_LEXER
#define DEBUG_PARSER
#endif

#include "lexer.h"

struct arg {
    std::string inputPath;
    arg(std::string inp) : inputPath(inp) {}
};

void printHelp() {
    std::cout << std::endl;
    std::cout << "lgcc.exe Usage:" << std::endl
              << std::endl;
    std::cout << "\t lgcc.exe -i <inputFilePath>" << std::endl;
}

arg parseArg(int argc, char **argv) {
    if (argc == 3 && !strcmp(argv[1], "-i")) return arg(argv[2]);
    printHelp();
    exit(0);
}

int main(int argc, char **argv){
    arg argInfo = parseArg(argc, argv);

    std::unique_ptr<lexer> codeParser = std::make_unique<lexer>(argInfo.inputPath);
    codeParser->scan();

    #ifdef DEBUG_LEXER
    codeParser->printTokenList();
    #endif
    return 0;
}