/**
 * @file .hpp
 *
 * This is a generic C++ header template.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */


#include "palindrome.hpp"

bool is_palindrome(const std::string & str) {
    if(str.size() < 2) return true;

    size_t front = 0;
    size_t back = str.size() - 1;
    while(front < back && str[front] == str[back]) {
	++front;
	--back;
    }
    return str[front] == str[back];
}
