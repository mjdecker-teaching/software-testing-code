/**
 * @file test_calculator.cpp
 *
 * Illustrate Turtle - Mocking Framework for Boost.Test
 */

#define BOOST_TEST_MODULE test calculator
#include <boost/test/included/unit_test.hpp>
#include <turtle/mock.hpp>

// Simple calculator return results
// class calculator_t {
// public:
//     int add(int a, int b) { return a + b; }
// };

// // Equally simple testing
// BOOST_AUTO_TEST_CASE( zero_plus_zero_is_zero )
// {
//     calculator_t c;
//     BOOST_CHECK_EQUAL( 0, c.add( 0, 0 ) );
// }

//...

class view_t {
public:
    virtual void display(int result) = 0;
};

// Now calculator displays results to a view
class calculator_t {
private:
    view_t & view;
public:
    calculator_t(view_t & view) : view(view) {}
    void add(int a, int b) { view.display(a + b); }
};

/*
 Instead of making a mock_view that checks if it is called with the 
 correct results, will use Turtle
 */
// declare a 'mock_view' class implementing 'view'
MOCK_BASE_CLASS(mock_view, view_t) {
    // implement the 'display' method from 'view' (taking 1 argument)
    MOCK_METHOD(display, 1);
};

BOOST_AUTO_TEST_CASE(zero_plus_zero_is_zero) {
    // create mock object
    mock_view view;

    // create object under test
    calculator_t calculator(view);

    // Set expectations
    // expect the 'display' method to be called once (and only once)
    // with a parameter value equal to 0
    MOCK_EXPECT(view.display).once().with(0);

    // excercise object under test
    calculator.add(0, 0);
} // verify mock object via destructor
