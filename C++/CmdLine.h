//
//  CmdLine.hpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//

#ifndef CmdLine_h
#define CmdLine_h


#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>


// class Option which is pure virtual
class Option{
protected:
    char c;     // short name
    string nom; // long name
public:
    virtual ~Option(){};
    virtual Option* clone() const=0; // "virtual constructor"
    bool check(char* arg); // recognize an option entered as an argument
    virtual void decode(int& argc, char* arg[])=0; /* give an option the adapted value (true for a bool,
                                                      the entered one for others) */
};



// Function check to see if an argument matches with the Option
bool Option::check(char* arg){
    bool result=false;
    string arg_string(arg+1); // name of entered option without the first character '-'
    string arg_string2(arg+2); // name of entered option without the two first characters '--'
    string c_string(&c);  // conversion of short name from char* into string, long name is already one
    if(arg_string==c_string || arg_string2==nom){ // now we can compare strings
            result=true;
        }
    return result;
}


// class OptionField<T> in the namespace command
namespace command{

/* class OptionField which inherites from class Option
   objects of type OptionField<T> may be different but they all are Option
   so we can put them in a vector as Option* */
template <typename T>
class OptionField: public Option{
    T* var;
public:
    OptionField<T>(char court_name, string long_name, T& variable);
    ~OptionField<T>();
    virtual Option* clone() const; // a "virtual constructor" to stock options in a vector
    virtual void decode(int& argc, char* argv[]); /* the programm reaction to an entered option and possibly
                                             a parameter. This method is different if the type T is a bool */
};
       

// Constructor of OptionField<T>
template <typename T>
OptionField<T>::OptionField(char court_name, string long_name, T& variable){
    c=court_name;
    nom=long_name;
    var=&variable; // the value will be known when the command is entered
}

// Constructor of OptionField<bool>, in which we give the value "false" to the variable
template <>
OptionField<bool>::OptionField(char court_name, string long_name, bool& variable){
    c=court_name;
    nom=long_name;
    var = &variable; // to "initiate" the pointer
    *var= false;
}
       

// make_option method let construct a Option without precising its type
template <typename T>
OptionField<T> make_option(char c, string nom, T& var){
    return OptionField<T>(c, nom, var);
}

    
/* virtual constructor in order to copy an Option and keep a copy of it (in a vector) 
 even if the Option doesn't exist anymore */
template <typename T>
Option* OptionField<T>::clone() const{
    return new OptionField<T>(*this);
}


template<>
void OptionField<bool>::decode(int& argc, char* arg[]){
    (*var)=true; // make the variable true
    for(int i=1; i<argc-1; i++){
        arg[i]=arg[i+1];
    } // only one argument is "put aside", the call to an option which is bool
    argc--;
}


template <typename T>
void OptionField<T>::decode(int& argc, char* arg[]){
    stringstream str;
    str << arg[2];
    T t;
    str >> t;  // conversion from char* to T
    if(!str.fail()){
        (*var)=t;
    }
    for(int i=1; i<argc-2; i++){
        arg[i]=arg[i+2];
    }  // two arguments are "put aside", the call to the option and the parameter of type T
    argc-=2;
}


template <typename T>
OptionField<T>::~OptionField(){
}
       

// class CmdLine
class CmdLine{
    vector <Option*> opt; // to store options of differents type
public:
    ~CmdLine();
    template <typename T>
    void add(command::OptionField<T> option); // to add OptionField in opt
    void process(int& argc, char* argv[]); // to treat entered options
};
       

/* put several OptionField instances in a vector. They can be of different types but they all are Option
   instances so we can fill the vector */
template <typename T>
void CmdLine::add(command::OptionField<T> option){
    opt.push_back(option.clone());
}


// process method helps anlysing entered arguments, checking options and updating argv[]
void CmdLine::process(int& argc, char* argv[]){
    for(int i=1 ; i<argc ;){
        if(argv[i][0]=='-'){ /* all options start by a '-', they may start by two ones as in "--help"
                                if it doesn't start by a '-', it is not an option but a parameter
                                that cannot be decoded */
            
            bool decoded=false; // to know if an option has not been checked and decoded
            
            for(vector<Option*>::iterator option=opt.begin(); option!=opt.end(); ++option){
                if((**option).check(argv[i])){ /* compare each possible option with the argument after
                                                the title */
                    (**option).decode(argc, argv);
                    decoded=true; // here it means that the option has been checked and decoded
                }
            }
            if(!decoded){                                 /* decoded = false means that the entered option is
                                                             not in the vector opt */
                throw string("unknown option ")+argv[i]; //  if an unknown option is entered
            }                                           //   we throw an exception
        }
        else{
            i++;
        }
    }
}


// the destructor of a CmdLine instance just delete the vector opt (which contains pointers on Option)
CmdLine::~CmdLine(){
    for(vector<Option*>::iterator it=opt.begin(); it!=opt.end(); ++it){
        delete *it;
    }
}

}
// end of namespace command scope


#endif /* CmdLine_h */
