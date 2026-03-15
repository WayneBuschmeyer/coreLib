#include <Core/io.h>
#include <core/type_traits/remove_reference.h>
#include <core/utility/move.h>
#include <core/utility/forward.h>
#include <core/utility/swap.h>

namespace ns = core;

struct Test
{
    int value;

    Test(int v) : value(v)
    {
        ns::cout << "constructor\n";
    }

    Test(const Test& other)
    {
        value = other.value;
        ns::cout << "copy constructor\n";
    }

    Test(Test&& other)
    {
        value = other.value;
        other.value = 0;
        ns::cout << "move constructor\n";
    }

    Test& operator=(const Test& other)
    {
        value = other.value;
        ns::cout << "copy assignment\n";
        return *this;
    }

    Test& operator=(Test&& other)
    {
        value = other.value;
        other.value = 0;
        ns::cout << "move assignment\n";
        return *this;
    }
};

void test_remove_reference()
{
    ns::cout << "\nremove_reference test\n";

    using A = ns::remove_reference<int&>::type;
    using B = ns::remove_reference<int&&>::type;

    A a = 5;
    B b = 10;

    ns::cout << "A value: " << a << '\n';
    ns::cout << "B value: " << b << '\n';
}

void test_move()
{
    ns::cout << "\nmove test\n";

    Test a(10);

    Test b(ns::move(a));

    ns::cout << "b.value = " << b.value << '\n';
}

void test_forward_impl(Test&)
{
    ns::cout << "forward received lvalue\n";
}

void test_forward_impl(Test&&)
{
    ns::cout << "forward received rvalue\n";
}

template<typename T>
void test_forward(T&& value)
{
    test_forward_impl(ns::forward<T>(value));
}

void run_forward_tests()
{
    ns::cout << "\nforward test\n";

    Test a(20);

    test_forward(a);
    test_forward(ns::move(a));
}

void test_swap()
{
    ns::cout << "\nswap test\n";

    int a = 5;
    int b = 10;

    ns::cout << "before swap: " << a << " " << b << '\n';

    ns::swap(a, b);

    ns::cout << "after swap: " << a << " " << b << '\n';
}

int main()
{
    test_remove_reference();
    test_move();
    run_forward_tests();
    test_swap();

    return 0;
}