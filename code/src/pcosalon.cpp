//     ____  __________ ___   ____ ___  ___
//    / __ \/ ____/ __ \__ \ / __ \__ \|__ \
//   / /_/ / /   / / / /_/ // / / /_/ /__/ /
//  / ____/ /___/ /_/ / __// /_/ / __// __/
// /_/    \____/\____/____/\____/____/____/
//
// Modifications à faire dans le fichier

#include "pcosalon.h"

#include <pcosynchro/pcothread.h>

#include <iostream>

PcoSalon::PcoSalon(GraphicSalonInterface *interface, unsigned int capacity)
    : _interface(interface), _capacity(capacity)
{
    _clients = std::queue<unsigned>();
    _chairNumber = _capacity;
    _asleep = false;
}

/********************************************
 * Méthodes de l'interface pour les clients *
 *******************************************/

bool PcoSalon::accessSalon(unsigned clientId)
{
    monitorIn();
    if (getNbClient() > _capacity) {
        monitorOut();
        return false;
    }

    _clients.push(clientId);

    animationClientAccessEntrance(clientId);

    if (_asleep) {
        signal(_wakeUpBarber);
    }

    if (_clients.front() != clientId) {

        _chairNumber++;
        if (_chairNumber >= _capacity) {
            _chairNumber = 0;
        }

        animationClientSitOnChair(clientId, _chairNumber);
    }

    monitorOut();
    return true;
}


void PcoSalon::goForHairCut(unsigned clientId)
{
    monitorIn();

    if (_clients.front() != clientId) {
        wait(_workingSeatEmpty);
    }

    animationClientSitOnWorkChair(clientId);

    signal(_clientOnChair);
    wait(_waitForHaircut);

    _clients.pop();

    monitorOut();
}

void PcoSalon::waitingForHairToGrow(unsigned clientId)
{
    monitorIn();

    animationClientWaitForHairToGrow(clientId);

    monitorOut();
}


void PcoSalon::walkAround(unsigned clientId)
{
    monitorIn();

    animationClientWalkAround(clientId);

    monitorOut();
}


void PcoSalon::goHome(unsigned clientId)
{
    monitorIn();

    animationClientGoHome(clientId);

    monitorOut();
}


/********************************************
 * Méthodes de l'interface pour le barbier  *
 *******************************************/

unsigned int PcoSalon::getNbClient()
{
    return _clients.size();
}

void PcoSalon::goToSleep()
{
    monitorIn();

    _asleep = true;
    animationBarberGoToSleep();

    wait(_wakeUpBarber);

    animationWakeUpBarber();
    _asleep = false;

    monitorOut();
}


void PcoSalon::pickNextClient()
{
    monitorIn();

    signal(_workingSeatEmpty);

    monitorOut();
}


void PcoSalon::waitClientAtChair()
{
    monitorIn();

    wait(_clientOnChair);

    monitorOut();
}


void PcoSalon::beautifyClient()
{
    monitorIn();

    animationBarberCuttingHair();

    signal(_waitForHaircut);

    monitorOut();
}

/********************************************
 *    Méthodes générales de l'interface     *
 *******************************************/
bool PcoSalon::isInService()
{
    return true;
}


void PcoSalon::endService()
{
    // TODO
}

/********************************************
 *   Méthodes privées pour les animations   *
 *******************************************/
void PcoSalon::animationClientAccessEntrance(unsigned clientId)
{
    monitorOut();
    _interface->clientAccessEntrance(clientId);
    monitorIn();
}

void PcoSalon::animationClientSitOnChair(unsigned clientId, unsigned clientSitNb)
{
    monitorOut();
    _interface->clientSitOnChair(clientId, clientSitNb);
    monitorIn();
}

void PcoSalon::animationClientSitOnWorkChair(unsigned clientId)
{
    monitorOut();
    _interface->clientSitOnWorkChair(clientId);
    monitorIn();
}

void PcoSalon::animationClientWaitForHairToGrow(unsigned clientId)
{
    monitorOut();
    _interface->clientWaitHairToGrow(clientId, true);
    monitorIn();
}

void PcoSalon::animationClientWalkAround(unsigned clientId)
{
    monitorOut();
    _interface->clientWalkAround(clientId);
    monitorIn();
}

void PcoSalon::animationBarberGoToSleep()
{
    monitorOut();
    _interface->barberGoToSleep();
    monitorIn();
}

void PcoSalon::animationWakeUpBarber()
{
    monitorOut();
    _interface->clientWakeUpBarber();
    monitorIn();
}

void PcoSalon::animationBarberCuttingHair()
{
    monitorOut();
    _interface->barberCuttingHair();
    monitorIn();
}

void PcoSalon::animationClientGoHome(unsigned clientId){
    monitorOut();
    _interface->clientWaitHairToGrow(clientId, false);
    monitorIn();
}
