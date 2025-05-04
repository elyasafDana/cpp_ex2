//elidnana@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Mat.h"
#include <iostream>
#include <cassert>

using namespace pro;
using namespace std;

TEST_CASE("Basic Matrix Tests") {
    Mat m(3);
    m.initialize(2);

    CHECK(m.getSize() == 3);
    CHECK(m.getVal(0, 0) == 2);

    m.setVal(1, 1, 5);
    CHECK(m.getVal(1, 1) == 5);
}

TEST_CASE("Matrix Addition and Subtraction") {
    Mat a(2);
    a.initialize(1);

    Mat b(2);
    b.initialize(2);

    Mat c = a + b;
    CHECK(c.getVal(0, 0) == 3);
    CHECK(c.getVal(1, 1) == 3);


    a.initialize(1);
    b.initialize(2);

    Mat d = b - a;
    
    CHECK(d.getVal(0, 0) == 1);
    CHECK(d.getVal(1, 1) == 1);
}

TEST_CASE("Matrix Comparisons") {
    Mat a(2);
    a.initialize(3.5);

    Mat b(2);
    b.initialize(3.5);

    Mat c(2);
    c.initialize(1);

    CHECK(a == b);
    CHECK_FALSE(a == c);
    CHECK(c<a);
    CHECK(!(c>a));
}

TEST_CASE("Matrix Operators with Integers") {
    Mat m(2);
    m.initialize(3.5);

    Mat res = m * 2;
    CHECK(res.getVal(0, 0) == 7);
    CHECK(res.getVal(1, 1) == 7);

    res = 2 * m;
    CHECK(res.getVal(0, 0) == 7);
    CHECK(res.getVal(1, 1) == 7);

    res = m % 2;
    CHECK(res.getVal(0, 0) == 1.5);
    CHECK(res.getVal(1, 1) == 1.5);
}

TEST_CASE("Matrix Power Operator") {
    Mat identity(2);
    identity.initialize(0);
    identity.setVal(0, 0, 1);
    identity.setVal(1, 1, 1);

    Mat power = identity ^ 3;
    CHECK(power.getVal(0, 0) == 1);
    CHECK(power.getVal(1, 1) == 1);
}

TEST_CASE("Increment, Decrement, and Transposition Operators") {
    Mat m(2);
    m.initialize(1.1);

    ++m;
    CHECK(m.getVal(0, 0) == 2.1);
    CHECK(m.getVal(1, 1) == 2.1);

    m--;
    CHECK(m.getVal(0, 0) == 1.1);
    CHECK(m.getVal(1, 1) == 1.1);

    m.setVal(0, 1, 7);
    m.setVal(1, 0, 3);

    ~m;
    CHECK(m.getVal(0, 1) == 7);
    CHECK(m.getVal(1, 0) == 3);
}
bool isClose(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}
TEST_CASE("In-place Operator Tests +=, -=, *=, /=, %=")  {
    Mat m1(2);
    m1.initialize(1.1);

    Mat m2(2);
    m2.initialize(2.4);

    m1 += m2;
    CHECK(m1.getVal(0, 0) == 3.5);
    CHECK(m1.getVal(1, 1) == 3.5);

    m1.initialize(2.4);
    m2.initialize(1.1);

    

    m1 -= m2;
    cout<<m1;
    assert(isClose(m1.getVal(0, 0), 1.3));
    assert(isClose(m1.getVal(1, 1), 1.3));


    m1.initialize(1.1);
    m2.initialize(2.4);

    m1 *= m2;
    CHECK(m1.getVal(0, 0) == 5.28);
    CHECK(m1.getVal(1, 1) == 5.28);

    m1.initialize(1.1);
    m2.initialize(2.4);

    m1 /= 1;
    CHECK(m1.getVal(0, 0) == 1.1);
    CHECK(m1.getVal(1, 1) == 1.1);

    m1.initialize(1.1);
    m2.initialize(2.4);

    m1 %= 2;
    CHECK(m1.getVal(0, 0) == 1.1);
    CHECK(m1.getVal(1, 1) == 1.1);
}