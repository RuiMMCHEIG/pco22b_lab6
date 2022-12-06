//     ____  __________ ___   ____ ___  ___
//    / __ \/ ____/ __ \__ \ / __ \__ \|__ \
//   / /_/ / /   / / / /_/ // / / /_/ /__/ /
//  / ____/ /___/ /_/ / __// /_/ / __// __/
// /_/    \____/\____/____/\____/____/____/
//
// Auteurs : Prénom Nom, Prénom Nom

#include "skierbehavior.h"

#include <QRandomGenerator>

int SkierBehavior::nextId = 0;

SkierBehavior::SkierBehavior(PCCarInterface *interface, std::shared_ptr<CableCarSkierInterface> cableCar)
    : _interface(interface),  skierId(nextId++), cableCar(cableCar)
{
    _interface->consoleAppendText(skierId, "Salut, le ski c'est la vie");
}


void SkierBehavior::run()
{
    // A vous d'ajouter le comportement du skieur

}
