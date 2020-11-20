//including necessary libraries (preprocessor directives) and namespace 
#include <iostream>  
#include <iomanip> 
#include <fstream> 
#include <string> 
#include <iomanip> 
#include <map>

//using namespace std; 

struct book {
  book() = default;
  book(int id, std::string title, std::string author,
      int pages, int year, int quantity,
      double price) :
      id_(id),
      title_(title), author_(author),
      pages_(pages), year_(year), quantity_(quantity),
      price_(price) {};

  std::string title_;
  std::string author_;
  int id_;
  int pages_;
  int quantity_;
  int year_;
  double price_;
};

int main() { 
  std::map<int, book> catalog; 

  //defining necessary variables 
  std::ifstream fromfile; //file variable for writing data from the file 
  std::ofstream tofile;   //file variable for writing data into the file 
  //string variables used to store title and author names of the books 
  std::string title, author;  
  //numeric variables used to store integer and double values of the books' data 
  int  choice, id, pages, quantity, year;  
  double price;  
  //a do while loop and the start of the program, used do while to display menu at least once 
  do { 
    //display the menu for the user 
    std::cout << "Library System" << std::endl; 
    std::cout << "[1] Add book" << std::endl; 
    std::cout << "[2] Update book" << std::endl; 
    std::cout << "[3] Remove book" << std::endl; 
    std::cout << "[4] List books" << std::endl; 
    std::cout << "[5] Books whose quantity < 5" << std::endl; 
    std::cout << "[6] Books above the given price" << std::endl; 
    std::cout << "[7] Books above the average price" << std::endl; 
    std::cout << "[8] Library statistics" << std::endl; 
    std::cout << "[9] Exit" << std::endl; 
    //asking for user's choice/input 
    std::cout << "\nEnter your choice: "; 
    std::cin >> choice; 
    std::cout << std::endl; 
    //input verification to make sure user input was valid 
    if (choice >= 1 && choice <= 9) { 
      //switch statement to enter code/instructions for program to execute based off of user input 
      switch (choice) { 
      case 1: //adding data to the file 
        {
          //opening the file in appending mode to add data to it 
///         tofile.open("BookData.txt", std::ios::app); 
///          tofile << "\n"; //new line at start to seperate different books and avoid errors 
          //Asking the user to add new data to the file and adding a tab to keep file format consistent  
          std::cout << "Enter the details for the new book:" << std::endl; 
          std::cout << "ID: "; 
          std::cin >> id;  
///         tofile << id << "\t"; 
          std::cout << "Title: "; 
          std::cin.ignore();  
          getline(std::cin, title); 
///        tofile << title << "\t"; 
          std::cout << "First Author: "; 
          getline(std::cin, author); 
///         tofile << author << "\t"; 
          std::cout << "Total-Pages: "; 
          std::cin >> pages; 
///         tofile << pages << "\t"; 
          std::cout << "Quantity: "; 
          std::cin >> quantity; 
///          tofile << quantity << "\t"; 
          std::cout << "Year: "; 
          std::cin >> year; 
///         tofile << year << "\t"; 
          std::cout << "Price(QAR): "; 
          std::cin >> price; 
///         tofile << price; 
          tofile.close(); //closing file 
          std::cout << std::endl; //to make output on screen neater and more organised by seperating user input section from menu 
          book bk(id, title, author, pages, year, quantity, price);
          catalog.emplace(id, bk);
        }
        break; 

      case 2: break; 
      case 3: break; 

      case 4: //printing a list of the file's data 
        //printing the table headers/titles 
        std::cout << "-------------------------------------------------------------------------------------------------------------------------------" << std::endl; 
        std::cout << "ID"  << std::setw(20)
                  << "Title"  << std::setw(40)
                  << "First Author" << std::setw(18)
                  << "Total-Pages" << std::setw(12)
                  << "Quantity" << std::setw(7)
                  << "Year" << std::setw(13)
                  << "Price(QAR)" << std::setw(14)
                  << "Total-Price" << std::endl; 
        std::cout << "-------------------------------------------------------------------------------------------------------------------------------" << std::endl; 
        fromfile.open("BookData.txt", std::ios::in); //opening file in input mode to read 
        //statements will be looped until the end of the file is reached 
        while (!fromfile.eof()) { 
          fromfile.ignore(); //ignoring the '\n' character at the start of each line  
          fromfile >> id; 
          fromfile.ignore(); //to avoid errors and ensure data gets read properly 
          // reading data until tab 
          getline(fromfile, title, '\t'); 
          getline(fromfile, author, '\t'); 
          fromfile >> pages; 
          fromfile >> quantity; 
          fromfile >> year; 
          fromfile >> price; 
          //displaying the header of the table 
          //displaying data with fixed width using setw, and using setprecision and and fixed to display data to 2 decimal points 
          std::cout << id
                    << std::setw(2) << " "
                    << std::setw(40) << title
                    << std::setw(2) << " "
                    << std::setw(20) << author
                    << std::setw(2) << " "
                    << std::setw(10) << pages 
                    << std::setw(2) << " "
                    << std::setw(10) << quantity
                    << std::setw(2) << " "
                    << std::setw(8) << year
                    << std::setw(2) << " "
                    << std::fixed
                    << std::setw(6) << std::setprecision(2) << price
                    << std::setw(10) << " "
                    << std::setprecision(2) << price * quantity
                    << std::endl; 
        } 
        fromfile.close(); //closing the file 
        break; 

      case 5: break; 
      case 6: break; 
      case 7: break; 
      case 8: break; 
      default: break;
      } 
    } 
    else //validation text telling the user the integer they intered was invalid 
      std::cout << "Please enter a number from 1 to 9" << std::endl; 
  } while (choice != 9); //ensures that menu and tasks keep on getting repeated unless 9 is entered 
  //exit message  
  std::cout << "Bye, see you again later!" << std::endl; 

  return 0; 
}
