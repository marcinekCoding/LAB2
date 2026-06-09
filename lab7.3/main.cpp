#include <iostream>

#define STAGE_1
// #define STAGE_2
// #define STAGE_3
// #define STAGE_4

#include "ring_buffer.hpp"

int main() {
#ifdef STAGE_1
    {
        std::cout << "\n--- Stage 1: RingBuffer definition, push, isEmpty, isFull, size ---"
                  << std::endl;

        RingBuffer<int, 4> q;
        std::cout << "Empty: " << std::boolalpha << q.isEmpty() << std::endl;
        std::cout << "Full: " << q.isFull() << std::endl;
        std::cout << "Size: " << q.size() << std::endl;

        std::cout << "push(10): " << q.push(10) << std::endl;
        std::cout << "push(20): " << q.push(20) << std::endl;
        std::cout << "push(30): " << q.push(30) << std::endl;
        std::cout << "Size after 3 pushes: " << q.size() << std::endl;
        std::cout << "Full: " << q.isFull() << std::endl;

        std::cout << "push(40): " << q.push(40) << std::endl;
        std::cout << "Full after 4th push: " << q.isFull() << std::endl;
        std::cout << "push(50) rejected: " << q.push(50) << std::endl;
        std::cout << "Size unchanged: " << q.size() << std::endl;
    }
#endif

#ifdef STAGE_2
    {
        std::cout << "\n--- Stage 2: pop, front, back, operator<< ---" << std::endl;

        RingBuffer<int, 4> q;
        q.push(10);
        q.push(20);
        q.push(30);

        std::cout << "Queue: " << q << std::endl;
        std::cout << "front: " << *q.front() << std::endl;
        std::cout << "back: " << *q.back() << std::endl;

        q.pop();
        std::cout << "After pop: " << q << std::endl;
        std::cout << "front: " << *q.front() << std::endl;

        RingBuffer<int, 2> empty;
        std::cout << "pop on empty: " << empty.pop() << std::endl;
        std::cout << "front on empty has value: " << empty.front().has_value() << std::endl;

        RingBuffer<int, 3> wrap;
        wrap.push(1);
        wrap.push(2);
        wrap.push(3);
        wrap.pop();
        wrap.pop();
        wrap.push(4);
        wrap.push(5);
        std::cout << "Wrap-around queue: " << wrap << std::endl;
    }
#endif

#ifdef STAGE_3
    {
        std::cout << "\n--- Stage 3: initializer_list constructor ---" << std::endl;

        RingBuffer<int, 3> q = {1, 2, 3, 4, 5};
        std::cout << "From {1,2,3,4,5} with capacity 3: " << q << std::endl;
        std::cout << "Size: " << q.size() << std::endl;
        std::cout << "Full: " << q.isFull() << std::endl;

        RingBuffer<char, 5> letters = {'a', 'b', 'c'};
        std::cout << "Letters: " << letters << std::endl;
    }
#endif

#ifdef STAGE_4
    {
        std::cout << "\n--- Stage 4: RingBuffer<T, 1> specialization ---" << std::endl;

        RingBuffer<int, 1> single;
        std::cout << "push(100): " << single.push(100) << std::endl;
        std::cout << "Content: " << single << std::endl;
        std::cout << "push(200) overwrites: " << single.push(200) << std::endl;
        std::cout << "Content: " << single << std::endl;
        std::cout << "front: " << *single.front() << std::endl;
        std::cout << "Size still: " << single.size() << std::endl;

        single.pop();
        std::cout << "After pop empty: " << single.isEmpty() << std::endl;
        std::cout << "Content: '" << single << "'" << std::endl;
    }
#endif

    return 0;
}
