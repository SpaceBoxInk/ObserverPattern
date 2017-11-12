/**
 * Observed.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 11 nov. 2017
 *      Author: nihil
 */
#ifdef OBSERVED_HPP

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------
template<class MessageName, class Content>
Observed<MessageName, Content>::Observed()
{
}
template<class MessageName, class Content>
Observed<MessageName, Content>::~Observed()
{
}
//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------

template<class MessageName, class Content>
inline void Observed<MessageName, Content>::addObserver(
    Observer<MessageName, Content>* observer)
{
  observers.push_back(observer);
}

template<class MessageName, class Content>
inline void Observed<MessageName, Content>::notifyObserver(MessageName messageName,
    Content content)
{
  for(Observer<MessageName, Content>* obs : observers)
  {
    obs->event(messageName, content, *this);
  }
}

//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------
#endif
