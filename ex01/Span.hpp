#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <list>


class Span
{
    private:
        unsigned int _sizeN;
        std::vector<int> _vector;
    public:
        Span();
        Span(unsigned int sizeN);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void fillSpan(Iterator begin, Iterator end);

        int shortestSpan() const;
        int longestSpan() const;
        class tooMuchMember : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Too much member in the Span";
            }
        };
        class NotEnoughMember : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "Span need at least 2 members";
            }
        }; 

};

template <typename Iterator>
void Span::fillSpan(Iterator begin, Iterator end)
{   
    while(begin != end)
    {
        if(_vector.size() >= _sizeN)
            throw tooMuchMember();
        _vector.push_back(*begin);
        ++begin;
    }
}

#endif