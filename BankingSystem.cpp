#include <iostream>
using namespace std;
template <class T>
class Client {
private:
	string ClientName;
	string ClientEmail;
	string ClientPhone;
	string ClientAddress;
	string ClientPassword;
	int ClientID;

public:
	T arra[5];
	Client() {}
	Client(string cn, string ce, string cp, string ca)
	{
		ClientName = cn;
		ClientEmail = ce;
		ClientPhone = cp;
		ClientAddress = ca;

	}
	void set_ClientName(string cn) { ClientName = cn; }
	string get_ClientName() { return ClientName; }

	void set_ClientEmail(string ce) { ClientEmail = ce; }
	string get_ClientEmail() { return ClientEmail; }

	void set_ClientPhone(string cp) { ClientPhone = cp; }
	string get_ClientPhone() { return ClientPhone; }

	void set_ClientAddress(string ca) { ClientAddress = ca; }
	string get_ClientAddress() { return ClientAddress; }

	void set_ClientPassword(string cpa) { ClientPassword = cpa; }
	string get_ClientPassword() { return ClientPassword; }

	void set_ClientID(int ci) { ClientID = ci; }
	int get_ClientID() { return ClientID; }

	void get_trans(int num) {
		for (int i; i < num; i++) {
			arra[i].printf_info();
		}
	}

	void PrintClientinfo() {
		cout << "Client Name:      " << ClientName << endl;
		cout << "Client Email:     " << ClientEmail << endl;
		cout << "Client Phone:     " << ClientPhone << endl;
		cout << "Client Address:   " << ClientAddress << endl;
		cout << "Client ID:        " << ClientID << endl;
	}
};

template <class T>
class LinkedListNode {
public:
	T data;
	LinkedListNode<T>* next;

	LinkedListNode(T e) {
		data = e;
		next = NULL;
	}
};

template <class T>
class ClientLinkedList {
public:
	LinkedListNode<T>* head;
	int listSize = 0;
	ClientLinkedList()
	{
		head = NULL;
	}

	bool insertclient(T e) {

		LinkedListNode<T>* newNode = new LinkedListNode<T>(e);
		if (head == NULL) {
			head = newNode;
			listSize++;
			return true;
		}

		LinkedListNode<T>* tmpx = head;
		while (tmpx != NULL) {
			if (tmpx->data.get_ClientEmail() == e.get_ClientEmail()) {
				return 0;
			}
			tmpx = tmpx->next;
		}
		listSize++;
		LinkedListNode<T>* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;

		return true;

	}

	void print_all() {
		LinkedListNode<T>* itr = head;
		while (itr != NULL) {
			itr->data.PrintClientinfo();
			itr = itr->next;
		}
	}
};

class Transaction {
private:
	int transactionID;
	string transactionName;
	string transactionDate;
public:
	Transaction() {}
	Transaction(int id, string name, string date) {
		transactionID = id;
		transactionName = name;
		transactionDate = date;
	}
	void set_id(int id) { transactionID = id; }
	int get_id() { return transactionID; }

	void set_name(string name) { transactionName = name; }
	string get_name() { return transactionName; }

	void set_date(string date) { transactionDate = date; }
	string get_date() { return transactionDate; }

	void printf_info()
	{
		cout << "TransactionName:   " << transactionName << endl;
		cout << "TransactionID:     " << transactionID << endl;
		cout << "TransactionDate:   " << transactionDate << endl;
	}
};

Client<Transaction>* keep;
ClientLinkedList<Client<Transaction>> l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;
ClientLinkedList<Client<Transaction>> Arr[10] = { l1,l2,l3,l4,l5,l6,l7,l8,l9,l10 };

void transactionsMenu();
void loginMenu();
void NewClientMenu();
void forgett();
void clientHome();

void swapforsort(ClientLinkedList<Client<Transaction>>* a, ClientLinkedList<Client<Transaction>>* b)
{
	ClientLinkedList<Client<Transaction>> temp = *a;
	*a = *b;
	*b = temp;
}

