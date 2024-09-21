#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules();

int main() {
	setlocale(LC_ALL, "RUS");

	string playerName;
	int balance;
	int bettingAmount;
	int guess;
	int secretNumber;
	char choice;

	srand(time(0));

	cout << endl << endl << endl << "========WELCOME TO CASINO WORLD=======" << endl << endl;
	cout << endl << endl << "введите ваше имя: ";
	getline(cin, playerName);

	cout << endl << endl << "введите начальную ставку $";
	cin >> balance;
	do {
		system("cls");
		rules();

		cout << endl << endl << "Ваш текущий баланс составляет $" << balance << endl;
		do {
			cout << "Эй, " << playerName << ", введите сумму для ставки : $";
			cin >> bettingAmount;

			if (bettingAmount > balance) {
				cout << "баланс ставки не может быть больше текущего баланса!" << endl;
				cout << endl << "Re-enter balance " << endl;
			}

		} while (bettingAmount > balance);

		do {
			cout << "Угадайте любой номер ставки от 1 до 10: ";
			cin >> guess;

			if (guess <= 0 || guess > 10) {
				cout << endl << "Число должно быть от 1 до 10 " << endl <<
					"Повторно введите номер: " << endl;
			}
		} while (guess <= 0 || guess > 10);

		secretNumber = rand() % 10 + 1;

		if (secretNumber == guess) {
			cout << endl;
			cout << endl << endl << "Сумма ставок.Вам повезло!!Вы выиграли рупии." << bettingAmount * 10;

			balance = balance + bettingAmount * 10;
		} else {
			cout << endl;
			cout << "Упс, в следующий раз повезет больше!! Вы проиграли $ " << bettingAmount;
			balance = balance - bettingAmount;
		}
		cout << endl << "Выигрышный номер был : " << secretNumber << endl;
		cout << endl << playerName << ", у вас на балансе $ " << balance << endl;

		if (balance == 0) {
			cout << "У вас нет денег, чтобы играть";
			break;
		}
		cout << endl << endl << "-->Ты хочешь поиграть еще раз (y/n)? ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	cout << endl << endl; //<< endl; 
	cout << endl << endl << "Спасибо, что поиграли в игру. Ваш баланс равен $" << balance << endl << endl;

	return 0;
}

void rules() {
	system("cls");
	cout << "\t\t====== ПРАВИЛА УГАДЫВАНИЯ НОМЕРОВ КАЗИНО!======" << endl;
	cout << "\t1. Выберите число от 1 до 10" << endl;
	cout << "\t2. Победитель получает сумму, в 10 раз превышающую сумму ставки" << endl << endl;
	cout << "\t3. Неправильная ставка, и вы теряете сумму, которую поставили" << endl << endl;
}