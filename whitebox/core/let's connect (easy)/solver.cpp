#include <bits/stdc++.h>

class Connect4Bot {
public:

    int move(const Board board) {
        std::srand(std::time(0));

        return std::rand() % (6);
    }

};