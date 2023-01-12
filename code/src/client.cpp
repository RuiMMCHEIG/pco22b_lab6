//     ____  __________ ___   ____ ___  ___
//    / __ \/ ____/ __ \__ \ / __ \__ \|__ \
//   / /_/ / /   / / / /_/ // / / /_/ /__/ /
//  / ____/ /___/ /_/ / __// /_/ / __// __/
// /_/    \____/\____/____/\____/____/____/
//
// Modifications à faire dans le fichier

#include "client.h"
#include <unistd.h>

#include <iostream>

int Client::_nextId = 0;

Client::Client(GraphicSalonInterface *interface, std::shared_ptr<SalonClientInterface> salon)

    : _interface(interface), _salon(salon),  _clientId(_nextId++)
{
    _interface->consoleAppendTextClient(_clientId, "Salut, prêt pour une coupe !");
}

void Client::run()
{
    while (_salon->isInService()) {

        if (_salon->accessSalon(_clientId)) {

            _salon->goForHairCut(_clientId);
            _interface->consoleAppendTextClient(_clientId, "C'est mon tour ? Je prendrais... cette coupe !");

            _salon->waitingForHairToGrow(_clientId);
            _interface->consoleAppendTextClient(_clientId, "Merci ! Je reviendrai quand j'aurais des cheveux !");
        }
        else {
            _salon->walkAround(_clientId);
            _interface->consoleAppendTextClient(_clientId, "C'est pas libre ? Je reviendrais plus tard !");
        }
    }

    _salon->goHome(_clientId);
    _interface->consoleAppendTextClient(_clientId, "Le salon est fermé... Zut !");
}
