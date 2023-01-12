//     ____  __________ ___   ____ ___  ___
//    / __ \/ ____/ __ \__ \ / __ \__ \|__ \
//   / /_/ / /   / / / /_/ // / / /_/ /__/ /
//  / ____/ /___/ /_/ / __// /_/ / __// __/
// /_/    \____/\____/____/\____/____/____/
//
// Modifications à faire dans le fichier

#include "barber.h"
#include <unistd.h>

#include <iostream>

Barber::Barber(GraphicSalonInterface *interface, std::shared_ptr<SalonBarberInterface> salon)
    : _interface(interface), _salon(salon)
{
    _interface->consoleAppendTextBarber("Salut, prêt à travailler !");
}

void Barber::run()
{
    while (_salon->isInService()) {
        if (_salon->getNbClient() > 0) {

            _salon->pickNextClient();
            _interface->consoleAppendTextBarber("Client suivant !");
        }
        else {

            _salon->goToSleep();
            _interface->consoleAppendTextBarber("zZzZz...");
        }

        _salon->waitClientAtChair();
        _interface->consoleAppendTextBarber("Ce sera quelle coupe ?");

        _salon->beautifyClient();
        _interface->consoleAppendTextBarber("Et une coupe pour monsieur !");
    }

    _interface->consoleAppendTextBarber("La journée est terminée, à demain !");
}
