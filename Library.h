/*
 * Library.h
 *
 *  Created on: Oct 29, 2019
 *      Author: Zonghui Wang
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <string>
#include<iostream>
#include<fstream>

#include "Book.h"
#include "Patron.h"

using namespace std;

class Library{
	private:

		int numBooks;
		int numPatrons;
		Book* availableBooks;
		Patron* currentPatrons;
		void initialize (int, int );
		void cleanup();

	public:

		Library();
		~Library();

		void addBook();
		void addPatron();


		void checkOut(int , int );
		void checkIn(int , int );

		Book& operator [] (string);
		Patron& operator [] (int);

		friend ostream& operator << (ostream& , const Patron&);

		void start();


};



#endif /* LIBRARY_H_ */