int parttion(ClientLinkedList<Client<Transaction>> arr[], int low, int high)
{
	int pivot = arr[high].listSize;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		if (arr[j].listSize < pivot) {
			i++;
			swapforsort(&arr[i], &arr[j]);
		}
	}
	swapforsort(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(ClientLinkedList<Client<Transaction>> arr[], int low, int high)
{
	if (low < high) {

		int pi = parttion(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printafter(ClientLinkedList<Client<Transaction>> arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << "Index #" << i << ": Linked List of " << arr[i].listSize << " clients" << endl;
		arr[i].print_all();
	}

	cout << endl;
}

void SortLinkedList(ClientLinkedList<Client<Transaction>> arr[])
{
	LinkedListNode<Client<Transaction>>* node = NULL, * temp = NULL;
	int tempvar;
	for (int i = 0; i < 10; i++) {
		node = Arr[i].head;
		temp = node;
		while (node != NULL)
		{
			temp = node;
			while (temp->next != NULL)
			{
				if (temp->data.get_ClientID() > temp->next->data.get_ClientID());
				{
					tempvar = temp->data.get_ClientID();
					temp->data = temp->next->data;
					temp->next->data.set_ClientID(tempvar);
				}
				temp = temp->next;
			}
			node = node->next;
		}
	}
	printafter(arr, 10);
}

void mainMenu()
{
	int num;
	int n;
	cout << "+++++++++++++++++++ Welcome to Banking System +++++++++++++++++++++++" << endl;
	cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS" << endl;
	cout << "1. Login to your account" << endl;
	cout << "2. New client " << endl;
	cout << "3. Forgot your password" << endl;
	cout << "4. Sort Clients by linked list size using Quick Sort Algorithm " << endl;
	cout << "5. Sort Linked Lists by Client ID" << endl;
	cout << "6. Exit Program" << endl;
	cout << "======================================================================" << endl;
	cin >> num;
	if (num == 1) {
		loginMenu();
		cout << "If you want to return to main menu choose 0" << endl;

		cin >> n;
		if (n == 0) {
			mainMenu();
		}
		else { cout << "Invalid " << endl; }
	}

	if (num == 2) {
		NewClientMenu();
		cout << "If you want to return to main menu choose 0" << endl;

		cin >> n;
		if (n == 0) {
			mainMenu();
		}
		else { cout << "Invalid " << endl; }
	}

	if (num == 3) {
		forgett();
		cout << "If you want to return to main menu choose 0" << endl;

		cin >> n;
		if (n == 0) {
			mainMenu();
		}
		else { cout << "Invalid " << endl; }
	}

	if (num == 4) {
		int sizex = sizeof(Arr) / sizeof(Arr[0]);
		quickSort(Arr, 0, sizex - 1);
		printafter(Arr, sizex);
		cout << "If you want to return to main menu choose 0" << endl;
		cin >> n;
		if (n == 0) {
			mainMenu();
		}
	}
	if (num == 5) {

		SortLinkedList(Arr);
		cout << "If you want to return to main menu choose 0" << endl;
		cin >> n;
		if (n == 0) {
			mainMenu();
		}
		else { cout << "Invalid " << endl; }
	}

	if (num == 6) {
		return;
	}
}

void loginMenu()

{
	int exsits = 0;
	Client<Transaction> C;
	keep = &C;
	string Email;
	string Password;
	cout << "+++++++++++++++ Welcome back dear client ++++++++++++++" << endl;
	cout << "Please write your email:" << endl;
	cin >> Email;
	C.set_ClientEmail(Email);
	cout << "Please write your password:" << endl;
	cin >> Password;
	C.set_ClientPassword(Password);
	cout << "======================================================================" << endl;
	for (int i = 0; i < 10; i++) {
		LinkedListNode<Client<Transaction>>* tmpx = Arr[i].head;
		while (tmpx != NULL) {
			if (tmpx->data.get_ClientEmail() == C.get_ClientEmail()) {
				exsits = 1;
				if (C.get_ClientPassword() == tmpx->data.get_ClientPassword()) {
					clientHome();
				}
				else {
					cout << "Email or Password is incorrect, Please try again " << endl;
                    cout<< "If you want to try again, Press '1', If you want to go the main menu Press '0'"<<endl;
                        int num;
                        cin>> num;
                        if(num == 1){
                        loginMenu();
                        }
                        if(num == 0){
                        mainMenu();
                        }
				}
			}
			tmpx = tmpx->next;
		}

	}
	if (exsits == 0) {
		cout << "Email or Password is incorrect, Please try again " << endl;
		cout<< "If you want to try again, Press '1', If you want to go the main menu Press '0'"<<endl;
		int num;
		cin>> num;
		if(num == 1){
            loginMenu();
		}
		if(num == 0){
            mainMenu();
		}

	}
}

void NewClientMenu() {

	Client<Transaction> c;
	string Name;
	string Email;
	string PhoneNumber;
	string Address;
	string Password;

	cout << "+++++++++++++++++ Welcome to Banking System ++++++++++++++++++++" << endl;
	cout << "++++++++++++++++ Create a new client account ++++++++++++++++++++" << endl;
	cout << "Enter your Name: " << endl;
	cin >> Name;
	c.set_ClientName(Name);

	cout << "Enter your Email: " << endl;
	cin >> Email;
	c.set_ClientEmail(Email);

	cout << "Enter your Phone Number: " << endl;
	cin >> PhoneNumber;
	c.set_ClientPhone(PhoneNumber);

	cout << "Enter your Address: " << endl;
	cin >> Address;
	c.set_ClientAddress(Address);

	cout << "Enter a password: " << endl;
	cin >> Password;
	c.set_ClientPassword(Password);
	c.set_ClientID(rand());

	for (int i = 0; i < 10; i++) {
		LinkedListNode<Client<Transaction>>* tmpx = Arr[i].head;
		while (tmpx != NULL) {
			if (tmpx->data.get_ClientEmail() == c.get_ClientEmail()) {
				cout << "Already Exists" << endl;
			}
			tmpx = tmpx->next;
		}
	}

	int Hashh = c.get_ClientID() % 10;
	switch (Hashh) {
	case 1: {
		Arr[0].insertclient(c);
		break; }
	case 2: {
		Arr[1].insertclient(c);
		break; }
	case 3: {
		Arr[2].insertclient(c);
		break; }
	case 4: {
		Arr[3].insertclient(c);
		break; }
	case 5: {
		Arr[4].insertclient(c);
		break; }
	case 6: {
		Arr[5].insertclient(c);
		break; }
	case 7: {
		Arr[6].insertclient(c);
		break; }
	case 8: {
		Arr[7].insertclient(c);
		break; }
	case 9: {
		Arr[8].insertclient(c);
		break; }
	case 10: {
		Arr[9].insertclient(c);
		break; }
	}
	cout << "======================================================================" << endl;
}

void clientHome() {
	int num;
	cout << "+++++++++++ Welcome to the Banking System ++++++++++" << endl;
	cout << "+++++++++++ Welcome to the Home Page +++++++++++++++" << endl;
	cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS:" << endl;
	cout << "1. Transactions menu" << endl;
	cout << "2. View Personal info" << endl;
	cout << "3. LogOut" << endl;
	cin >> num;
	if (num == 1) { transactionsMenu(); }
	if (num == 2) {
		for (int i = 0; i < 10; i++) {
			LinkedListNode<Client<Transaction>>* tmpx = Arr[i].head;
			while (tmpx != NULL) {
				if (tmpx->data.get_ClientEmail() == keep->get_ClientEmail()) {
					tmpx->data.PrintClientinfo();
				}
				tmpx = tmpx->next;
			}
		}
		clientHome();
	}
	if (num == 3) { mainMenu(); }
}

void forgett() {
	Client<Transaction> c;
	string email;
	int existss = 0;
	cout << "Please enter your email " << endl;
	cin >> email;
	for (int i = 0; i < 10; i++) {
		LinkedListNode<Client<Transaction>>* tempn = Arr[i].head;
		while (tempn != NULL) {
			if (tempn->data.get_ClientEmail() == email)
			{
				existss = 1;
				cout << "Your Password Is: " << endl;
				cout << tempn->data.get_ClientPassword() << endl;
			}
			tempn = tempn->next;
		}
	}
	if (existss == 0) {
		cout << "This Email does not exist try again" << endl;
		cout<< "If you want to try again, Press '1', if you want to go the main menu Press '0'"<<endl;
		int num;
		cin>> num;
		if(num == 1){
         	forgett();
		}
		if(num == 0){
            mainMenu();
		}



	}
}

int keep_num=0;
int creatTransaction() {
	Transaction u;
	int transactionID;
	string transactionName;
	string transactionDate;
	cout << "Enter number of transactions you want to add" << endl;
	int num;
	cin >> num;
	keep_num = num;
	if (num > 5) {
		cout << "Invalid please choose from 1 to 5 " << endl;
		creatTransaction();
	}
	else {
		for (int i = 0; i < num; i++) {
			cout << "Enter transaction name: " << endl;
			cin >> transactionName;
			u.set_name(transactionName);
			cout << "Enter transaction ID: " << endl;
			cin >> transactionID;
			u.set_id(transactionID);
			cout<<"Enter transaction Date (In the format of: 14/Dec/2022): "<<endl;
			cin >> transactionDate;

			u.set_date(transactionDate);
			keep->arra[i] = u;
		}
	}
	transactionsMenu();
}

void Print_trans() {
	keep->get_trans(keep_num);
	transactionsMenu();
}

void deleteTransaction(int transactionId, Transaction* arr, int& size) {
	int exsits = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].get_id() == transactionId) {
			exsits = 1;
			for (int j = i; j < size - 1; j++) {
				arr[j] = arr[j + 1];
			}
			size--;
			cout << "Transaction with ID " << transactionId << " has been deleted!!" << endl;
		}
	}
	if (exsits == 0) {
		cout << "Not Found Try Again" << endl;
	}
	transactionsMenu();
}

