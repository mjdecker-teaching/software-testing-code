/**
 * @file main.cpp
 *
 * Test a palindrome function
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cassert>

#include "palindrome.hpp"

int main(int argc, char * argv[]) {

    {
	assert(is_palindrome(""));
    }

    {
	assert(!is_palindrome("ab"));
    }

    {
	assert(is_palindrome("aa"));
    }

    {
	assert(!is_palindrome("abca"));
    }

    // other possible tests odd length
    // do spaces matter, our tests show this.
    // ???

    return 0;
}
