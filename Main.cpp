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
	std::cout << "Если хотите сами задать атаку, защиту, здоровье и урон, напишите 0, если хотите оставить их случайными, напишите 1" << std::endl;
	std::cin >> i;
	while (!IsCorrect()) {
		std::cout << "Введите нормально >:(" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl;
	int atk;
	int def;
	int HP;
	int minDmg;
	int maxDmg;
	if (i == 0) {
		std::cout << "Атака: ";
		std::cin >> atk;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> atk;
		}
		std::cout << "Защита: ";
		std::cin >> def;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> def;
		}
		std::cout << "Здоровье: ";
		std::cin >> HP;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> HP;
		}
		std::cout << "Мин. урон: ";
		std::cin >> minDmg;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> minDmg;
		}
		std::cout << "Макс. урон: ";
		std::cin >> maxDmg;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> maxDmg;
		}
		std::cout << std::endl;
	}
	else {
		if (i != 1) std::cout << "Играй нормально >:(" << std::endl;
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
	std::cout << "Если хотите сами задать атаку, защиту, здоровье и урон, напишите 0, если хотите оставить их случайными, напишите 1" << std::endl;
	std::cin >> i;
	while (!IsCorrect()) {
		std::cout << "Введите нормально >:(" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl;
	int atk;
	int def;
	int HP;
	int minDmg;
	int maxDmg;
	if (i == 0) {
		std::cout << "Атака: ";
		std::cin >> atk;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> atk;
		}
		std::cout << "Защита: ";
		std::cin >> def;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> def;
		}
		std::cout << "Здоровье: ";
		std::cin >> HP;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> HP;
		}
		std::cout << "Мин. урон: ";
		std::cin >> minDmg;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> minDmg;
		}
		std::cout << "Макс. урон: ";
		std::cin >> maxDmg;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> maxDmg;
		}
		std::cout << std::endl;
	}
	else {
		if (i != 1) std::cout << "Играй нормально >:(" << std::endl;
		atk = rand() % 20 + 1;
		def = rand() % 20 + 1;
		HP = rand() % 1000 + 1;
		maxDmg = rand() % 200 + 1;
		minDmg = rand() % maxDmg + 1;
	}
	return Monster(atk, def, HP, minDmg, maxDmg);
}

void GetParam(Creature creature) {
	std::cout << "Атака " << creature.GetAttack() << ", защита " << creature.GetDefence() << ", здоровье " << creature.GetHP() << ", урон " << creature.GetMinDamage() << " - " << creature.GetMaxDamage() << std::endl;
}

void ActionPlayer(Player& player, Monster& monster) {
	std::cout << "Хочешь исцелиться перед атакой? 1 если да, 0 если нет" << std::endl;
	int i;
	std::cin >> i;
	while (!IsCorrect()) {
		std::cout << "Введите нормально >:(" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl;
	if (i) player.Cure();
	std::cout << "Ты аттакуешь монстра" << std::endl;
	int damage = player.Attack(monster);
	if (damage == 0) std::cout << "Ты промахнулся" << std::endl;
	else std::cout << "Ты нанес "<< damage<<" урона" << std::endl;
	std::cout << std::endl;
}

void ActionMonster(Player& player, Monster& monster) {
	std::cout << "Монстр аттакует" << std::endl;
	int damage = monster.Attack(player);
	if (damage == 0) std::cout << "Монстр промахнулся" << std::endl;
	else std::cout << "Монстр нанес " << damage << " урона" << std::endl;
	std::cout << std::endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Проверим реализацию классов для Игрока и Монстров. \n Мы создадим Игрока и пару Монстров и попытаемся их убить." << std::endl;
	std::cout << "Создадим игрока" << std::endl;
	Player player = CreatePlayer();
	std::cout << "Создан игрок" << std::endl;
	GetParam(player);

	std::cout << "Создадим 2х монстров" << std::endl;
	Monster monster_1 = CreateMonster();
	std::cout << "Создан первый монстр" << std::endl;
	GetParam(monster_1);
	Monster monster_2 = CreateMonster();
	std::cout << "Создан второй монстр" << std::endl;
	GetParam(monster_2);

	int counterMonsters = 2;

	while (!player.IsDead() && (counterMonsters != 0)) {
		if (counterMonsters == 1) {
			std::cout << "Аттакуем второго монстра!" << std::endl;
			ActionPlayer(player, monster_2);
			if (monster_2.IsDead()) {
				--counterMonsters;
				std::cout << "Второй монстр мертв!" << std::endl;
			}
			else ActionMonster(player, monster_2);
		}
		if (counterMonsters == 2) {
			std::cout << "Аттакуем первого монстра!" << std::endl;
			ActionPlayer(player, monster_1);
			if (monster_1.IsDead()) {
				--counterMonsters;
				std::cout << "Первый монстр мертв!" << std::endl;
			}
			else ActionMonster(player, monster_1);
		}
		if (player.IsDead()) {
			std::cout << "Игрок мертв!" << std::endl;
		}
	}

	if (!player.IsDead()) {
		std::cout << "Все монстры уже переплыли по реке Стикс, желаете к ним присоединиться? Напишите 1, если хотите отправиться в путешествие по реке Стикс, или 0, если не хотите" << std::endl;
		int i;
		std::cin >> i;
		while (!IsCorrect()) {
			std::cout << "Введите нормально >:(" << std::endl;
			std::cin >> i;
		}
		std::cout << std::endl;
		if (!i) std::cout << "Вы прошли игру, поздравляю!" << std::endl;
		else {
			while (!player.IsDead()) player.Attack(player);
			std::cout << "Вы умерли, поздравляю!" << std::endl;
		}
	}
	std::system("pause");


	return 0;
}