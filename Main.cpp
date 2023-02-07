#include "Player.h"
#include "Monster.h"

bool IsCorrect() {
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		return false;
	}
	return true;
}

Player CreatePlayer() {
	int i;
	std::cout << "���� ������ ���� ������ �����, ������, �������� � ����, �������� 0, ���� ������ �������� �� ����������, �������� 1" << std::endl;
	std::cin >> i;
	while (!IsCorrect()) {
		std::cout << "������� ��������� >:(" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl;
	int atk;
	int def;
	int HP;
	int minDmg;
	int maxDmg;
	if (i == 0) {
		std::cout << "�����: ";
		std::cin >> atk;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> atk;
		}
		std::cout << "������: ";
		std::cin >> def;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> def;
		}
		std::cout << "��������: ";
		std::cin >> HP;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> HP;
		}
		std::cout << "���. ����: ";
		std::cin >> minDmg;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> minDmg;
		}
		std::cout << "����. ����: ";
		std::cin >> maxDmg;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> maxDmg;
		}
		std::cout << std::endl;
	}
	else {
		if (i != 1) std::cout << "����� ��������� >:(" << std::endl;
		atk = rand() % 20 + 1;
		def = rand() % 20 + 1;
		HP = rand() % 1000 + 1;
		maxDmg = rand() % 200 + 1;
		minDmg = rand() % maxDmg + 1;
	}
	return Player(atk, def, HP, minDmg, maxDmg);
}

Monster CreateMonster() {
	int i;
	std::cout << "���� ������ ���� ������ �����, ������, �������� � ����, �������� 0, ���� ������ �������� �� ����������, �������� 1" << std::endl;
	std::cin >> i;
	while (!IsCorrect()) {
		std::cout << "������� ��������� >:(" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl;
	int atk;
	int def;
	int HP;
	int minDmg;
	int maxDmg;
	if (i == 0) {
		std::cout << "�����: ";
		std::cin >> atk;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> atk;
		}
		std::cout << "������: ";
		std::cin >> def;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> def;
		}
		std::cout << "��������: ";
		std::cin >> HP;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> HP;
		}
		std::cout << "���. ����: ";
		std::cin >> minDmg;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> minDmg;
		}
		std::cout << "����. ����: ";
		std::cin >> maxDmg;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> maxDmg;
		}
		std::cout << std::endl;
	}
	else {
		if (i != 1) std::cout << "����� ��������� >:(" << std::endl;
		atk = rand() % 20 + 1;
		def = rand() % 20 + 1;
		HP = rand() % 1000 + 1;
		maxDmg = rand() % 200 + 1;
		minDmg = rand() % maxDmg + 1;
	}
	return Monster(atk, def, HP, minDmg, maxDmg);
}

void GetParam(Creature creature) {
	std::cout << "����� " << creature.GetAttack() << ", ������ " << creature.GetDefence() << ", �������� " << creature.GetHP() << ", ���� " << creature.GetMinDamage() << " - " << creature.GetMaxDamage() << std::endl;
}

void ActionPlayer(Player& player, Monster& monster) {
	std::cout << "������ ���������� ����� ������? 1 ���� ��, 0 ���� ���" << std::endl;
	int i;
	std::cin >> i;
	while (!IsCorrect()) {
		std::cout << "������� ��������� >:(" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl;
	if (i) player.Cure();
	std::cout << "�� ��������� �������" << std::endl;
	int damage = player.Attack(monster);
	if (damage == 0) std::cout << "�� �����������" << std::endl;
	else std::cout << "�� ����� "<< damage<<" �����" << std::endl;
	std::cout << std::endl;
}

void ActionMonster(Player& player, Monster& monster) {
	std::cout << "������ ��������" << std::endl;
	int damage = monster.Attack(player);
	if (damage == 0) std::cout << "������ �����������" << std::endl;
	else std::cout << "������ ����� " << damage << " �����" << std::endl;
	std::cout << std::endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "�������� ���������� ������� ��� ������ � ��������. \n �� �������� ������ � ���� �������� � ���������� �� �����." << std::endl;
	std::cout << "�������� ������" << std::endl;
	Player player = CreatePlayer();
	std::cout << "������ �����" << std::endl;
	GetParam(player);

	std::cout << "�������� 2� ��������" << std::endl;
	Monster monster_1 = CreateMonster();
	std::cout << "������ ������ ������" << std::endl;
	GetParam(monster_1);
	Monster monster_2 = CreateMonster();
	std::cout << "������ ������ ������" << std::endl;
	GetParam(monster_2);

	int counterMonsters = 2;

	while (!player.IsDead() && (counterMonsters != 0)) {
		if (counterMonsters == 1) {
			std::cout << "�������� ������� �������!" << std::endl;
			ActionPlayer(player, monster_2);
			if (monster_2.IsDead()) {
				--counterMonsters;
				std::cout << "������ ������ �����!" << std::endl;
			}
			else ActionMonster(player, monster_2);
		}
		if (counterMonsters == 2) {
			std::cout << "�������� ������� �������!" << std::endl;
			ActionPlayer(player, monster_1);
			if (monster_1.IsDead()) {
				--counterMonsters;
				std::cout << "������ ������ �����!" << std::endl;
			}
			else ActionMonster(player, monster_1);
		}
		if (player.IsDead()) {
			std::cout << "����� �����!" << std::endl;
		}
	}

	if (!player.IsDead()) {
		std::cout << "��� ������� ��� ��������� �� ���� �����, ������� � ��� ��������������? �������� 1, ���� ������ ����������� � ����������� �� ���� �����, ��� 0, ���� �� ������" << std::endl;
		int i;
		std::cin >> i;
		while (!IsCorrect()) {
			std::cout << "������� ��������� >:(" << std::endl;
			std::cin >> i;
		}
		std::cout << std::endl;
		if (!i) std::cout << "�� ������ ����, ����������!" << std::endl;
		else {
			while (!player.IsDead()) player.Attack(player);
			std::cout << "�� ������, ����������!" << std::endl;
		}
	}
	std::system("pause");


	return 0;
}