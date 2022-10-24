//name:Maryam Jafar
//description: this program lets the user input remove or print student data for a program. It uses the student ID as position indicator.
//The addStudent() method checks if the list is empty, and then proceeds to add students by their ID's. In the addStudent() method, it goes throught the list to make sure if the ID is less or more than the current list data, and if inserts accrodingly. 
//The removeStudent() method searches for the inputted ID and remov es it from the list
//The printStudent method prints the whole list for the program. 
//The main function executes all the methods in apropriate order and gets user input. it also contains the necessary main - loops.
#include "string"
#include "iostream"
using namespace std;

class Student {

public:
	string name;
	int ID = 0;
	int prgmID= 0;
	int size=0;
	//	int data;
	Student *next;
	Student *prev;
	Student *header;
	Student *tail;
	Student *temp;

	void addStudent(int ID);
	void removeStudent(int ID);
	void printStudent();
	Student();
	~Student();

	Student(int ID) {
		this->ID = ID;
		prev = NULL;
		next = NULL;
	}
};


Student::Student()
{
	ID = 0;
	prgmID = 0;
	name = "";
	header = NULL;
	tail = NULL;
	size = 0;
	ID = 0;
	temp = header;
}


Student::~Student()
{
}

void Student::addStudent(int ID)
{

	if (ID < 1 || ID > size + 1) {
		return;
	}
	else if (ID == 1) {//else if(ID==1){
		Student *n = new Student(ID);
		if (header == NULL) {
			header = n;
			tail = n;
		}
		else {
			header->prev = n;
			n->next = header;
			header = n;
		}
		size++;
	}
	else if (ID = size + 1) {
		Student *n = new Student(ID);
		if (header == NULL) {
			header = n;
			tail = n;
		}
		else {
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		size++;
	}
	else if (header != NULL) {
		Student *temp = header;
		Student *n = new Student(ID);
		while (temp != NULL) {
			temp = temp->next;
			if (n > temp) {
				/*for (int i = 1; i < ID; i++) {
					temp = temp->next;
				}*/
				temp->prev->next = n;
				n->prev = temp->prev;

				n->next = temp;
				temp->prev = n;
				size++;
				cout << n; /*************************/
			}
			else if (n < temp) {
				/*for (int i = 1; i < ID; i++) {
					temp = temp->next;
				}*/
				temp->next->prev = n;
				n->next = temp->next;

				n->prev = temp;
				temp->next = n;
				size++;
				cout << n; /*************************/
			}
		}
		//Student *n = new Student(ID); 
		//for (int i = 1; i < ID; i++) { 
		//	temp = temp->next;
		//}	
		//temp->prev->next = n;
		//n->prev = temp->prev;

		//n->next = temp;
		//temp->prev = n;
		//size++;
		//cout << n; /*************************/
	}

}

void Student::removeStudent(int ID)
{

	if (ID == 1) {
		if (header->next == NULL) {
			delete header;
			header = NULL;
			tail = NULL;
			size--;
		}
		else if (header != NULL) {
			header = header->next;
			delete header->prev;
			header->prev = NULL;
		}
	}
	else if (ID == size) {
		if (header->next == NULL) {
			delete header;
			header = NULL;
			tail = NULL;
			size--;
		}
		else if (header != NULL) {
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
			size--;
		}
	}
	else if (header != NULL) {
		Student *n = new Student(ID);
		Student *temp = header;
		for (int i = 1; i < ID; i++) {
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;








		delete temp;

		size--;
		cout << n;
	}

}

void Student::printStudent()
{
	Student *temp = header;
	cout << "results:" << "\n";

	while (temp != NULL) {
		cout << temp->ID << "";
		temp = temp->next;


	}
	cout << "\n";
}

int main() {
	Student student;
	int temp;
	int option;
	int prgrm;
	int command;
	bool inputVal = false;
	bool quit = false;
	while (!quit) {
		cout << "do you want to quit? 1-yes 2-no \n";
		cin >> command;
		if (command == 2) {
			cout << "please enter size \n";
			cin >> student.size;
			cout << "please enter the program ID \n";
			cin >> prgrm;
			cout << "input for program ID:" << prgrm << " \n";
			do {
				cout << "what would you like to do today? \n";
				cout << "1:add, 2:remove, 3:print students \n";
				cin >> option;
				if (option > 3 || option < 1) {
					cout << "invalid input \n";
					inputVal = false;
				}
				else {
					inputVal = true;
				}
				switch (option) {
				case 1:
					cout << "please enter ID \n";
					cin >> student.ID;
					cout << "please enter name \n";
					cin >> student.name;
					if (student.ID < 1 || student.ID > student.size + 1) {
						return 1;
					}
					student.addStudent(student.ID);
					break;
				case 2:
					cout << "please enter ID \n";
					cin >> student.ID;
					cout << "please enter name \n";
					cin >> student.name;
					if (student.ID < 1 || student.ID > student.size + 1) {
						return 1;
					}
					student.removeStudent(student.ID);
					break;
				case 3:
					student.printStudent();
					break;
				}
			} while (inputVal = true);
		}else {
	quit = true;
	return 1;
	}
	}

	//return 1;
}