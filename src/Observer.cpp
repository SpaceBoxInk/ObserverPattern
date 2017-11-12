/**
 * Observer.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 11 nov. 2017
 *      Author: nihil
 */
#ifdef OBSERVER_HPP
#include <iostream>
#include <typeinfo>

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------
template<class MessageName, class Content>
void Observer<MessageName, Content>::addAction(MessageName event,
    actionMethod<MessageName, Content> method)
{
  actions.insert(std::make_pair(event, method));
}

template<class MessageName, class Content>
void Observer<MessageName, Content>::event(MessageName messageName, Content content,
    Observed<MessageName, Content> const& observed) const
{
  using namespace std;
  auto actionsForEvent = actions.equal_range(messageName);
  for (auto i = actionsForEvent.first; i != actionsForEvent.second; ++i)
  {
    i->second(content, observed);
  }
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

#endif
