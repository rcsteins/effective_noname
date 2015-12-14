#ifndef _GUID_SET_H_
#define _GUID_SET_H_

#include <unordered_set>
#include <algorithm>

class GuidSet : public std::unordered_set<int>
{
public:
    GuidSet (): std::unordered_set<int>() {};

    bool contains(int guid) { return this->find(guid) != this->end(); } 
    bool containsAny(GuidSet& other) {
        return std::any_of(other.begin(), other.end(), [this](int i){ return this->contains(i);} );
    }
private:
    /* data */
};

#endif /* end of include guard: _GUID_SET_H_ */
