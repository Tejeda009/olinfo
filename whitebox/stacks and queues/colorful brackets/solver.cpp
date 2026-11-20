#include <bits/stdc++.h>

bool isValid(std::string_view s) {
    std::map<char, char> opener = {{')', '('}, {']', '['}, {'>', '<'}};
    std::stack<char> waiting;

    for (char el : s) {
        if (opener.count(el)) {
            if (waiting.empty() || waiting.top() != opener[el]) {
                return false;
            }
            
            waiting.pop();
        } else {
            waiting.push(el);
        }
    }

    return waiting.empty();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string in;
    getline(std::cin, in);

    if (isValid(in)) {
        std::cout << "Yes\n";
    } else std::cout << "No\n";

    return 0;
}
