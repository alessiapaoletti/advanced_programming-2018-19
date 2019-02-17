#include <iostream>
#include <string>

enum class Month {January=1,February, March, April, May, June, July, August, September, October, November, December };
std::ostream& operator << (std::ostream& os, const Month& obj)
{
   os << static_cast<std::underlying_type<Month>::type>(obj);
   return os;
}

inline Month& operator++(Month& m, int) {
	const int i = static_cast<int>(m)+1;
	m = static_cast<Month>(i);
	return m;
}

class Date{
  private:
    int day;
    Month month;
    int year;

  public:
    Date(int _day, Month _month, int _year): day{_day}, month{_month}, year{_year} {}; //constructor
    ~Date() {}; //destructor
    void printDay();
    void printMonthNumber();
    void printMonthName();
    void printYear();
    void add_days(const unsigned int n);

    friend std::ostream& operator<<(std::ostream &, Date&);
    friend bool operator==(const Date& , const Date& );
    friend bool operator!=(const Date& , const Date& );
    friend bool is_leap(const int );
  };

  void Date::printDay () {
    std::cout << "The day is: " << this->day << std::endl;
  }

  void Date::printMonthNumber () {
    std::cout << "The month number is: " << this->month << std::endl;
  }

  void Date::printMonthName () {
    std::cout << "The month name is: ";
    switch (this->month) {
      case Month::January: std::cout << "January" <<std::endl; break;
      case Month::February: std::cout << "February" <<std::endl; break;
      case Month::March: std::cout << "March" <<std::endl; break;
      case Month::April: std::cout << "April" <<std::endl; break;
      case Month::May: std::cout << "May" <<std::endl; break;
      case Month::June: std::cout << "June" <<std::endl; break;
      case Month::July: std::cout << "July" <<std::endl; break;
      case Month::August: std::cout << "August" <<std::endl; break;
      case Month::September: std::cout << "September" <<std::endl; break;
      case Month::October: std::cout << "October" <<std::endl; break;
      case Month::November: std::cout << "November" <<std::endl; break;
      case Month::December: std::cout << "December" <<std::endl; break;
      default: std::cout << "Unknown Month" << '\n';  break;
    }
  }

  void Date::printYear () {
    std::cout << "The year is: " << this->year << std::endl;
  }

  void Date::add_days(const unsigned int n){
    /*Until we have days to add we add 1 day to the current day, until we reach the end of the month. If we reach the end of the month
    and we still have days to add, we increase the month and we restart the loop. If the month is december and if we reach the end of the month
    we have to increase the year */
    unsigned int numDay = n;
    while (numDay!=0) {
      switch (this->month) {
        case Month::January: case Month::March: case Month::May: case Month::July:  case Month::August:  case Month::October:
          while (this->day <31 && numDay !=0) {
            this->day +=1;
            numDay--;
          }
          if (numDay != 0 ) {
            this->month++;
            this->day = 0;
          }
          break;

        case Month::April: case Month::June: case Month::September: case Month::November :
          while (this->day <30 && numDay !=0) {
            this->day +=1;
            numDay--;

          }
          if (numDay != 0 ) {
            this->month++;
            this->day = 0;
          }
          break;

        case Month::February :
        /*we can add here the control for the year, if leap or not, if leap <29, if not <28 */
          while (this->day <28 && numDay !=0) {
            this->day +=1;
            numDay--;
          }
          if (numDay != 0 ) {
            this->month++;
            this->day = 0;
          }
          break;

        case Month::December:
        while (this->day <31 && numDay !=0) {
          this->day +=1;
          numDay--;
        }
        if (numDay != 0 ) {
          this->month= Month::January;
          this->day = 0;
          this->year +=1;
        }
        break;
      }
  }
}


/* ---------------- HELPER FUNCTIONS ---------------------------- */
  bool operator==(const Date& d0, const Date& d1){
    if ((d0.year == d1.year) && (d0.month == d1.month) && (d0.day == d1.day) )
      return 1;
    return 0;
  }

  bool operator!=(const Date& d0, const Date& d1) {
    if ((d0.year != d1.year) && (d0.month != d1.month) && (d0.day != d1.day) )
      return 1;
    return 0;
  }

  bool is_leap(const int y) {
    if (y % 4 == 0 && y % 400 != 0)
      return 1;
    return 0;
  }


  //To print all the date
  std::ostream& operator<< (std::ostream &out, Date& d) {
      out << d.day << '/';
      out << d.month << '/';
      out << d.year;
      return out;
  }



int main() {
  Date date0{20, Month::December, 1996};
  Date date1{7, Month::January, 1997};
  Date date2{20, Month::July, 1996};
  date0.printDay();
  date0.printMonthNumber();
  date0.printMonthName();
  date0.printYear();
  std::cout << "Date: " << date0<<std::endl;

  date0.add_days(18);

  date0.printDay();
  date0.printMonthNumber();
  date0.printMonthName();
  date0.printYear();
  std::cout << "New Date: " << date0<<std::endl;

  bool equal{date1==date2};
  if (equal == 1)
    std::cout << "The dates " <<date1 << " and " << date2 << " are the same" << '\n';
  else
    std::cout << "The dates " <<date1 << " and " << date2 << " are different" << '\n';

  bool diff{date1!=date2};
  if (diff == 1)
    std::cout << "The dates " <<date1 << " and " << date2 << " are different" << '\n';
  else
    std::cout << "The dates " <<date1 << " and " << date2 << " are the same" << '\n';

  int y = 2006;
  bool resleap{is_leap(y)};
  if (resleap == 1)
    std::cout << "The year " <<  y << " is leap "<< '\n';
  else
    std::cout << "The year " <<  y << " is not leap "<< '\n';

  return 0;
}
