# ObserverPattern in c++
## Overview
This is an implementation of the observer pattern in c++, it use c++17 with template class only (no #define !)
And take care of the event actions of observers linked to envent send by the observed.
## Installation
just put the 4 files of class for Observed and Observer in your project and compile with -std=c++17 (or c++1z)
## Documentation
- [Lambda Functions in c++](http://en.cppreference.com/w/cpp/language/lambda)
- [Lambda explained in video](https://www.youtube.com/watch?v=uk0Ytomv0wY)
- [Short resume to lambda function](https://www.youtube.com/watch?v=Fg4TNhIQgNM)
## Exemple
Here an exemple of an Observer class implementation :
```c++
// we herit of the Observer class and we specify that
// the type of event names is string
// and the type of event content is string
class EffectiveObserver : public Observer<string, string>
{
private:
  EffectiveObserved vTest;
public:

  // this is our event action for event "Test"
  /**
   * Make a function that return a lambda
   * @return the lambda for event "Test"
   */
  auto eventTest()
  {
    //the content is a string v
    return [](string const& content, Observed<string, string> const& observed) -> void
    {
      cout <<"Message : " << content << " from object : ";
      cout << typeid(observed).name() << " recieved !" << endl;
    };
  }
  
  // here is the constructor
  EffectiveObserver() :
      vTest()
  {
    // we subscribe this observer to the observed vTest
    vTest.addObserver(this);
    // call the function returning the lambda
    // and link the action to the event name "Test"
    addAction("Test", eventTest());

    // or use directly a lambda function
    addAction("Test2",
              [](string const& content, Observed<string, string> const& observed) -> void
              {
                cout <<"Message : " << content << " from object : ";
                cout << typeid(observed).name() << " recieved !" << endl;
              });

    vTest.show();
  }

};
```
This is the function signature for event actions :
```c++
void(Content const&, Observed<Content, EventName> const&)

// aliased by
using actionMethod = std::function<void(Content const&, Observed<Content, EventName> const&)>;

// a lambda :
auto action = [](Content const&, Observed<Content, EventName> const&) -> void 
  {
    // do action [...]
  }
```
Here is the Observed class :
```c++
class EffectiveObserved : public Observed<string, string>
{
private:
  bool shown;
public:

  EffectiveObserved() :
      shown(false)
  {

  }

  void show()
  {
    shown = true;
    cout << "IHM stuff and waiting for input :" << endl;
    string key;
    std::getline(cin, key);
    
    // say that the object state has changed
    setChanged();
    // and then notify observers with the event name : "Test" and content key
    notifyObserver("Test", key);

    doOtherIhmStuff();
  }

  /**
   * another test to send event
   */
  void doOtherIhmStuff()
  {
    cout << "Other IHM stuff" << endl;
    if (isShown())
    {
      setChanged();
    }
    notifyObserver("Test2", "other Ihm input");
  }

  // getter for shown
  bool isShown()
  {
    return bool();
  }
};
```
The main :
```c++
int main()
{
  TestObserver();
}
```
And that's all ;)\
the method link to the event name is called automatically.
