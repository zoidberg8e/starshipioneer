#ifndef FACTORY_H
#define FACTORY_H

#include <vector>

// TODO: Let this inherit from std::vector and add
//       - createEntity
//       - destroyEntitiy
//       - destroyLast
//       with garbage lists
template<class T>
class Factory
{
public:
    Factory();
    ~Factory();

    T* CreateEntity();
    void DestroyEntitiy(T* t);
    void DestroyLast();
    void Clear();

    typedef typename std::vector<T>::iterator T_it;

    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();

protected:
    std::vector<T> elems;
};

#include "factory.cpp"

#endif // FACTORY_H
