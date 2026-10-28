#include "Span.hpp"

int main()
{
    std::srand(std::time(0));

    try
    {
        // Test 1: fillSpan avec un tableau
        std::cout << "Test 1 - fillSpan:" << std::endl;
        int array[] = {6, 3, 17, 9, 11};
        Span sp = Span(5);
        sp.fillSpan(array, array + 5);
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;

        // Test 2: addNumber un par un
        std::cout << "\nTest 2 - addNumber:" << std::endl;
        Span sp2 = Span(4);
        sp2.addNumber(5);
        sp2.addNumber(10);
        sp2.addNumber(15);
        sp2.addNumber(20);
        std::cout << "Longest: " << sp2.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;

        // Test 3: deux nombres
        std::cout << "\nTest 3 - Two numbers:" << std::endl;
        Span sp3 = Span(2);
        sp3.addNumber(42);
        sp3.addNumber(100);
        std::cout << "Longest: " << sp3.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp3.shortestSpan() << std::endl;

        // Test 4: deux nombres identiques
        std::cout << "\nTest 4 - Two identical numbers:" << std::endl;
        Span sp4 = Span(2);
        sp4.addNumber(1);
        sp4.addNumber(1);
        std::cout << "Longest: " << sp4.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp4.shortestSpan() << std::endl;

        // Test 5: 10 000 nombres consecutifs
        std::cout << "\nTest 5 - 10,000 consecutive numbers:" << std::endl;
        Span sp5 = Span(10000);
        for (int i = 0; i < 10000; i++)
            sp5.addNumber(i);
        std::cout << "Longest: " << sp5.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp5.shortestSpan() << std::endl;

        // Test 6: 10 000 nombres aleatoires
        std::cout << "\nTest 6 - 10,000 random numbers:" << std::endl;
        Span sp6 = Span(10000);
        for (int i = 0; i < 10000; i++)
            sp6.addNumber(std::rand() % 100000);
        std::cout << "Longest: " << sp6.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp6.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    // Test 7: Span plein -> exception attendue
    std::cout << "\nTest 7 - Full span:" << std::endl;
    try
    {
        Span full(1);
        full.addNumber(1);
        full.addNumber(2);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 8: moins de 2 nombres -> exception attendue
    std::cout << "\nTest 8 - Not enough numbers:" << std::endl;
    try
    {
        Span one(5);
        one.addNumber(1);
        std::cout << one.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 9: plage trop grande -> exception attendue
    std::cout << "\nTest 9 - Range too long:" << std::endl;
    try
    {
        int tooLong[] = {1, 2, 3};
        Span small(2);
        small.fillSpan(tooLong, tooLong + 3);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    // Test 10: fillSpan avec un std::vector
    std::cout << "\nTest 10 - fillSpan with std::vector:" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++)
        vec.push_back(std::rand() % 100000);
    Span sp7(10000);
    sp7.fillSpan(vec.begin(), vec.end());
    std::cout << "Longest: " << sp7.longestSpan() << std::endl;
    std::cout << "Shortest: " << sp7.shortestSpan() << std::endl;

    // Test 11: fillSpan avec un std::list
    std::cout << "\nTest 11 - fillSpan with std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(14);
    lst.push_back(8);
    Span sp8(3);
    sp8.fillSpan(lst.begin(), lst.end());
    std::cout << "Longest: " << sp8.longestSpan() << std::endl;
    std::cout << "Shortest: " << sp8.shortestSpan() << std::endl;

    return 0;
}