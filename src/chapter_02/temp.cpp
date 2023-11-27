#include <iostream>
// #include "wrapper.h"

namespace n201
{
    template <typename T>
    T add(T const a, T const b)
    {
        return a + b;
    }

    class foo
    {
        int value;
    public:
        explicit foo(int const i) :value(i)
        {
        }

        explicit operator int() const { return value; }
    };

    foo operator+(foo const a, foo const b)
    {
        return foo((int)a + (int)b);
    }

    template <typename Input, typename Predicate>
    int count_if(Input start, Input end, Predicate p)
    {
        int total = 0;
        for (Input i = start; i != end; i++)
        {
            if (p(*i))
                total++;
        }
        return total;
    }
}

namespace n202
{
    template <typename T>
    class wrapper
    {
    public:
        wrapper(T const v):value(v)
        { }

        T const& get() const { return value; }
    private:
        T value;
    };
}

namespace n203
{
    // 仅声明
    template <typename T>
    class wrapper;

    void use_wrapper(wrapper<int>* ptr);
}

namespace n203
{
    // 上述声明的实现
    // 定义必须在 实例化 之前完成不然会导致编译器报错
    template <typename T>
    class wrapper
    {
    public:
        wrapper(T const v) :value(v)
        {
        }

        T const& get() const { return value; }
    private:
        T value;
    };

    void use_wrapper(wrapper<int>* ptr)
    {
        std::cout << ptr->get() << '\n';
    }
}

namespace n204
{
    template<typename T>
    class composition
    {
    public:
        T add (T const a, T const b)
        {
            return a + b;
        }
    };
}

namespace n205
{
    class composition
    {
    public:
        template<typename T>
        T add(T const a, T const b)
        {
            return a + b;
        }
    };
}

namespace n206
{
    template <typename T>
class wrapper
    {
    public:
        wrapper(T const v) :value(v)
        {
        }

        T const& get() const { return value; }

        template <typename U>
        U as() const
        {
            return static_cast<U>(value);
        }
    private:
        T value;
    };
}

namespace n207
{
    template <typename T>
    class wrapper1 { /* ... */ };

    template <typename T = int>
    class wrapper2 { /* ... */ };

    template <typename>
    class wrapper3;

    template <typename = int>
    class wrapper4;

    template <typename... T>
    class wrapper5 { /* ... */ };

    template <typename T>
    concept WrappableType = std::is_trivial_v<T>;

    // must use cxx20 concepts
    template <WrappableType T>
    class wrapper6 { /* ... */ };

    template <WrappableType T = int>
    class wrapper7 { /* ... */ };

    template <WrappableType... T>
    class wrapper8 { /* ... */ };
}

namespace n208
{
    template <int V>
    class foo1 { /*...*/ };

    template <int V = 42>
    class foo2 { /*...*/ };

    template <int... V>
    class foo3 { /*...*/ };
}

namespace n209
{
    template <typename T, size_t S>
    class buffer
    {
        T data_[S];
    public:
        constexpr T const * data() const { return data_; }

        constexpr T& operator[](size_t const index)
        {
            return data_[index];
        }

        constexpr T const & operator[](size_t const index) const
        {
            return data_[index];
        }
    };

    template <typename T, size_t S>
    buffer<T, S> make_buffer()
    {
        return {};
    }
}


int main()
{
    {
        using namespace n201;

        auto a1 = add(42, 21);
        auto a2 = add<int>(42, 21);
        auto a3 = add<>(42, 21);

        auto b = add<short>(42, 21);

        //auto d1 = add(41.0, 21); // error, type undecleared
        auto d2 = add<double>(41.0, 21);

        auto f = add(foo(42), foo(41));

        int arr[]{ 1,1,2,3,5,8,11 };

        // 概念上类似于 algorithm's count_if
        int odds = count_if(std::begin(arr), std::end(arr),
           [](int const n) { return n % 2 == 1; });
        std::cout << "n201: " << odds << '\n';
    }

    {
        using namespace n202;

        wrapper a(42);           // wraps an int
        wrapper<int> b(42);      // wraps an int
        wrapper<short> c(42);    // wraps a short
        wrapper<double> d(42.0); // wraps a double
        wrapper e("42");         // wraps a char const *
    }

    {
        using namespace n203;

        wrapper<int> a(42);          // wraps an int
        use_wrapper(&a);
    }

    {
        using namespace n204;

        composition<int> c;
        std::cout << "n204: " << c.add(21, 42);
    }

    {
        using namespace n205;

        composition c;
        std::cout << "\nn205: " << c.add<int>(21, 42);
    }

    {
        using namespace n206;

        wrapper a(42.1); // 可以不指定 wapper<double>, 编译器自动推断

        auto d = a.get();
        auto n = a.as<int>();
        std::cout << "\nn206: " << d << " " << n << '\n';
    }
}