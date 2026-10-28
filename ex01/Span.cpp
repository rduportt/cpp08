#include "Span.hpp"

Span::Span()
{
    _sizeN = 0;
    _vector.reserve(_sizeN);
}

Span::Span(unsigned int sizeN)
{
    _sizeN = sizeN;
    _vector.reserve(_sizeN);
}

Span::Span(const Span &other) : _sizeN(other._sizeN), _vector(other._vector) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _sizeN = other._sizeN;
        _vector = other._vector;
    }
    return *this;
}

Span::~Span()
{

}

void Span::addNumber(int number)
{
    if(_vector.size() < _sizeN)
        _vector.push_back(number);
    else
        throw tooMuchMember();
}



int Span::longestSpan() const
{
    if (_vector.size() < 2)
        throw NotEnoughMember();
    int min = *std::min_element(_vector.begin(), _vector.end());
    int max = *std::max_element(_vector.begin(), _vector.end());
    return max - min;
}

int Span::shortestSpan() const
{
    if (_vector.size() < 2)
        throw NotEnoughMember();
    std::vector<int> sorted(_vector);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (std::size_t i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}