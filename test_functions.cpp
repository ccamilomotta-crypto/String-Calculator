#include <iostream>
#include "functions.h"
#include "test.h"

// TODO(student): declare other functions, as needed

void test_add() {
    assert_equal(add("1", "1"), "2");
    // TODO(student): add tests for add
    assert_equal(add("0", "0"), "0");
    assert_equal(add("0000", "000"), "0");
    assert_equal(add("9", "1"), "10");
    assert_equal(add("999", "1"), "1000");
    assert_equal(add("123", "77"), "200");
    assert_equal(add("00012", "003"), "15");
    assert_equal(add("-5", "-7"), "-12");
    assert_equal(add("5", "-2"), "3");
    assert_equal(add("-5", "2"), "-3");
    assert_equal(add("-5", "5"), "0");
}
// thr substr for loop
void test_subtract() {
    assert_equal(subtract("1", "1"), "0");
    // TODO(student): add tests for subtract
    assert_equal(subtract("0", "0"), "0");
    assert_equal(subtract("1000", "1"), "999");
    assert_equal(subtract("1", "1000"), "-999");
    assert_equal(subtract("5", "-2"), "7");
    assert_equal(subtract("-5", "2"), "-7");
    assert_equal(subtract("-5", "-2"), "-3");
    assert_equal(subtract("0002", "0005"), "-3");
}

void test_multiply() {
    assert_equal(multiply("1", "1"), "1");
    // TODO(student): add tests for multiply
    assert_equal(multiply("0", "123"), "0");
    assert_equal(multiply("0000", "999"), "0");
    assert_equal(multiply("12", "12"), "144");
    assert_equal(multiply("999", "999"), "998001");
    assert_equal(multiply("-12", "12"), "-144");
    assert_equal(multiply("-12", "-12"), "144");
    assert_equal(multiply("00012", "003"), "36");
    assert_equal(multiply("123456789", "987654321"), "121932631112635269");
}

// TODO(student): add tests for other functions, as needed

int main() {
    test_add();
    test_subtract();
    test_multiply();

    // TODO(student): invoke tests for other functions

    return 0;
}
