#include <iostream>
#include <string>

std::string LCS(const std::string& a, const std::string& b, int i, int j) {
    if (i == -1 || j == -1)
        return "";
    else if (i == j) {
        return LCS(a, b, i - 1, j - 1) + a[i];
    } else {
        std::string x = LCS(a, b, i - 1, j);
        std::string y = LCS(a, b, i, j - 1);
        return x.size() > y.size() ? x : y;
    }
}

int main(void) {
    std::string a, b;
    std::cin >> a >> b;

    std::cout << "LCS: " << LCS(a, b, a.size(), b.size());

    return 0;
}