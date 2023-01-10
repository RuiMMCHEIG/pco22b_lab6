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
    : _interface(interface)
{
    // TODO
}

/********************************************
 * Méthodes de l'interface pour les clients *
 *******************************************/
unsigned int PcoSalon::getNbClient()
{
    // TODO
}

bool PcoSalon::accessSalon(unsigned clientId)
{
    // TODO
}


void PcoSalon::goForHairCut(unsigned clientId)
{
    // TODO
}

void PcoSalon::waitingForHairToGrow(unsigned clientId)
{
    // TODO
}


void PcoSalon::walkAround(unsigned clientId)
{
    // TODO
}


void PcoSalon::goHome(unsigned clientId){
    // TODO
}


/********************************************
 * Méthodes de l'interface pour le barbier  *
 *******************************************/
void PcoSalon::goToSleep()
{
    // TODO
}


void PcoSalon::pickNextClient()
{
    // TODO
}


void PcoSalon::waitClientAtChair()
{
    // TODO
}


void PcoSalon::beautifyClient()
{
    // TODO
}

/********************************************
 *    Méthodes générales de l'interface     *
 *******************************************/
bool PcoSalon::isInService()
{
    // TODO
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
