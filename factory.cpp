#include "factory.h"

#include <iostream>

Orchestre* Orchestre::s_instance = nullptr;

void Orchestre::pianist::play() const
{
    std::cout << "piano" << std::endl;
}

Orchestre::pianist* Orchestre::pianist::clone() const
{
    return new pianist(*this);
}

void Orchestre::organist::play() const
{
    std::cout << "organ" << std::endl;
}

Orchestre::organist* Orchestre::organist::clone() const
{
    return new organist(*this);
}

Orchestre* Orchestre::get_instance()
{
    if (s_instance == nullptr) {
        s_instance = new Orchestre;
    }
    return s_instance;
}

void Orchestre::remove_instance()
{
    if (s_instance != nullptr) {
        delete s_instance;
        s_instance = nullptr;
    }
}

Orchestre::Orchestre()
{
    m_musicians.insert(std::make_pair(instrument::PIANO, new pianist()));
    m_musicians.insert(std::make_pair(instrument::ORGAN, new organist()));
}

Orchestre::~Orchestre()
{
    for (auto& pair : m_musicians) {
        delete pair.second;
    }
}

std::unique_ptr<Orchestre::musician> Orchestre::create_musician(const instrument i)
{
    return std::unique_ptr<Orchestre::musician>(m_musicians[i]->clone());
}
