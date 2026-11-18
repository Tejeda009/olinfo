#include <bits/stdc++.h>

bool isPalindrome(std::string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        while (left < right && !std::isalnum(s[left])) {
            left++;
        }

        while (left < right && !std::isalnum(s[right])) {
            right--;
        }

        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    std::string in;
    getline(std::cin, in);
    std::cout << std::boolalpha;

    std::cout << isPalindrome(in) << '\n';


    return 0;
}