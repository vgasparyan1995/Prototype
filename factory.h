#pragma once

#include <map>
#include <vector>
#include <memory>

class Orchestre;

enum class instrument : unsigned char
{
    PIANO,
    ORGAN
};

class Orchestre
{
public:
    class musician
    {
    public:
        virtual ~musician() {}
        virtual void play() const = 0;
        virtual musician* clone() const = 0;
    };

private:
    class pianist : public musician
    {
    public:
        pianist() {}
        void play() const override;
        virtual pianist* clone() const override;
    };

    class organist : public musician
    {
    public:
        organist() {}
        void play() const override;
        virtual organist* clone() const override;
    };

public:
    std::unique_ptr<musician> create_musician(const instrument i);

private:
    std::map<instrument, musician*> m_musicians;

public:
    static Orchestre* get_instance();
    static void remove_instance();

private:
    static Orchestre* s_instance;

private:
    Orchestre();
    ~Orchestre();
    Orchestre(const Orchestre&) = delete;
    Orchestre& operator=(const Orchestre&) = delete;
};

