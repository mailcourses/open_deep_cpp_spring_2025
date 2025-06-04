#include <iostream>
#include <queue>
#include <vector>

struct Foo
{
    uint16_t age;
    uint16_t weight;
    friend std::ostream& operator<<(std::ostream& out, const Foo& rhs);
};

std::ostream& operator<<(std::ostream& out, const Foo& rhs)
{
    out << "Foo(age=" << rhs.age << ", weight=" << rhs.weight << ")";
    return out;
}

int main()
{
    const uint8_t k = 3;

    {
        std::cout << "===================" << std::endl;
        std::vector<int32_t> arr = {7, 1, 5, 3, 9, 2};

        // O(n log n)
        std::sort(arr.begin(), arr.end());
        for (uint8_t i = 0; i < k; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // O(n log n)
    {
        std::cout << "===================" << std::endl;
        std::vector<int32_t> arr = {7, 1, 5, 3, 9, 2};
        //std::priority_queue pq(arr.begin(), arr.end(), std::greater<int32_t>());
        std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> pq;
        for (auto num : arr) {
            pq.push(num);
        }

        for (uint8_t i = 0; i < k && !pq.empty(); ++i) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }

    // O(n log n) -> O(n log k)
    {
        std::cout << "===================" << std::endl;
        std::vector<int32_t> arr = {7, 1, 5, 3, 9, 2};

        std::priority_queue<int32_t, std::vector<int32_t>, std::less<int32_t>> pq;
        for (auto num : arr) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        for (uint8_t i = 0; i < k && !pq.empty(); ++i) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }

    {
        std::vector<Foo> arr = {Foo{23, 65}, Foo{45, 83}, Foo{8, 30}, Foo{35, 82}, Foo{45, 75}, Foo{23, 69}, Foo{82, 83}};
        auto comp = [](const Foo& lhs, const Foo& rhs) {
            if (lhs.weight != rhs.weight)
                return lhs.weight < rhs.weight;
            return lhs.age > rhs.age;
        };
        std::priority_queue<Foo, std::vector<Foo>, decltype(comp)> pq(comp);
        for (auto el : arr) {
            pq.push(el);
        }

        for (uint8_t i = 0; !pq.empty(); ++i) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }
}
