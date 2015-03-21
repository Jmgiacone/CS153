/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#include "FourDPackage.h"

float FourDPackage::getCharge() const
{
  return m_length * m_width * m_height * m_time * FOURDCONSTANT + m_weight * FOURDRATE + EXTRA_DIMENSIONAL_HANDLING;
}
