/**
 * @file Observed.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 11 nov. 2017
 *      Author: nihil
 */

#include "Observed.hpp"

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------
Observed::Observed(): changed(false)
{
}

//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------


void Observed::deleteObservers()
{
  observers.clear();
}


template<class EventName, class Content>
void Observed::notifyObserver(EventName eventName,
    Content content)
{
  if (hasChanged())
  {
    for (Observer const* obs : observers)
    {
      obs->doEventActions(eventName, content, *this);
    }
  }
  clearChanged();
}

