#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;
        std::vector<int *> PrimeElements;//vector have just Prime number
        std::vector<int> CrossElements;//vector for class SideCross

    public:
        MagicalContainer() = default;
        void addElement(int element);//add element to the vecotrs
        void addPrime();//add Prime number to the vector PrimeElements
        void addSideCross();//add element to the vector CrossElements
        size_t size();//return the size of vector elements
        void removeElement(int element);//remove elements
        const std::vector<int> &getVector() const;//return vector elements
        const std::vector<int> &getVectorCross() const;//return vector CrosseElements
        const std::vector<int *> &getVectorPrime() const;//return vector PrimeElements
        bool exist(int element);//this function check if the element exist return true else return false
        bool isPrime(int number);//this function check if the element is prime return true else return false

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            AscendingIterator(MagicalContainer &);// constructor

            AscendingIterator(AscendingIterator &other):container(other.container),
            index(other.index){};//copy constructor



            ~AscendingIterator() = default;

            AscendingIterator begin();// begin iterator
            AscendingIterator end();//retrun end iterator

            AscendingIterator &operator=(const AscendingIterator &other);
            int operator*() const;
            AscendingIterator &operator++();
            MagicalContainer &getMagicalA();//return the container

            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            AscendingIterator &operator=(const AscendingIterator &&other) = delete;
            //AscendingIterator(AscendingIterator &&) = delete;
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            SideCrossIterator(MagicalContainer &);// constructor

            //copy constructor
            SideCrossIterator(SideCrossIterator &other) : container(other.container), index(other.index) {}
            ~SideCrossIterator() = default;

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator &operator=(const SideCrossIterator &other);
            int operator*() const;
            SideCrossIterator &operator++();
            MagicalContainer &getMagicalS() const;//return the container

            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;

            SideCrossIterator &operator=(const SideCrossIterator &&other) = delete;
            //SideCrossIterator(SideCrossIterator &&other) = delete;
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:

            PrimeIterator(MagicalContainer &);// constructor

            // copy constructor
            PrimeIterator(PrimeIterator &other) : container(other.container), index(other.index) {}
            ~PrimeIterator()=default;

            PrimeIterator begin();//return begin iterator 
            PrimeIterator end();//return end iterator

            PrimeIterator &operator=(const PrimeIterator &other);
            int operator*() const;
            PrimeIterator &operator++();

            MagicalContainer &getMagicalP() const;//return the container

            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;

            PrimeIterator &operator=(const PrimeIterator &&other) = delete;
            //PrimeIterator(PrimeIterator &&other) = delete;
        };
    };

};

#endif
