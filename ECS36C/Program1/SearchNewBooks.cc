#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <chrono>

// Book Class to create book objects and separate attributes to ISNB, language, type
class Book
{
public:
  // Book Object Constructor
  Book(std::string bookInfo)
  {
    int indexComma = bookInfo.find(",");
    ISNB = bookInfo.substr(0, indexComma);
    int indexComma2 = bookInfo.find(",", indexComma + 1);
    language = bookInfo.substr(indexComma + 1, indexComma2 - indexComma - 1);
    type = bookInfo.substr(indexComma2 + 1);
  }
  // Book attributes
  std::string ISNB;
  std::string language;
  std::string type;
};

// Timer class to record search methods
class timer
{
public:
  void Reset() // Start Timer
  {
    start = std::chrono::high_resolution_clock::now();
  };
  std::chrono::high_resolution_clock::time_point start; // Start Time
};

// Overloading << operator to print out a vector of book class objects for debugging purposes
std::ostream &operator<<(std::ostream &os, const std::vector<Book> &b)
{
  for (auto Book : b)
  {
    os << "ISNB: " << Book.ISNB << ", Language: " << Book.language << ", Type: " << Book.type << std::endl;
  }
  return os;
}

// Overloading << operator to print out the time elapsed since started
std::ostream &operator<<(std::ostream &os, const timer &ct)
{
  auto end = std::chrono::high_resolution_clock::now();
  double elapsed_us = std::chrono::duration<double, std::micro>(end - ct.start).count();
  os << "CPU time: " << elapsed_us << " microseconds";
  return os;
}

// Overloading < operator to compare two book objects for sorting
bool operator<(Book &i, Book &j)
{
  int iISNB = stoi(i.ISNB);
  int jISNB = stoi(j.ISNB);
  if (iISNB == jISNB)
  {
    int iVal;
    int jVal;
    std::string iType = i.type;
    std::string jType = j.type;
    if (iType == "new")
    {
      iVal = 3;
    }
    else if (iType == "used")
    {
      iVal = 2;
    }
    else if (iType == "digital")
    {
      iVal = 1;
    }
    if (jType == "new")
    {
      jVal = 3;
    }
    else if (jType == "used")
    {
      jVal = 2;
    }
    else if (jType == "digital")
    {
      jVal = 1;
    }
    if (iVal == jVal)
    {
      return (i.language > j.language);
    }
    return (iVal > jVal);
  }
  return (iISNB > jISNB);
}

// Reading files and Error Check
void readFile(std::ifstream &file, std::string fileName)
{
  file.open(fileName);
  if (!file)
  {
    std::cerr << "Error: cannot open file " << fileName << std::endl;
    exit(1);
  }
}

// Checking for correct number of arguments
void argCheck(int argc)
{
  if (argc < 4)
  {
    std::cerr << "Usage: .SearchNewBooks <newBooks.dat> <request.dat> <result_file.dat>" << std::endl;
    exit(1);
  }
}

// Load file into vectors
void fileVector(std::vector<Book> &v, std::ifstream &file)
{
  std::string bookInfo;
  while (file)
  {
    getline(file, bookInfo);
    if (bookInfo.size() != 0)
    {
      Book newBook = Book(bookInfo);
      v.push_back(newBook);
    }
  }
}

// Linear search on requested books
int LinearSearch(std::vector<Book> &newBooks, std::vector<Book> &request)
{
  int count = 0;
  for (unsigned int i = 0; i < request.size(); i++)
  {
    bool found = false;
    for (unsigned int j = 0; j < newBooks.size() && found == false; j++)
    {
      if (request[i].ISNB == newBooks[j].ISNB && request[i].type == newBooks[j].type && request[i].language == newBooks[j].language)
      {
        found = true;
        count++;
      }
    }
  }
  return count;
}

// Binary search on requested books
int BinarySearch(std::vector<Book> &newBooks, std::vector<Book> &request)
{
  int count = 0;
  sort(newBooks.begin(), newBooks.end());
  for (unsigned int i = 0; i < request.size(); i++)
  {
    int low = 0;
    int high = newBooks.size() - 1;
    int mid;
    bool found = false;
    while (low <= high && !found)
    {
      mid = (low + high) / 2;
      if (request[i].ISNB == newBooks[mid].ISNB && request[i].type == newBooks[mid].type && request[i].language == newBooks[mid].language)
      {
        found = true;
        count++;
      }
      else if (request[i] < newBooks[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
  }
  return count;
}

int main(int argc, char *argv[])
{
  // Checking for correct number of command line arguments
  argCheck(argc);
  // Reading newBooks and request files
  std::ifstream newBooksFile;
  readFile(newBooksFile, argv[1]);
  std::ifstream requestFile;
  readFile(requestFile, argv[2]);
  // Loading files into vectors
  std::vector<Book> newBooks;
  std::vector<Book> request;
  fileVector(newBooks, newBooksFile);
  fileVector(request, requestFile);
  // Search Selection Choice
  std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
  char choice;
  std::cin >> choice;
  int count;
  while (choice != 'l' && choice != 'b')
  {
    std::cerr << "Incorrect choice" << std::endl;
    std::cin >> choice;
  }
  timer ct;
  ct.Reset(); // Timer Begins, Search Starts
  if (choice == 'l')
  {
    count = LinearSearch(newBooks, request);
  }
  else if (choice == 'b')
  {
    count = BinarySearch(newBooks, request);
  }
  // Output
  std::cout << ct << std::endl; // Timer End
  std::ofstream of(argv[3]);
  of << count << std::endl;
}
//./SearchNewBooks newbooks.dat request.dat found.dat