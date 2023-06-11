#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
#define zero 0
/// Ascending Iterator implement

// constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &Magical) : container(Magical), index(zero)
{
}

//opertor ==
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return &container == &(other.container) && this->index == other.index;
}
//operator !=
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}
//operator =
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other)
{
    if (this != &other)
    {
        throw runtime_error("differnt container");
    }
    this->index = other.index;
    return *this;
}
//opertor <
bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const
{
    return this->index < other.index;
}
//operator >
bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const
{

    return this->index > other.index;
}
//operator *
int MagicalContainer::AscendingIterator::operator*() const
{
    if (this->index >= this->container.getVector().size())
    {
        throw runtime_error("the index bigger than the size");
    }
    return this->container.getVector().at(index);
}
//operator ++
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (this->index >= this->container.getVector().size())
    {
        throw runtime_error("the index bigger than the size");
    }
    ++index;
    return *this;
}
//return the begin iterator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    AscendingIterator it(this->container);
    return it;
}
//return the end of iterator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator it(this->container);
    it.index = container.size();
    return it;
}
// return container ->MagicalContainer
MagicalContainer &MagicalContainer::AscendingIterator::getMagicalA()
{
    return container;
}
