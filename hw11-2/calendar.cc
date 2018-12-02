#include "calendar.h"

Date::Date() {}

Date::Date(int year, int month, int day):year_(year), month_(month), day_(day) {}

void Date::NextDay(int n)
{
	int days = ComputeDaysFromYearStart(year_, month_, day_)-1+n;
	while (days < 0) {
		year_--;
		days += this->GetDaysInYear(year_);
	}
	while (days >= this->GetDaysInYear(year_)) {
		days -= this->GetDaysInYear(year_);
		year_++;
	}
	int _month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	_month[2] = this->GetDaysInYear(year_) == 366 ? 29 : 28;
	month_ = 1;
	days++;
	cout << days << endl;
	for (int i = 1; i <= 12; i++) {
		if (days > _month[i]) {
			days -= _month[i];
			month_=i+1;
		}
		else {
			break;
		}
	}
	day_ = days;
}

bool Date::SetDate(int year, int month, int day)
{
	int _month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	_month[2] = this->GetDaysInYear(year) == 366 ? 29 : 28;
	if (month <= 0 || month > 12) return false;
	if (day <= 0 || day > _month[month]) return false;
	year_ = year;
	month_ = month;
	day_ = day;
	return true;
}

int Date::year() const
{
	return year_;
}

int Date::month() const
{
	return month_;
}

int Date::day() const
{
	return day_;
}

int Date::GetDaysInYear(int year)
{
	if (year % 4 != 0) return 365;
	else if (year % 400 == 0) return 366;
	else if (year % 100 == 0) return 365;
	else return 366;
}

int Date::ComputeDaysFromYearStart(int year, int month, int day)
{
	int _month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	_month[2] = GetDaysInYear(year) == 366 ? 29 : 28;
	int sum = 0;
	for (int i = 1; i < month; i++) sum += _month[i];
	return sum + day;
}

ostream & operator<<(ostream & os, const Date & c)
{
	os << c.year() << '.' << c.month() << '.' << c.day();
	return os;
}

istream & operator>>(istream & is, Date & c)
{
	int t[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		char cstr[10001] = { 0, };
		is.getline(cstr, 10001, i != 2 ? '.' : '\n');
		t[i] = atoi(cstr);
	}
	if (c.SetDate(t[0], t[1], t[2]) == false) {
		cout << "Invalid date: " << t[0] << '.' << t[1] << '.' << t[2] << endl;
	}
	else cout << c << endl;
	return is;
}
