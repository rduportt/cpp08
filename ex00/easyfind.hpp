#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &container, int value);
#include "easyfind.tpp"

#endif