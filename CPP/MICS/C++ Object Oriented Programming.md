
-> default access specifier is *private


```cpp
#include<iostream>
using namespace std;

class classname
{
  private:
        //member variables
        //member variables
  public:
        //member variables
        //member variables
  protected:
        //member variables
        //member variables
};
int main()
{
 //statements;
}


```

## class
-> class is a template or Blueprint which consists set of variables and functions
-> class is a logical or passive
### syntax:
```cpp
class class_name
{
  private:
        //member variables
        //member variables
  public:
        //member variables
        //member variables
  protected:
        //member variables
        //member variables
}; 
```

Example:
```cpp
class Fruit
{
   pulbic:
          string fname;
        void display(string name)
        {
             fname=name;
             count<<fname;
        }
}
```

## object:
-> It is an instance of a class or it is a real world entity which is distingiushable form other entities.
-> Object is Physical
-> Any number of objects can be created for the same class

### syntax:

```cpp
class_name object_name;
```

### Example:
```cpp
Fruit Mango;
```


-> Member of a class can be accessed by using object_name.member_name

```cpp
#include<iostream>
using namespace std;
class Fruit
{
   pulbic:
          string fname;
        void display(string name)
        {
             fname=name;
             count<<fname;
        }
};

int main()
{
  Fruit f1;
  f1.display("mango");
}
```

## Encapsulation:

-> Wraping up of data variables and functions into a single unit is called as an encapsulation.
-> It provides data security with the help of access specifiers
-> The accesss specifiers are private, public and protected
-> The default access specifier in CPP is Private
-> class is an example for encapsulation

## Abrastraction:

-> It is used to hide implementation/internal details
-> It can be achieved using virtual function

## Inheritance:

-> It is a process of aquiring properties from one class to another class
- like parent_class -> child_class
- base_class -> Derived_class
- super_class -> sub_class
### Types of Inheritance:

-> Single inheritance
-> multiple inheritance
-> multi level
-> hybrid
-> hierarchial
### Single Inheritance
#### Syntax:
```cpp
classs parentclassname
{
  // memebers
}
class child_class_name:accessspecifier;
```
#### Example:

```cpp
class A
{
  public:
       int a;
};
class B: public A
{
 public int b;
};
```



## Polymorphism:
-> It exibits in different forms

### Types of polymorphism:
-> Compiletime poly
- overriding
-> Runtime
- overloading