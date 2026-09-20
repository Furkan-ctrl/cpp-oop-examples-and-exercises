#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Polymorphism in a Backend Application

    Scenario:
    You are developing a backend application for a library management system. 
    The application needs to handle various types of items in the library, such as books, e-books, and audio CDs. 
    Each of these items has specific properties and actions associated with them.

    Requirements:

    1. Create a base class called LibraryItem with the following properties and methods:
        Properties:
        title (string): The title of the library item.
        year (int): The year of publication.
        Methods:
        virtual void checkout(): A virtual function that marks the item as checked out.
        virtual void checkin(): A virtual function that marks the item as checked in.
        virtual void displayInfo(): A virtual function that displays information about the item, 
        including its title and year of publication.

    2. Create three derived classes: Book, EBook, and AudioCD, each inheriting from LibraryItem. 
       These classes should have their own specific properties and methods:
        Book:
        Properties:
        author (string): The author of the book.
        Methods:
        Override the displayInfo() method to include information about the author.
        EBook:
        Properties:
        format (string): The format of the e-book (e.g., PDF, EPUB).
        Methods:
        Override the displayInfo() method to include information about the format.
        AudioCD:
        Properties:
        artist (string): The artist of the audio CD.
        Methods:
        Override the displayInfo() method to include information about the artist.

    3. In the main() function, create instances of Book, EBook, and AudioCD objects, each representing a library item.
    4. Create an array of pointers to LibraryItem objects and store the addresses of the items in the array.
    5. Use a loop to iterate through the array and perform the following actions:
        Check out and check in each item to simulate library operations.
        Display information about each item using the displayInfo() method.
    

    Example Output:

    Book Title: "The Great Gatsby"
    Author: F. Scott Fitzgerald
    Year: 1925
    Status: Checked out

    EBook Title: "The Hitchhiker's Guide to the Galaxy"
    Format: EPUB
    Year: 1979
    Status: Checked in

    Audio CD Title: "Abbey Road"
    Artist: The Beatles
    Year: 1969
    Status: Checked out

*/

// Solution
class LibraryItem {
protected:
    string title;
    int year;
    bool isCheckedOut;

public:
    LibraryItem(string t, int y) : title(t), year(y), isCheckedOut(false) {}
    virtual void checkout() {
        isCheckedOut = true;
    }

    virtual void checkin() {
        isCheckedOut = false;
    }

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (isCheckedOut ? "Checked out" : "Checked in") << endl;
    }
};

class Book : public LibraryItem {
private:
    string author;

public:
    Book(string t, int y, string a) : LibraryItem(t, y), author(a) {}
    void displayInfo() override {
        LibraryItem::displayInfo();
        cout << "Author: " << author << endl;
    }

};

class EBook : public LibraryItem {
private:
    string format;

public:
    EBook(string t, int y, string f) : LibraryItem(t, y), format(f) {}
    void displayInfo() override {
        LibraryItem::displayInfo();
        cout << "Format: " << format << endl;
    }

};

class AudioCD : public LibraryItem {
private:
    string artist;

public:
    AudioCD(string t, int y, string a) : LibraryItem(t, y), artist(a) {}
    void displayInfo() override {
        LibraryItem::displayInfo();
        cout << "Artist: " << artist << endl;
    }

};


int main() {

    /*      Example usage:     */ 
 Book book("The Great Gatsby", 1925, "F. Scott Fitzgerald");
    EBook ebook("The Hitchhiker's Guide to the Galaxy", 1979, "EPUB");
    AudioCD audioCD("Abbey Road", 1969, "The Beatles");

    LibraryItem* items[] = { &book, &ebook, &audioCD };

    for (LibraryItem* item : items) {
        item->checkin();
        item->displayInfo();
        cout << endl;
        item->checkout();
    }

    

    return 0;
}
