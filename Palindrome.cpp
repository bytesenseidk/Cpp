#include <string>
using namespace std;

class IsPalindrome {
public:
    int num;
    explicit IsPalindrome(int n) {
        num = n;
    }
    void setNum(int n) {
        num = n;
    }

    string palindrome() {
        bool res = check(num);
        string number = to_string(num);
        if (res) {
            return number + " is a palindrome!";
        }
        return number + " is not a palindrome!";
    }

private:
    bool check(int) const {
        string numStr = to_string(num);
        unsigned int numLen = numStr.length() - 1;

        for (int i = 0; i < numLen; i++) {
            if (numStr[i] != numStr[numLen]) {
                return false;
            }
            --numLen;
        }
        return true;
    }
};