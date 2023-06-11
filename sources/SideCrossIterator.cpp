#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
/// SideCross Iterator implement

// constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &Magical) : container(Magical),index(0)
{
}
//return begining of iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    SideCrossIterator it(this->container);
    return it;
}
//return the end of iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator it(this->container);
    it.index = container.getVectorCross().size();
    return it;
}
//operator =
MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)
{
    if (this != &other)
    {
        throw runtime_error("differnt container");
    }
    this->index=other.index;
    return *this;
}
//operator *
int MagicalContainer::SideCrossIterator::operator*() const
{
    if (this->index >= this->container.getVectorCross().size())
    {
        throw runtime_error("the index bigger than the size!!");
    }
    return container.getVectorCross().at(index);
}
//operator ++
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (this->index >= this->container.getVectorCross().size())
    {
        throw runtime_error("the index bigger than the size");
    }
    ++index;
    return *this;
}
//operator ++
bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const
{
    return &container == &(other.container) && this->index == other.index;
}
//operator !=
bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const
{
    return !(*this == other);
}
//operator <
bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const
{
   return this->index < other.index;
}
//operator >
bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const
{
    return this->index > other.index;
}
//reuturn container
MagicalContainer &MagicalContainer::SideCrossIterator::getMagicalS() const
{
    return container;
}