/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#ifndef TWODPACKAGE_H
#define TWODPACKAGE_H
#include "abstractpackage.h"

const float TWODRATE = .05;

class TwoDPackage : public AbstractPackage
{
protected:
    float m_length, m_width, m_weight;
public:
    TwoDPackage(string from, string to, float l, float width, float weight) : AbstractPackage(from, to), m_length(l), m_width(width), m_weight(weight) {}

    // Purpose: Returns the charge of a package.
    virtual float getCharge() const;

    // Purpose: Returns the package's sender.
    string getFrom() const;

    // Purpose: Returns the package's receiver.
    string getTo() const;
};
#endif
