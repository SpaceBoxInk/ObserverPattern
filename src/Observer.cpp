/**
 * @file Observer.cpp
 *
 * Early optimization is the root of all evil
 *
 *  @date 11 nov. 2017
 *  @author nihil
 */
#include <iostream>
#include <typeinfo>
#include "Observer.hpp"

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------
template<class EventName, class Content>
void Observer::addAction(EventName eventName,
    actionMethod<Content> method)
{
  actions.insert(std::make_pair(eventName, method));
}

template<class EventName, class Content>
void Observer::doEventActions(EventName eventName, Content content,
    Observed const& observed) const
{
  using namespace std;
  auto actionsForEvent = actions.equal_range(eventName);
  for (auto i = actionsForEvent.first; i != actionsForEvent.second; ++i)
  {
    i->second(content, observed);
  }
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------
