/*
 * Patron.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Zonghui
 */

#include "Book.h"
#include "Patron.h"
#include "Library.h"

#include <string>
#include<iostream>
#include<fstream>
using namespace std;

Patron::Patron( string n, int a){
	cout << "constructor of Patron"<<endl;

	 n= " ";
	 a = 0;
	 //b = 0;  //? should b come from library

	 initialize(n, a );
}

Patron::Patron(const Patron& copyObj){
	cout <<" copy constructor of Patron"<<endl;
	initialize(copyObj.getName(),copyObj.getAge());

}

Patron :: ~Patron(){
	cout << "destruct Patron obj " << endl;
	cleanup();
}


void Patron :: initialize(string n, int a  ){
	 age = a ;
	 numBooks = 10;
	 name = new string (n);



	 for (int i = 0; i<numBooks; i++){
		 currentBooks[i]; // build b Book constructors for this patron
	 }
		 // ? initialize each book item ?
}



void Patron :: cleanup(){
	cout << "Destruct Patron"<<endl;
	delete name;
	delete []currentBooks;
}

int Patron :: getAge()const{
	return age;
}

int Patron :: getNumBooks() const {
	return numBooks;
}

string Patron :: getName() const {
	return *name;
}

void Patron :: addBook(Book&) {
  numBooks ++;
}

void Patron :: removeBook(Book&){;
  numBooks -- ;
}



Patron& Patron :: operator = (const Patron& rightObj){

	cout <<"overload (=) assignment operator for Patron"<<endl;

	Patron *myPatron;  // ptr of obj

	myPatron->age = rightObj.getAge();
	*myPatron->name = rightObj.getName();
	myPatron->numBooks = rightObj.getNumBooks();

	for (int i = 0 ; i < numBooks; i++){		// use the "=" opereator of Book
		myPatron->currentBooks[i] = rightObj.currentBooks[i];
	}

}

Book& Patron :: operator [] (int index){

    cout << "overloaded ([]) subscript operator"<<endl;
    return currentBooks[index];

}

Book& Patron :: operator [] (string index){

	cout << "overloaded ([]) subscript operator (string)\n";

	Book* copyCurrentBooks;
	copyCurrentBooks = currentBooks;
	    for (int i = 0; i < numBooks; i++) {
	        if (to_string(i) == index) {
	            return copyCurrentBooks[i];
	        }
	        else{
	        	cout<< "no such book checked out for " << name << endl;
	        }
	    }

}

ostream&  operator <<(ostream& outStream, const Patron& myPatron){
	 cout <<"overloaded (<<) stream insertion operator\n" << endl;

	 outStream <<"---Current Patron---\n" << endl;
	 outStream <<"Name : "<< myPatron.getName() << endl;
	 outStream <<"Age : "<< myPatron.getAge() << endl;
	 outStream <<"Number of Books checked out : "<< myPatron.getNumBooks() << endl;


    return outStream ;
}
