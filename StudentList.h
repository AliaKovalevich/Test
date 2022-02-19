#include <iostream>
#include <string>

using namespace std;

// enum class и enum отличаются уровнем доступа (Желательно использовать enum class)
enum class Faculty
{
	UNKNOWN, FIT, HTIT, TOF, PIM, FOREST
};

struct Student
{
public: 
	string FirName;
	string SecName;
	string DadName;
	string Special;

	int group;
	int enterDate; //др

	float middleMark; //средний балл

	Faculty faculty;

	Student* next;

	Student() : FirName("None"), SecName("None"), DadName("None"), Special("None"), group(0), enterDate(00000000), middleMark(0), faculty(Faculty::UNKNOWN), next(nullptr) {}

	Student(string MainName, string SecName, string DadName, string Special, int group, int enterDate, float middleMark, Faculty faculce, Student* next = nullptr) {
		this->FirName = MainName;
		this->SecName = SecName;
		this->DadName = DadName;
		this->Special = Special;
		this->group = group;
		this->enterDate = enterDate;
		this->middleMark = middleMark;
		this->faculty = faculce;
		this->next = next;
	}

	// Выводящая инфу студента
	void print() {
		cout << FirName << ":" << SecName << ":" << DadName << ":" << Special << ":"
			<< group << ":" << enterDate << ":" << middleMark << ":" << endl;
	}
};

struct StudentList
{
public:
	Student* First; // Первый элемент
	Student* Last; // Последний элемент

	StudentList() : First(nullptr), Last(nullptr) { }

	// Пустой ли список?
	bool is_empty() {
		return (First == nullptr || Last == nullptr);
	}

	// Возврощает кол-во элементов в списке
	int getSize() {
		Student* ref = First;

		int size = 0;

		while (ref != nullptr) {
			size++;
			ref = ref->next;
		}

		return size;
	}

	// Добавляет элемент
	void add(Student* student) {
		if (is_empty()) {
			First = student;
			Last = student;
		}
		else {
			Last->next = student;
			Last = student;
		}
	}

	// Перегрузка выводящая инфу всех элементов списка
	void print() {
		for (int i = 0; i < getSize(); i++)
			cout << get(i)->FirName << ":" << get(i)->SecName << ":" << get(i)->DadName << ":" << get(i)->Special << ":"
			<< get(i)->group << ":" << get(i)->enterDate << ":" << get(i)->middleMark << ":" << endl;
	}

	// Перегрузка выводящая инфу элемента списка с текущим индексом
	void print(int index) {
		cout << get(index)->FirName << ":" << get(index)->SecName << ":" << get(index)->DadName << ":" << get(index)->Special << ":"
			<< get(index)->group << ":" << get(index)->enterDate << ":" << get(index)->middleMark << ":" << endl;
	}

	// Получение указателя на элемент с тиким индексом
	Student* get(int index) {
		if (is_empty()) return nullptr;

		// Ссылка на текущий рассматриваемый эл
		Student* ref = First;

		for (int i = 0; i < index; i++) {
			ref = ref->next;

			if (ref == nullptr) return nullptr;
		}

		return ref;
	}

	// Получение указателя элемент через оператор индексации => [] <=
	Student* operator[] (int index) {
		return get(index);
	}

	// Удоляет ссылку с текущим индексом
	void remove(int index) {
		if (is_empty()) return;

		Student* delref = get(index);

		if (index == 0) 
			First = First->next;
		else if (index == getSize() - 1) {
			Last = get(getSize() - 2);
			Last->next = nullptr;
		}
		else get(index - 1)->next = get(index + 1);
		
		delete delref;
	}

	// Находит элеимент в списке с такой датой
	Student* findByEnterDate(int date) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->enterDate == date ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}

	// Находит элеимент в списке с такой оценкой
	Student* findByMiddleMark(int mark) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->middleMark == mark ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}

	// Находит элеимент в списке с такой группой
	Student* findByGroup(int group) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->group == group ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}

	// Находит элеимент в списке с такой фамилией
	Student* findBySecName(string name) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->SecName == name ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}
};