/*
 * Patron.h
 *
 *  Created on: Oct 29, 2019
 *      Author: Zonghui Wang
 */

#ifndef PATRON_H_
#define PATRON_H_
#include <string>
#include<iostream>
#include<fstream>

#include"Book.h"

using namespace std;

class Patron{
	private:
		int age ;
		int numBooks;
		string* name;  //name of patron
		Book* currentBooks; // courrentBooks is the head pointer to the dynamic Array

		void initialize(string, int);

		void cleanup();


	public:
		Patron(string ,int);
		Patron(const Patron&);
		~Patron();

		int getAge() const;
		int getNumBooks() const;
		string getName() const;

		void addBook(Book&);
		void removeBook(Book&);

		Patron& operator = (const Patron&);
		Book& operator [] (int);
		Book& operator [] (string);

		friend ostream& operator << (ostream& , const Patron&);


};







#endif /* PATRON_H_ */
