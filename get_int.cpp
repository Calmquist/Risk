#include "get_int.h"

int get_int() {

    int n = 0;
    std::string s;
    std::istringstream strm;

    std::cin >> s;

    // Ensures that a false 0 is not returned if a non-number is inputted.
    if(!isdigit(s[0])) {
        return INT_MIN;
    }

    strm.str(s);

    strm >> n;
    return n;
}
