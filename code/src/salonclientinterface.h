//     ____  __________ ___   ____ ___  ___
//    / __ \/ ____/ __ \__ \ / __ \__ \|__ \
//   / /_/ / /   / / / /_/ // / / /_/ /__/ /
//  / ____/ /___/ /_/ / __// /_/ / __// __/
// /_/    \____/\____/____/\____/____/____/
//
// Rien à modifier

#ifndef SALONCLIENTINTERFACE_H
#define SALONCLIENTINTERFACE_H


class SalonClientInterface
{
public:
    /*!
     * \brief accessSalon Permet au client de savoir si le salon est plein
     * \return retourne true si le client peut accéder au salon, false s'il est plein
     */
    virtual bool accessSalon(unsigned clientId) = 0;

    /*!
     *  \brief goForHairCut Le client se dirige vers la chaise pour se faire embellir
     */
    virtual void goForHairCut(unsigned clientId) = 0;

    /*!
     *  \brief waitingForHairToGrow Après s'être fait coiffé, le client part et ne revient
     *  pas tant que ses cheuveux n'ont pas repoussé
     */
    virtual void waitingForHairToGrow(unsigned clientId) = 0;

    /*!
     *  \brief walkAround Si le salon est plein, le client va se balader pendant un certains
     *  temps et revenir après avoir pris un petit kawa
     */
    virtual void walkAround(unsigned clientId) = 0;

    /*!
     * \brief isInService Permet de savoir si le salon est ouvert
     * \return retourne vrai si le salon est ouvert
     */
    virtual bool isInService() = 0;

    /*!
     * \brief goHome Permet au client de partir et de quitter la scène
     */
    virtual void goHome(unsigned clientId) = 0;
};

#endif // SALONCLIENTINTERFACE_H
