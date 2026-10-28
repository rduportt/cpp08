#include "easyfind.hpp"


int main()
{
    std::vector<int> v;
    for (int i = 1; i <= 6; i++)
        v.push_back(i);

    std::list<int> l(v.begin(), v.end());

    try
    {
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "vector: found " << *it
                  << " at index " << (it - v.begin()) << std::endl;

        std::list<int>::iterator lit = easyfind(l, 3);
        std::cout << "list: found " << *lit << std::endl;

        easyfind(v, 42);
    }
    catch (const std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    return 0;
}