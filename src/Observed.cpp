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
Observed<MessageName, Content>::Observed(): changed(false)
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
inline void Observed<MessageName, Content>::deleteObserver(
    Observer<MessageName, Content>* observer)
{
  observers.erase(std::find(observers.begin(), observers.end(), observer));
}

/**
 * delete all observers for this Observed object
 */
template<class MessageName, class Content>
void Observed<MessageName, Content>::deleteObservers()
{
  observers.clear();
}

/**
 * @return the number of subscribed Observers
 */
template<class MessageName, class Content>
inline int Observed<MessageName, Content>::countObservers() const
{
  return observers.size();
}

template<class MessageName, class Content>
inline void Observed<MessageName, Content>::notifyObserver(MessageName messageName,
    Content content)
{
  if (hasChanged())
  {
    for(Observer<MessageName, Content>const* obs : observers)
    {
      obs->event(messageName, content, *this);
    }
  }
  clearChanged();
}

//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------
template<class MessageName, class Content>
inline bool Observed<MessageName, Content>::hasChanged() const
{
  return changed;
}

template<class MessageName, class Content>
inline void Observed<MessageName, Content>::setChanged()
{
  changed=true;
}

template<class MessageName, class Content>
inline void Observed<MessageName, Content>::clearChanged()
{
  changed=false;
}
#endif
