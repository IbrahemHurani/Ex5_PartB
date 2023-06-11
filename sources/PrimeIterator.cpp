#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
// Prime Iterator implement

// constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont) : container(cont), index(0)
{
}

//operator ==
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return &container == &(other.container) && this->index == other.index;
}
//operator !=
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}
//operator =
MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)
{

    if (this != &other)
    {
        throw runtime_error("differnt container");
    }
    this->index = other.index;
    return *this;
}
//operator <
bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const
{
    return this->index < other.index;
}
//operator>
bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const
{

    return this->index > other.index;
}
//operator *
int MagicalContainer::PrimeIterator::operator*() const
{
    if (this->index >= this->container.getVector().size())
    {
        throw runtime_error("the index bigger than the size");
    }
    return *container.getVectorPrime().at(index);
}
//operator ++
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (this->index >= this->container.getVectorPrime().size())
    {
        throw runtime_error("the index bigger than the size");
    }
    index++;//add
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    PrimeIterator it(this->container);
    it.index = 0;//for the begin iterator index =0 ->the begining
    return it;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{

    PrimeIterator it(this->container);
    it.index = container.getVectorPrime().size();//for the end iterator index=size->the end
    return it;
}

MagicalContainer &MagicalContainer::PrimeIterator::getMagicalP() const
{
    return container;
}