void transactionsMenu() {
	int num;

	cout << "++++++++++++++++ Welcome to Transaction System ++++++++++++++++++++++++" << endl;
	cout << "Choose one of the following options: " << endl;
	cout << "1. Create a new transaction " << endl;
	cout << "2. View your transaction" << endl;
	cout << "3. Delete a transaction by its ID" << endl;
	cout << "4. If you want to return to main menu " << endl;
	cin >> num;
	if (num == 1) {
		creatTransaction();
	}
	else if (num == 2) {
            if(keep_num == 0){
                cout<< "There is no transactions"<<endl;
                transactionsMenu();
            }else{
		Print_trans();
            }
	}
	else if (num == 3) {
		int transactionId;
		cout << "Enter the transaction ID to be Deleted: " << endl;
		cin >> transactionId;
		deleteTransaction(transactionId, keep->arra, keep_num);
	}
	else if (num == 4)
	{
		mainMenu();

	}
	cout << "======================================================================" << endl;
}

int main() {
	Client<Transaction> c("z", "z", "z", "z");
	Client<Transaction> c2("z1", "z1", "z1", "z1");
	Client<Transaction> c3("z2", "z2", "z2", "z2");
	Client<Transaction> c4("zi", "zi", "zi", "zi");
	Client<Transaction> c5("i", "z1i", "z1i", "z1i");
	Client<Transaction> c6("z2i", "z2i", "z2i", "z2i");
	Arr[0].insertclient(c);
	Arr[1].insertclient(c2);
	Arr[1].insertclient(c3);
	Arr[8].insertclient(c4);
	Arr[8].insertclient(c5);
	Arr[8].insertclient(c6);
	mainMenu();
}
