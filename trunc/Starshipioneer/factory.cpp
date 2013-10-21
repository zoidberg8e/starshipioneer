#include "factory.h"

#ifndef FACTORY_CPP
#define FACTORY_CPP

//#define T_it typename std::vector<T>::iterator

template<class T>
Factory<T>::Factory()
{
}

template<class T>
Factory<T>::~Factory()
{
    Clear();
}

template<class T>
T* Factory<T>::CreateEntity()
{
    // this is efficient
    elems.push_back(T());
    return &(elems.back());
}

template<class T>
void Factory<T>::DestroyLast()
{
    elems.pop_back();
}

template<class T>
void Factory<T>::DestroyEntitiy(T* t)
{
    // TODO: bring in more performance
    for(typename std::vector<T>::iterator it = elems.begin(); it < elems.end(); it++)
    {
        if(&(*it) == t)
        {
            elems.erase(it); // This calls destructor
            break;
        }
    }
}

template<class T>
void Factory<T>::Clear()
{
    elems.clear(); // This calls destructors
}

template<class T>
typename std::vector<T>::iterator Factory<T>::begin()
{
    return elems.begin();
}

template<class T>
typename std::vector<T>::iterator Factory<T>::end()
{
    return elems.end();
}

#endif // FACTORY_CPP
