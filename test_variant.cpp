#include <variant>
#include <string>

int main() {
    std::variant<int, std::string> v = "hello";
    std::string s = "hello";
    bool b = (v == s);
    return 0;
}
