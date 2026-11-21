#include <bits/stdc++.h>

//EDIT THE CLASS
class box {
    public:
        virtual int foo() { return 0; }
};

class whitebox : public box {
    public: 
        int foo() override { return 1; }
        int foo(const int a) { return a + 1; }
};

int main() {

    whitebox wb;
    box& b = wb;
    b.foo();   // returns 1 through the base reference
    wb.foo(2);  // returns 3 through the whitebox overload

    return 0;
}