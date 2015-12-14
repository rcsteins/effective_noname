#ifndef _COMPACTIBLE_VECTOR_H_
#define _COMPACTIBLE_VECTOR_H_

#include <vector>
#include <algorithm>

template <class T>
class compactible_vector: public std::vector<T>
{
public:

template <class F> 
void compact(F pred) {
    this->erase( 
        std::remove_if(this->begin(), this->end(), pred),
        this->end()
    );
}
};

#endif /* end of include guard: _COMPACTIBLE_VECTOR_H_ */
