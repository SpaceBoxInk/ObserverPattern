/**
 * @file Test.cpp
 * @example
 */

#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

//class TestObserved : public Observed
//{
//private:
//  bool shown;
//public:
//
//  TestObserved() :
//      shown(false)
//  {
//
//  }
//
//  void show()
//  {
//    shown = true;
//    cout << "IHM stuff and waiting for input :" << endl;
//    string key;
//    std::getline(cin, key);
//    // say that the object state has changed
//    setChanged();
//    // and then notify observers with the event name : "Test" and content key
//    notifyObserver("Test", key);
//
//    doOtherIhmStuff();
//  }
//
//  /**
//   * another test to send event
//   */
//  void doOtherIhmStuff()
//  {
//    cout << "Other IHM stuff" << endl;
//    if (isShown())
//    {
//      setChanged();
//    }
//    notifyObserver("Test2", "other Ihm input");
//  }
//
//  bool isShown()
//  {
//    return bool();
//  }
//};
//
//class TestObserver : public Observer
//{
//private:
//  TestObserved vTest;
//public:
//  // Make a function that return a lambda
//  /**
//   * Make a function that return a lambda
//   * @return the lambda for event "Test"
//   */
//  auto eventTest()
//  {
//    return [](string const& content, Observed const& observed) -> void
//    {
//      cout <<"Message : " << content << " from object : ";
//      cout << typeid(observed).name() << " recieved !" << endl;
//    };
//  }
//
//  TestObserver() :
//      vTest()
//  {
//    vTest.addObserver(this);
//    // call the function returning the lambda
//    addAction("Test", eventTest());
//
//    // or use directly a lambda function
//    addAction("Test2",
//              [](string const& content, Observed const& observed) -> void
//              {
//                cout <<"Message : " << content << " from object : ";
//                cout << typeid(observed).name() << " recieved !" << endl;
//              });
//
//    vTest.show();
//  }
//
//};

int main()
{
  std::map<string, string>* s = new std::map<string, string>();
  std::map vz(*s);
  delete s;
  vz.insert(make_pair("e", "test"));
  cout << vz["e"];
}
