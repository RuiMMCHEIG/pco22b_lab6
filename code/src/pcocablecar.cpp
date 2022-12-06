//     ____  __________ ___   ____ ___  ___
//    / __ \/ ____/ __ \__ \ / __ \__ \|__ \
//   / /_/ / /   / / / /_/ // / / /_/ /__/ /
//  / ____/ /___/ /_/ / __// /_/ / __// __/
// /_/    \____/\____/____/\____/____/____/
//
// Auteurs : Prénom Nom, Prénom Nom

#include "pcocablecar.h"
#include <pcosynchro/pcothread.h>
#include <QRandomGenerator>
#include <QDebug>
#include <QThread>
#include <sstream>

constexpr unsigned int MIN_SECONDS_DELAY = 2;
constexpr unsigned int MAX_SECONDS_DELAY = 5;
constexpr unsigned int MIN_SECONDS_DELAY_SKIER = 1;
constexpr unsigned int MAX_SECONDS_DELAY_SKIER = 2;
constexpr unsigned int MIN_SECONDS_SKIER_SLIDE = 2;
constexpr unsigned int MAX_SECONDS_SKIER_SLIDE = 5;
constexpr unsigned int MIN_SECONDS_SKIER_GO_WAIT = 3;
constexpr unsigned int MAX_SECONDS_SKIER_GO_WAIT = 4;

constexpr unsigned int SECOND_IN_MILLISECONDS = 1000;


PcoCableCar::PcoCableCar(PCCarInterface *interface, const unsigned int capacity)
    : _interface(interface), capacity(capacity)
{
    // TODO
}

PcoCableCar::~PcoCableCar()
{

}

void PcoCableCar::waitForCableCar(int id)
{
    // TODO
}

void PcoCableCar::waitInsideCableCar(int id)
{
    // TODO
    // Ajoutez ce qu'il vous semble nécessaire dans cette fonction

    _interface->consoleAppendText(id, "Je suis dans le télécabine");
}

void PcoCableCar::goIn(int id)
{
    // TODO
    // Ajoutez ce qu'il vous semble nécessaire dans cette fonction

    _interface->consoleAppendText(id, "Je monte dans le télécabine");
    unsigned ms = (MIN_SECONDS_DELAY_SKIER + QRandomGenerator::system()->bounded(MAX_SECONDS_DELAY_SKIER)) * SECOND_IN_MILLISECONDS;
    _interface->skierGoIn(id, ms);
}

void PcoCableCar::goOut(int id)
{
    // TODO
    // Ajoutez ce qu'il vous semble nécessaire dans cette fonction
    _interface->consoleAppendText(id, "Je descends du télécabine");
    unsigned ms = (MIN_SECONDS_DELAY_SKIER + QRandomGenerator::system()->bounded(MAX_SECONDS_DELAY_SKIER)) * SECOND_IN_MILLISECONDS;
    _interface->skierGoOut(id, ms);
    _interface->consoleAppendText(id, "En haut de la piste !");
}


void PcoCableCar::slideSlope(int id)
{
    unsigned ms = (MIN_SECONDS_DELAY_SKIER + QRandomGenerator::system()->bounded(MAX_SECONDS_DELAY_SKIER)) * SECOND_IN_MILLISECONDS;
    QThread::msleep(ms/2);
    ms = (MIN_SECONDS_SKIER_SLIDE + QRandomGenerator::system()->bounded(MAX_SECONDS_SKIER_SLIDE)) * SECOND_IN_MILLISECONDS;
    _interface->skierSlide(id, ms);
    _interface->consoleAppendText(id, "Youhouuuu, une bonne descente !");
    ms = (MIN_SECONDS_SKIER_GO_WAIT + QRandomGenerator::system()->bounded(MAX_SECONDS_SKIER_GO_WAIT)) * SECOND_IN_MILLISECONDS;
    _interface->skierWait(id, ms);
    _interface->consoleAppendText(id, "J'attends le télécabine...");
}

bool PcoCableCar::isInService()
{
    return inService;
}

void PcoCableCar::endService()
{
    // TODO
}

void PcoCableCar::goUp()
{
    _interface->consoleAppendTextCcar("Le télécabine monte");
    unsigned ms = (MIN_SECONDS_DELAY + QRandomGenerator::system()->bounded(MAX_SECONDS_DELAY + 1)) * SECOND_IN_MILLISECONDS;
    _interface->cableCarTravelUp(ms);
}

void PcoCableCar::goDown()
{
    unsigned ms = (MIN_SECONDS_DELAY + QRandomGenerator::system()->bounded(MAX_SECONDS_DELAY + 1)) * SECOND_IN_MILLISECONDS;
    _interface->consoleAppendTextCcar("Le télécabine descend");
    _interface->cableCarTravelDown(ms);
}

void PcoCableCar::loadSkiers()
{
    // TODO
}

void PcoCableCar::unloadSkiers()
{
    // TODO
}
