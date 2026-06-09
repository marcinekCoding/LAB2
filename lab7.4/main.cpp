#include <iostream>

#define STAGE_1
// #define STAGE_2
// #define STAGE_3
// #define STAGE_4
// #define STAGE_5

#include "fixed_stack.hpp"

int main() {
#ifdef STAGE_1
    {
        std::cout << "\n--- Stage 1: FixedStack definition, push, isEmpty, isFull, size ---"
                  << std::endl;

        FixedStack<int, 4> s;
        std::cout << "Empty: " << std::boolalpha << s.isEmpty() << std::endl;
        std::cout << "Full: " << s.isFull() << std::endl;
        std::cout << "Size: " << s.size() << std::endl;

        std::cout << "push(10): " << s.push(10) << std::endl;
        std::cout << "push(20): " << s.push(20) << std::endl;
        std::cout << "push(30): " << s.push(30) << std::endl;
        std::cout << "Size after 3 pushes: " << s.size() << std::endl;

        std::cout << "push(40): " << s.push(40) << std::endl;
        std::cout << "Full: " << s.isFull() << std::endl;
        std::cout << "push(50) rejected: " << s.push(50) << std::endl;
        std::cout << "Size unchanged: " << s.size() << std::endl;
    }
#endif

#ifdef STAGE_2
    {
        std::cout << "\n--- Stage 2: pop, top, popValue, operator<< ---" << std::endl;

        FixedStack<int, 4> s;
        s.push(10);
        s.push(20);
        s.push(30);

        std::cout << "Stack: " << s << std::endl;
        std::cout << "top: " << *s.top() << std::endl;

        auto v = s.popValue();
        std::cout << "popValue: " << *v << std::endl;
        std::cout << "After popValue: " << s << std::endl;

        s.pop();
        std::cout << "After pop: " << s << std::endl;

        FixedStack<int, 2> empty;
        std::cout << "pop on empty: " << empty.pop() << std::endl;
        std::cout << "top on empty has value: " << empty.top().has_value() << std::endl;
        std::cout << "popValue on empty has value: " << empty.popValue().has_value() << std::endl;
    }
#endif

#ifdef STAGE_3
    {
        std::cout << "\n--- Stage 3: initializer_list constructor and clear ---" << std::endl;

        FixedStack<char, 3> s = {'a', 'b', 'c', 'd'};
        std::cout << "From {a,b,c,d} with capacity 3: " << s << std::endl;
        std::cout << "Size: " << s.size() << std::endl;

        s.clear();
        std::cout << "After clear empty: " << s.isEmpty() << std::endl;
        std::cout << "After clear size: " << s.size() << std::endl;
    }
#endif

#ifdef STAGE_4
    {
        std::cout << "\n--- Stage 4: FixedStack<T, 0> specialization ---" << std::endl;

        FixedStack<int, 0> s;
        std::cout << "push: " << s.push(1) << std::endl;
        std::cout << "pop: " << s.pop() << std::endl;
        std::cout << "isEmpty: " << s.isEmpty() << std::endl;
        std::cout << "isFull: " << s.isFull() << std::endl;
        std::cout << "size: " << s.size() << std::endl;
        std::cout << "top has value: " << s.top().has_value() << std::endl;
        std::cout << "Output: '" << s << "'" << std::endl;
    }
#endif

#ifdef STAGE_5
    {
        std::cout << "\n--- Stage 5: merge ---" << std::endl;

        FixedStack<int, 4> a;
        a.push(1);
        a.push(2);

        FixedStack<int, 4> b;
        b.push(3);
        b.push(4);
        b.push(5);

        auto merged = a.merge(b);
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "merged: " << merged << std::endl;
        std::cout << "merged size: " << merged.size() << std::endl;
    }
#endif

    return 0;
}
