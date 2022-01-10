#include <iostream>

const int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
private:
	int year_;
	int month_;
	int day_;

public:
	void set_date(int year, int month, int date) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date > 31 || date < 1) {
				std::cout << "��ȿ���� ���� ��¥�Դϴ�." << std::endl;
				break;
			}
			else {
				year_ = year;
				month_ = month;
				day_ = date;
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (date > 30 || date < 1) {
				std::cout << "��ȿ���� ���� ��¥�Դϴ�." << std::endl;
				break;
			}
			else {
				year_ = year;
				month_ = month;
				day_ = date;
				break;
			}
		case 2:
			if (date > 28 || date < 1) {
				std::cout << "��ȿ���� ���� ��¥�Դϴ�." << std::endl;
				break;
			}
			else {
				year_ = year;
				month_ = month;
				day_ = date;
				break;
			}
		default:
			std::cout << "��ȿ���� ���� ��¥�Դϴ�." << std::endl;
			break;
		}
	}

	void add_day(int inc) {
		for (;;) {
			if (inc < 1) {
				break;
			} else if ((inc + day_) > month_days[month_]) {
				inc -= month_days[month_] - (day_ - 1);
				day_ = 1;
				add_month(1);
			} else {
				day_ += inc;
				inc = 0;
			}
		}
	}
	void add_month(int inc) {
		for (;;) { 
			if (inc < 1) {
				break;
			} else if ((inc + month_) > 12) {
				inc -= 12 - (month_ - 1);
				month_ = 1;
				add_year(1);
			} else {
				month_ += inc;
				inc = 0;
			}
		}
	}
	void add_year(int inc) {
		year_ += inc;
	}

	void show_date() {
		std::cout << year_ << "�� " << month_ << "�� " << day_ << "�� �Դϴ�." << std::endl;
		std::cout << std::endl;
	}
};

int main() {
	Date date;
	for (;;) {
		int command, year, month, day;
		std::cout << "1. ��¥ ����  2. �� ���ϱ�  3. �� ���ϱ�  4. �� ���ϱ�  5. ��¥ ����  6. ����" << std::endl;
		std::cout << "�޴��� �������ּ��� : ";
		std::cin >> command;

		if (command == 6) break;

		switch (command) {
		case 1:
			std::cout << "��� �ΰ���? : ";
			std::cin >> year;
			std::cout << "��� �ΰ���? : ";
			std::cin >> month;
			std::cout << "���� �ΰ���? : ";
			std::cin >> day;
			date.set_date(year, month, day);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "��� ���ұ��? : ";
			std::cin >> year;
			date.add_year(year);
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "��� ���ұ��? : ";
			std::cin >> month;
			date.add_month(month);
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "���� ���ұ��? : ";
			std::cin >> day;
			date.add_day(day);
			std::cout << std::endl;
			break;
		case 5:
			date.show_date();
			break;
		default:
			std::cout << "��ȿ���� ���� ����Դϴ�." << std::endl;
			std::cout << std::endl;
			break;
		}
		std::cout << std::endl;
	}
}