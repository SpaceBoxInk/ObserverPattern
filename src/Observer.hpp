/**
 * @file Observer.hpp
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

class Observed;

/**
 * @brief alias for event function signature <br>
 * @code void(Content const&, Observed<Content, EventName> const&) @endcode
 *
 * with lambda :
 * @code
 * auto action1 = [](Content const& content, Observed<Content, EventName> const& Obs)
 * {
 *  std::cout << content;
 * };
 * @endcode
 */
template<class Content>
using actionMethod = std::function<void(Content const&, Observed const&)>;

/**
 * @class Observer
 * @brief it's the Observer of the Observer pattern
 * this class is a attempt to recieve event from #Observed by subscription system
 *
 * @tparam EventName is the type for the event names
 * @tparam Content is the type for the event's content
 *
 * @see Observed::addObserver(Observer<EventName, Content> const* observer)
 */
class Observer
{
//========================>Attributes<========================
private:
  /**
   * @brief the list of actions handle by event name
   */
  std::multimap actions;
//=======================>Constructors<=======================
public:

  template<class EventName, class Content>
  Observer();
  // TODO: rule of five ? copyandswap
  virtual ~Observer() = default;

private:

//=========================>Methods<==========================
public:
  /**
   *
   * @param eventName the name of this action which is called when an event of the same name is send
   * @param method the event behavior, the method/lambda defined for a specific event
   * @see Observed::notifyObserver(EventName eventName, Content content)
   */
  template<typename EventName, typename Content>
  void addAction(EventName eventName, actionMethod<Content> method);

  /**
   * @brief method called by the #Observed when an event is send
   *
   * @param eventName the name for the event
   * @param content the content message of the event
   * @param observed the source of the event
   * @note do not call this method, it's called automatically by #Observed
   */
  template<class EventName, class Content>
  void doEventActions(EventName eventName, Content content,
             Observed const& observed) const;
private:

//=====================>Getters&Setters<======================
public:

private:

};

template<class EventName, class Content>
inline Observer::Observer() :
    actions(std::map<EventName, Content>())
{

}

#endif
