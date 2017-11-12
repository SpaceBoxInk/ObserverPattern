/**
 * Observer.hpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 11 nov. 2017
 *      Author: nihil
 */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <map>
#include <functional>

template<class MessageName, class Content>
class Observed;

/**
 * alias for function signature of
 */
template<class MessageName, class Content>
using actionMethod = std::function<void(Content&, Observed<Content, MessageName>&)>;

template<class MessageName, class Content>
class Observer
{
//========================>Attributes<========================
private:
  std::multimap<MessageName, actionMethod<Content, MessageName>> actions;
//=======================>Constructors<=======================
public:
  Observer();
  // TODO: rule of five ? copyandswap
  virtual ~Observer();

private:

  //=========================>Methods<==========================
public:
  void addAction(MessageName event, actionMethod<MessageName, Content> method);

  void event(MessageName messageName, Content content,
             Observed<MessageName, Content>& observed);
private:

  //=====================>Getters&Setters<======================
public:

private:

};


#include "Observer.cpp"
#endif
