// Eman_Furrukh_21i1726
// Assignment #2 
// Question #3

/*
FAST university has hired you to make an operating system for their lifts. Below are specifications of the lifts OS.
The lift will be place in a building with 6 floors including a basement.
From basement to top floors are labeled as -1,0,1,2,3,4 respectively.
In the morning, the lift goes operation from the basement. The lift can go up and down.
If maintained is required, the lift can be halted. If the lift is halted, the lift not usable during that period.
Once unhalted, the lift can be used again.
With the help of above information, make a lift operating system
*/

#include<iostream>
using namespace std;

class lift_floors {
public:
	int  floor;
	char floor_status; //A for active N for not active
	lift_floors* next;
	lift_floors* previous;
	lift_floors(int data) {
		this->floor = data;
		this->next = NULL;
		this->previous = NULL;
		this->floor_status = 'A';
	}
};

int lift_operating_system(int requested_floor, lift_floors* current, lift_floors* head, lift_floors* tail, char lift_status) {
	// lift operating system logic
	int count = 0;
	if (current == NULL) 
		current = head;
	if (current->floor == requested_floor) {
		cout << "Reached Floor: " << current->floor << endl;
		return count;
	}
	else if (current->floor < requested_floor) {
		while (current != NULL && current->floor < requested_floor) {
			if (current->floor_status == 'A') {
				count++;
				current = current->next;
			}
			else 
				current = current->next;
		}
		cout << "Reached floor: " << current->previous->floor << endl;
	}
	else {
		while (current != NULL && current->floor > requested_floor) {
			if (current->floor_status == 'A') {
				count++;
				current = current->previous;
			}
			else 
				current = current->previous;
		}
		cout << "Reached floor:" << current->next->floor << endl;
	}
	return count;
}

int liftup(lift_floors* current, lift_floors* head, lift_floors* tail, int requested_floor) {
	// base case; lift has reached the requested floor
	if (current == NULL) { 
		cout << "Lift has reached floor " << requested_floor << endl;
		return requested_floor;
	}
	// another base case; lift is already on the requested floor
	if (current->floor == requested_floor) {
		cout << "Lift is already on floor " << requested_floor << endl;
		return requested_floor;
	}
	// if there is no next floor or the next floor is higher than the requested floor, stop going up
	if (current->next == NULL || current->next->floor > requested_floor) { 
		cout << "Lift has reached the highest floor it can go\n";
		return current->floor;
	}

	cout << "Lift is going up to floor " << current->next->floor << endl;
	// recursive call to move the lift up to the next floor
	return liftup(current->next, head, tail, requested_floor);
}

int liftdown(lift_floors* current, lift_floors* head, lift_floors* tail, int requested_floor) {
	// base case: lift has reached the requested floor
	if (current == NULL) { 
		cout << "Lift has reached floor " << requested_floor << endl;
		return requested_floor;
	}
	// another base case: lift is already on the requested floor
	if (current->floor == requested_floor) { 
		cout << "Lift is already on floor " << requested_floor << endl;
		return requested_floor;
	}
	// if there is no previous floor or the previous floor is lower than the requested floor, stop going down
	if (current->previous == NULL || current->previous->floor < requested_floor) { 
		cout << "Lift has reached the lowest floor it can go\n";
		return current->floor;
	}

	cout << "Lift going down to floor " << current->previous->floor << endl;
	// recursive call to move the lift down to the previous floor
	return liftdown(current->previous, head, tail, requested_floor); 
}

char halt_lift(char status) {
	//halts the lift, no up and down operation can be performed. Stored H for halting
	if (status == 'W') {
		status = 'H';
		cout << "Lift halted." << endl;
	}
	else 
		cout << "Lift was halted." << endl;
	return status;
}

char un_halt_lift(char status) {
	//Unhatls the lift. Store W which represents that the lift is working
	if (status == 'H') {
		status = 'W';
		cout << "Lift un-halted." << endl;
	}
	else 
		cout << "Lift was working." << endl;
	return status;
}

void add_floor(lift_floors* new_floor, lift_floors*& head, lift_floors*& tail) {
	//add a lift floor;
	if (head == NULL) {
		head = new_floor;
		tail = new_floor;
	}
	else if(head != NULL) {
		tail->next = new_floor;
		new_floor->previous = tail;
		tail = new_floor;
	}
}

void skip_floor(lift_floors*& head, lift_floors*& tail, int floorNo) {
	//add logic to make lift skip a certian floor
	lift_floors* temp = head;
	while (temp != NULL) {
		if (temp->floor == floorNo) {
			temp->floor_status = 'N';
			break;
		}
		temp = temp->next;
	}
}

void make_floor_operational(lift_floors*& head, lift_floors*& tail, int floorNo) {
	//add logic to make lift operational on a certain floor
	lift_floors* temp = head;
	while (temp != NULL) {
		if (temp->floor == floorNo) {
			temp->floor_status = 'A';
			break;
		}
		temp = temp->next;
	}
}

int main() {
	lift_floors* head = NULL;
	lift_floors* tail = NULL;
	lift_floors* current = NULL;
	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service = 0; //choice of user
	int requested_floor = 0; //floor the lift goes on
	char status = 'W'; //W for working , H for halted
	lift_floors* add = NULL;

	for (int i = 0; i < total_floors; i++)
		add = new lift_floors(i);

	current = head;

	while (1) {
		cout << "\n\t Lift System Automation Menu\n";
		cout << endl << "1. Go to a floor";
		cout << endl << "2. Halt the Lift";
		cout << endl << "3. Unhalt the Lift";
		cout << endl << "4. Add Floor";
		cout << endl << "5. Skip Floor";
		cout << endl << "6. Make Floor Optional";
		cout << endl << "7. Exit";
		cout << endl << endl << "Enter a choice: ";
		cin >> requested_service;

		switch (requested_service) {
			case 1: {
				cout << "Enter floor of choice: ";
				cin >> requested_floor;
				lift_operating_system(requested_floor, current, head, tail, status);
				break;
			}
			case 2: {
				status = halt_lift(status);
				break;
			}
			case 3: {
				status = un_halt_lift(status);
				break;
			}
			case 4: {
				cout << "Enter floor to add: ";
				cin >> requested_floor;
				add_floor(add, head, tail);
				break;
			}
			case 5: {
				cout << "Enter floor to skip: ";
				cin >> requested_floor;
				skip_floor(head, tail, requested_floor);
				break;
			}
			case 6: {
				cout << "Enter floor to make operational: ";
				cin >> requested_floor;
				make_floor_operational(head, tail, requested_floor);
				break;
			}
			case 7: {
				cout << "You have exited the program.\n";
				return 0;
			}
			default: {
				cout << "Invalid entry, try again." << endl;
				break;
			}
		}
	}
	return 0;
}