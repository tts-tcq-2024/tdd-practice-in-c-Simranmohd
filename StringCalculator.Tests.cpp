#include <stdio.h>
#include <assert.h>
#include "StringCalculator.h"

void testEmptyString() {
    assert(Add("") == 0);
}

void testOneNumber() {
    assert(Add("1") == 1);
}

void testTwoNumbers() {
    assert(Add("1,2") == 3);
}

void testMultipleNumbers() {
    assert(Add("1,2,3,4,5") == 15);
}

void testNewlineAsDelimiter() {
    assert(Add("1\n2,3") == 6);
}

void testCustomDelimiter() {
    assert(Add("//;\n1;2") == 3);
}

void runTests() {
    testEmptyString();
    testOneNumber();
    testTwoNumbers();
    testMultipleNumbers();
    testNewlineAsDelimiter();
    testCustomDelimiter();
    printf("All tests passed!\n");
}

int main() {
    runTests();
    return 0;
}
