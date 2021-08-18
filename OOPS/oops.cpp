#include <bits/stdc++.h>
using namespace std;
// virtual functions
class Base{
    public:
      virtual string classCalled(){ return "BaseClass";} 
};
class Derived1 : public Base{
    public :
        virtual string classCalled() { return "DerivedClass1"; }
};
class Derived2 : public Base{
    public :
        virtual string classCalled() { return "DerivedClass2"; }
};
int main(){
    
    Base *baseobj;
    Derived1 derivedobj1;
    baseobj = &derivedobj1;
    cout<<baseobj->classCalled()<<endl;
    Derived2 derivedobj2;
    baseobj = &derivedobj2;
    cout << baseobj->classCalled() << endl;

    return 0;
}
