//
//  Tools.cpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//


#include "Tools.h"
#include <cstdlib>  /* rand() */


////
//// Return uniformly a random floating value between 0 and 1
////
//float randomUniform(){
//    return rand()/double(RAND_MAX);
//}
//
////
//// Return uniformly a random floating value between a and b
////
//float random(const float &a, const float &b){
//    return a + randomUniform()*(b-a);
//}
//
////
//// Return uniformly a random floating value  between 0 and a
////
//float random(const float &a){
//    return random(0,a);
//}


//
// Return a random integer between 0 and a
//
int random(const int &a){
    return rand()%a;
}

//
// Return a random integer between a and b
//
int random(const int &a, const int &b){
    return a + random(b-a);
}



//// Display a vector of templates
//template<typename T>
//ostream &operator<<(ostream &os, vector<Point2D> const &v) {
//    for(typename vector<T>::iterator it = v.begin(); it != v.end(); ++it){
//        cout << *it << "  /  ";
//    }
//}
//
//template<typename T>
//ostream &operator<<(ostream &os, vector<Point2D*> const &v) {
//    for(typename vector<T>::iterator it = v.begin(); it != v.end(); ++it){
//        cout << **it << "  /  ";
//    }
//}
//
//
//// Display a set of templates
//template<typename T>
//ostream &operator<<(ostream &os, set<T> const &s) {
//     for(typename set<T>::iterator it = s.begin(); it != s.end(); ++it){
//        os << *it << "  /  ";
//    }
//    return os << " ";
//}
//
//template<typename T>
//ostream &operator<<(ostream &os, set<T*> const &s) {
//    for(typename set<T>::iterator it = s.begin(); it != s.end(); ++it){
//        os << **it << "  /  ";
//    }
//    return os << " ";
//}



// Display a vector of Point2D
void display(const vector<Point2D> &v) {
    if(v.empty()){
        cout << "vect{" << v.size() << " : this vector is empty}" << endl;
    }
    else{
        cout << "vect{" << v.size() << " : " << *(v.begin());
        for(vector<Point2D>::const_iterator it = v.begin()+1 ; it != v.end(); ++it){
            cout << " / " << *it;
        }
        cout << "}" << endl;
    }
    
}

void display(const vector<Point2D*> &v) {
    if(v.empty()){
        cout << "vect{" << v.size() << " : this vector is empty}" << endl;
    }
    else{
        cout << "vect{" << v.size() << " : " << **(v.begin());
        for(vector<Point2D*>::const_iterator it = v.begin()+1 ; it != v.end(); ++it){
            cout << " / " << **it;
        }
        cout << "}" << endl;
    }
}


// Display a set of Point2D
void display(const set<Point2D> &s) {
    if(s.empty()){
        cout << "set{" << s.size() << " : this set is empty}" << endl;
    }
    else{
        cout << "set{" << s.size() << " : " << *(s.begin());
        for(set<Point2D>::const_iterator it = ++s.begin(); it != s.end(); ++it){
            cout << " / " << *it;
        }
        cout <<  "}" << endl;
    }
}

void display(const set<Point2D*> &s) {
    if(s.empty()){
        cout << "set{" << s.size() << " : this set is empty}" << endl;
    }
    else{
        cout << "set{" << s.size() << " : " << **(s.begin());
        for(set<Point2D*>::const_iterator it = ++s.begin(); it != s.end(); ++it){
            cout << " / " << **it;
        }
        cout << "}" << endl;
    }
}