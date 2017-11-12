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
 * alias for event function signature
 */
template<class MessageName, class Content>
using actionMethod = std::function<void(Content const&, Observed<Content, MessageName> const&)>;

template<class MessageName, class Content>
class Observer
{
//========================>Attributes<========================
private:
  std::multimap<MessageName, actionMethod<Content, MessageName>> actions;
//=======================>Constructors<=======================
public:
  Observer() = default;
  // TODO: rule of five ? copyandswap
  virtual ~Observer() = default;

private:

//=========================>Methods<==========================
public:
  void addAction(MessageName event, actionMethod<MessageName, Content> method);

  void event(MessageName messageName, Content content,
             Observed<MessageName, Content> const& observed) const;
private:

//=====================>Getters&Setters<======================
public:

private:

};

#include "Observer.cpp"
#endif
