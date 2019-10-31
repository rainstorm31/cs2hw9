/*
 * Book.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Zonghui Wang
 */

#include "Book.h"


#include <string>
#include<iostream>
#include<fstream>
using namespace std;

Book::Book(string i , string t , string a , string g ){

	cout << "constructor of Book/n";
	 i = " ";
	 t = " ";
	 a = " ";
	 g = " ";

	initialize(i,t,a,g );

	}

Book::Book(const Book& copyObj){

	cout << "copy constructor of Book/n";
	initialize(copyObj.getISBN(),copyObj.getTitle(),copyObj.getAuthor(),copyObj.getGenre());



}


Book::~Book(){
	cout << "destructor of Book/n ";

	cleanup();
}

void Book::initialize (string i , string t , string a , string g){
	cout << "initialize the book Obj/n";
	isbn = new string (i);
	title = new string (t);
	author = new string (a);
	genre = new string (g);
}


void Book :: cleanup(){

	cout << "clean up the Book Obj/n";
	delete isbn ;
	delete title;
	delete author;
	delete genre;
}


string Book::getISBN()const{

	return* isbn;
}

string Book::getTitle()const{

	return* title;
}

string Book::getAuthor()const{

	return* author;
}

string Book::getGenre()const{

	return* genre;
}


Book& Book::operator = (const Book& rightObj){
	Book* myBook ;  // myBook is the ptr
	cout <<"overload (=) assignment operator \n";
	initialize(rightObj.getISBN(),rightObj.getTitle(),rightObj.getAuthor(),rightObj.getGenre());
	*myBook->isbn = rightObj.getISBN();
	*myBook->title = rightObj.getTitle();
	*myBook->author = rightObj.getAuthor();
	*myBook->genre = rightObj.getGenre();

	return *this; // myBook ptr ?

}

bool Book:: operator == (const Book& rightObj) const{
	cout << "overload (==)assignment operator\n";

	if ((this->getISBN() == rightObj.getISBN()) &&
		(this->getTitle() == rightObj.getTitle()) &&
		(this->getAuthor() == rightObj.getAuthor()) &&
		(this->getGenre() == rightObj.getGenre())
		)
		return true;

	else
		return false ;
}

bool Book:: operator != (const Book& rightObj) const{
	cout << "overload (==)assignment operator\n";

	if ((this->getISBN() != rightObj.getISBN()) ||
		(this->getTitle() != rightObj.getTitle()) ||
		(this->getAuthor() != rightObj.getAuthor()) ||
		(this->getGenre() != rightObj.getGenre())
		)
		return true;

	else
		return false ;
}

ostream&  operator <<(ostream& outStream, const Book& myBook){
	 cout <<"overloaded (<<) stream insertion operator\n" << endl;

	 outStream <<"---Printing Report for Book object ---\n" << endl;
	 outStream <<"ISBN : "<< myBook.getISBN() << endl;
	 outStream <<"Title : "<< myBook.getTitle() << endl;
	 outStream <<"Author : "<< myBook.getAuthor() << endl;
	 outStream <<"Genre : "<< myBook.getGenre() << endl;
	 outStream <<"---End of the Book report !---"<< endl;

    return outStream ;
}



