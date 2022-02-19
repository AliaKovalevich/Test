#include <iostream>
#include <string>

using namespace std;

// enum class � enum ���������� ������� ������� (���������� ������������ enum class)
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
	int enterDate; //��

	float middleMark; //������� ����

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

	// ��������� ���� ��������
	void print() {
		cout << FirName << ":" << SecName << ":" << DadName << ":" << Special << ":"
			<< group << ":" << enterDate << ":" << middleMark << ":" << endl;
	}
};

struct StudentList
{
public:
	Student* First; // ������ �������
	Student* Last; // ��������� �������

	StudentList() : First(nullptr), Last(nullptr) { }

	// ������ �� ������?
	bool is_empty() {
		return (First == nullptr || Last == nullptr);
	}

	// ���������� ���-�� ��������� � ������
	int getSize() {
		Student* ref = First;

		int size = 0;

		while (ref != nullptr) {
			size++;
			ref = ref->next;
		}

		return size;
	}

	// ��������� �������
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

	// ���������� ��������� ���� ���� ��������� ������
	void print() {
		for (int i = 0; i < getSize(); i++)
			cout << get(i)->FirName << ":" << get(i)->SecName << ":" << get(i)->DadName << ":" << get(i)->Special << ":"
			<< get(i)->group << ":" << get(i)->enterDate << ":" << get(i)->middleMark << ":" << endl;
	}

	// ���������� ��������� ���� �������� ������ � ������� ��������
	void print(int index) {
		cout << get(index)->FirName << ":" << get(index)->SecName << ":" << get(index)->DadName << ":" << get(index)->Special << ":"
			<< get(index)->group << ":" << get(index)->enterDate << ":" << get(index)->middleMark << ":" << endl;
	}

	// ��������� ��������� �� ������� � ����� ��������
	Student* get(int index) {
		if (is_empty()) return nullptr;

		// ������ �� ������� ��������������� ��
		Student* ref = First;

		for (int i = 0; i < index; i++) {
			ref = ref->next;

			if (ref == nullptr) return nullptr;
		}

		return ref;
	}

	// ��������� ��������� ������� ����� �������� ���������� => [] <=
	Student* operator[] (int index) {
		return get(index);
	}

	// ������� ������ � ������� ��������
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

	// ������� �������� � ������ � ����� �����
	Student* findByEnterDate(int date) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->enterDate == date ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}

	// ������� �������� � ������ � ����� �������
	Student* findByMiddleMark(int mark) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->middleMark == mark ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}

	// ������� �������� � ������ � ����� �������
	Student* findByGroup(int group) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->group == group ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}

	// ������� �������� � ������ � ����� ��������
	Student* findBySecName(string name) {
		Student* ref = nullptr;

		for (int i = 0; i < getSize(); i++) {
			ref = get(i)->SecName == name ? get(i) : nullptr;

			if (ref != nullptr) break;
		}

		return ref;
	}
};