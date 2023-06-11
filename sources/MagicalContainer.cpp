
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;
//add elements to vector elements and to vector PrimeElements and CrossElements
void MagicalContainer::addElement(int element)
{
    elements.push_back(element);//add elements
    std::sort(this->elements.begin(), this->elements.end());//sort the vector for class Ascending
    addPrime();//add the Prime elements
    addSideCross();//add to vector CrossElements
}

void MagicalContainer::addSideCross()
{
    if(this->elements.empty()){//check it the vector is empty
        return ;
    }
    this->CrossElements.clear();//clear the vector Elements to do the update
    size_t left = 0;
    size_t right = this->elements.size() - 1;
    for (int i = 0; i < this->elements.size() / 2; i++)
    {
        this->CrossElements.push_back(elements.at(left));//add the first elements
        this->CrossElements.push_back(elements.at(right));//add the last elements
        right--;
        left++;
    }
    if (this->elements.size() % 2 != 0)//if the size the vector is odd to add middle elements
    {
        size_t middleIndex = this->elements.size() / 2;
        this->CrossElements.push_back(elements.at(middleIndex));
    }
}

void MagicalContainer::addPrime()
{
    this->PrimeElements.clear();//clear the vector to do update
    for (int element : this->elements)
    {
        if (isPrime(element))
        {
            this->PrimeElements.push_back(new int(element));
        }
    }
}

size_t MagicalContainer::size()//return the size of vector elements
{
    return elements.size();
}
//fucntion to remove element
void MagicalContainer::removeElement(int element)
{
    if (exist(element))
    {
        auto re = std::remove(this->elements.begin(), this->elements.end(), element);
        this->elements.erase(re, this->elements.end());
        addPrime();//update vector Prime elements
        addSideCross();//update vector CrossElements
    }
    else
    {
        throw runtime_error("this element not exsit");
    }
}
//return the vector elements
const std::vector<int> &MagicalContainer::getVector() const
{
    return this->elements;
}
//return the vector Cross elemets
const std::vector<int> &MagicalContainer::getVectorCross() const
{
    return this->CrossElements;
}
//return the vector Prime elemets
const std::vector<int *> &MagicalContainer::getVectorPrime() const
{
    return this->PrimeElements;
}
//this fucntion check if the elemets exist
bool MagicalContainer::exist(int element)
{
    auto it = find(this->elements.begin(), this->elements.end(), element);
    if (it != this->elements.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//this function check if the elements is prime
bool MagicalContainer::isPrime(int number)
{
    if (number <= 1)
    {
        return false; // Numbers less than or equal to 1 are not prime
    }

    int sqrtNumber = sqrt(number);
    for (int i = 2; i <= sqrtNumber; ++i)
    {
        if (number % i == 0)
        {
            return false; // Number is divisible, hence not prime
        }
    }

    return true; // Number is prime
}

