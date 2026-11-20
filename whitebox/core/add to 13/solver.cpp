#include <bits/stdc++.h>
using namespace std;

enum class cmd {
    addCmd,
    sub,
    mul,
    div,
    unknown
};

string formatResult(double val) {
    if (abs(val) < 1e-11) {
        val = 0.0;
    }

    ostringstream oss;
    oss << fixed << setprecision(2) << val;
    string s = oss.str();

    s.erase(s.find_last_not_of('0') + 1, string::npos);

    if (s.back() == '.') s.pop_back();

    return s;
}

cmd switchCmd(std::string_view str) {
    if (str == "+") return cmd::addCmd;
    if (str == "-") return cmd::sub;
    if (str == "*") return cmd::mul;
    if (str == "/") return cmd::div;
    return cmd::unknown;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(12);
    cout << fixed;

    int q;
    cin >> q;
    cin.ignore();

    std::variant<int, float> num1;
    std::variant<int, float> num2;
    string in = "", strnum1, strnum2, op;

    for (int i = 0; i < q; i++) {
        getline(cin, in);
        stringstream stream(in);

        stream >> strnum1 >> op >> strnum2;

        if (strnum1.find('.') != string::npos) {
            num1 = std::stof(strnum1);
        } else {
            num1 = std::stoi(strnum1);
        }

        if (strnum2.find('.') != string::npos) {
            num2 = std::stof(strnum2);
        } else {
            num2 = std::stoi(strnum2);
        }

        cout << setprecision(12);
        cout << fixed;

        std::visit([&](auto a, auto b) {
            switch (switchCmd(op)) {
                case cmd::addCmd: 
                    cout << formatResult(static_cast<double>(a) + b) << "\n"; 
                    break;
                case cmd::sub:    
                    cout << formatResult(static_cast<double>(a) - b) << "\n"; 
                    break;
                case cmd::mul:    
                    cout << formatResult(static_cast<double>(a) * b) << "\n"; 
                    break;
                case cmd::div:    
                    if (b == 0) cout << "Division by zero\n";
                    else cout << formatResult(static_cast<double>(a) / b) << "\n"; 
                    break;
                default: break;
            }
        }, num1, num2);

    }

    return 0;
}