// Copyright 2018
// Author: LayerDE.
#include <string>
#include <vector>
#include <iostream>
#include "./Entity.h"
#include "./Wikidata.h"
std::vector<std::string> triple1{"Demo Entity", "place of birth", "C++"};
std::vector<std::string> triple2 {"Demo Entity", "cast member", "1"};
std::vector<std::string> triple3 {"Demo Entity", "cast member", "2"};
std::vector<std::string> triple4 {"Demo Entity", "cast member", "3"};

int main(int argc, char* argv[]) {
    Wikidata wd;
    int i;
    std::string userin;
    if (argc < 1) {
        wd.readFile(std::string(argv[1]));
    }
    if (wd._entities.size() == 0) {
        wd.readFile(std::string("WikidataTest.testfile"));
    }
looper:
    std::cin >> userin;
    if (!(userin.length() > 0))
        goto looper;
    std::vector<std::string>  tmp = wd.search(userin);
    i = 0;
    for (std::string x : tmp)
        if (i < 10)
            std::cout << (i++ + 1) << ": " << x << std::endl;
    goto looper;
}
