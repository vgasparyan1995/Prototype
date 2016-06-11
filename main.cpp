#include "factory.h"

#include <vector>

int main()
{
    auto orchestre = Orchestre::get_instance();
    std::vector<std::unique_ptr<Orchestre::musician>> orc;
    orc.push_back(orchestre->create_musician(instrument::PIANO));
    orc.push_back(orchestre->create_musician(instrument::PIANO));
    orc.push_back(orchestre->create_musician(instrument::ORGAN));

    for (const auto& m : orc) {
        m->play();
    }
}
