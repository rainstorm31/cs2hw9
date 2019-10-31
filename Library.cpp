/*
 * Library.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Zonghui Wang
 */
#include <string>
#include<iostream>
#include<fstream>

#include "Book.h"
#include "Patron.h"
# include "Library.h"

using namespace std;

Library ::Library(){

	cout <<" construct Library obj "<<endl;


	initialize( numBooks , numPatrons);



}

Library::~Library(){
	cout << " destruct the Library obj " << endl;
	cleanup();
}

void Library :: initialize (int b, int p){

	numBooks = b;
	numPatrons = p;

	/*Book* availableBooks;
	Patron* currentPatrons;

	for (int i = 0 ; i< numBooks; i++){
		availableBooks[i]; // build the books array for library
	}

	for (int j = 0; j < numPatrons; j++){
		currentPatrons[j]; // build the array for the patrons
	}
	*/
}


void Library :: cleanup(){

	cout << "destruct the library obj "<< endl;

	delete []availableBooks;

	delete []currentPatrons;
}


void Library :: addBook(){  // addBook to the library

	string i;
	string t;
	string a;
	string g;




	cout << "Enter ISBN : ";
	getline (cin, i);

	cout << "Enter Title : ";
	getline (cin,t);

	cout << "Enter Author : ";
	getline (cin, a);

	cout << "Enter Genre : ";
	getline (cin, g);

	Book avilableBooks(i,t,a,g);

	numBooks ++ ;

}

void Library :: addPatron(){
	int a;

	string n;

	cout << "Enter the name of the patron :";
	getline(cin,n);

	cout << "Enter the age of the patron :";
	cin >> a;

	Patron libraryPatron(n,a);

	numPatrons ++ ;

}

void Library :: checkOut( int pi, int bi){ // pi = patron index ; bi = book index from library


}

