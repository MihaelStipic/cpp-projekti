#include <iostream>
#include <vector>
using namespace std;




class Account {
private:
    vector<string> transactions;
    int accountNumber;
    string ownerName;
    double balance;

public:
    Account(int accNum, string name);
    bool deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    void transaction(string msg);

    int getAccountNumber() const;
    double getBalance() const;
    void showTransactions();
};












void Account::showTransactions() {
    if (transactions.empty()) {
        cout<<"Nema transakcija!"<<endl;
        return;
    }
    for (auto &x: transactions) {
        cout<<x<<" ";
    }
    cout<<endl;
}

void Account::transaction(string msg) {
    transactions.push_back(msg);

}

Account::Account(int accNum, const string name) :transactions {} , accountNumber(accNum), ownerName (name), balance(0) {}

bool Account::deposit(double amount) {
    if (amount < 0) {
        cout << "Ne mozete uplatiti negativan iznos." << endl;
        return false;
    }
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount < 0) {

        return false;
    }
    if (amount <= balance) {
        balance -= amount;
        return true;
    } else {
        return false;
    }

}

void Account::display() const {
    cout<<ownerName<<" na racunu ima "<<balance<<" EUR"<<endl;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}












class Bank {
private:

    vector<Account*> accounts;
    int nextAccountNumber;

public:
    Bank();
    int createAccount(const string &ownerName);
    void depositToAccount(int accNum, double amount);
    void withdrawFromAccount(int accNum, double amount);
    int showAccount(int accNum);
    void listAllAccounts();
    void transactionLog(int accNum, string msg);
    void showTransactions(int accNum);
    ~Bank();

    Account* findAccount(int accNum);
};












Bank::~Bank() {
    for (auto x : accounts) {
        delete x;
    }
}

void Bank::showTransactions(int accNum) {
    Account* acc = findAccount(accNum);
    if (acc != nullptr) {
        acc->showTransactions();
    } else {
        cout << "Racun broj " << accNum << " nije pronaden." << endl;
    }


}

void Bank::transactionLog(int accNum, string msg) {
    Account* acc = findAccount(accNum);
    if (acc != nullptr) {
        acc->transaction(msg);
    } else {
        cout << "Racun ne postoji" << endl;
    }


}

Bank::Bank() : accounts{}, nextAccountNumber(0) {
}

int Bank::createAccount(const string &ownerName) {
    Account *novi = new Account (nextAccountNumber, ownerName);
    accounts.push_back(novi);
    return nextAccountNumber++;
}

void Bank::depositToAccount(int accNum, double amount) {
    Account *acc = findAccount(accNum);

    if (acc != nullptr) {
        bool provjera = acc->deposit(amount);
        if (provjera == true ){

        cout << "Uplaceno " << amount << " EUR na racun " << accNum << endl;
        transactionLog(accNum, ("Uplata od "+ to_string(amount)+ " EUR."));
        return;
        }

    }else {
        cout << "Racun broj " << accNum << " nije pronaden." << endl;
    }




}


void Bank::withdrawFromAccount(int accNum, double amount) {

    Account *acc = findAccount(accNum);

    if (acc != nullptr) {
        if (amount < 0) {
            cout << "Ne mozete podignuti negativan iznos." << endl;
            return;
        }
        if (acc->withdraw(amount)) {
            cout << "Podignuto " << amount << " EUR s racuna " << accNum << endl;
            transactionLog(accNum, ("Isplata od "+ to_string(amount)+" EUR."));
            return;
        } else {
            cout << "Nedovoljno sredstava na racunu " << accNum << endl;
            return;
        }
    }else {
        cout << "Racun broj " << accNum << " nije pronaden." << endl;
    }
}

int Bank::showAccount(int accNum) {

    Account* acc = findAccount(accNum);

    if (acc != nullptr) {
        cout << "Racun broj " << acc->getAccountNumber() << " na racunu ima " << acc->getBalance() << " EUR." << endl;
        return 0;
    } else {
        cout << "Racun broj " << accNum << " nije pronaden." << endl;
        return 1;
    }

}

void Bank::listAllAccounts() {
    if (accounts.empty()) {
        cout<<"Prazna lista!"<<endl;
        return;
    }

    for (const auto &x : accounts) {
        cout<<"Racun broj "<<x->getAccountNumber()<<" ";
        x->display();
    }
}

Account * Bank::findAccount(int accNum) {
    for (auto &x: accounts) {
        if (accNum == x->getAccountNumber()) {
            return x;
        }
    }
    return nullptr;
}







int main() {
    Bank B;
    B.createAccount("Marko Filipovic");
    B.depositToAccount( 0, 100);
    B.withdrawFromAccount(0, 50);
    B.createAccount("Ivan Kunce");
    B.depositToAccount( 1, 1200);
    B.withdrawFromAccount(1, 530);
    int broj;

do {

    cout<<"|-----------------------------------------|\n   Dobrodosli u online bankarstvo!"<<endl;
    cout<< "   Odaberite jednu od sljedecih opcija: "<<endl;
    cout<< "   1. Izrada racuna"<<endl;
    cout<< "   2. Pronalazak racuna"<<endl;
    cout<< "   3. Lista svih racuna"<<endl;
    cout<< "   4. Uplata na racun"<<endl;
    cout<< "   5. Isplata s racuna"<<endl;
    cout<< "   6. Transakcije racuna"<<endl;
    cout<< "   0. Izlaz"<<endl;
    cout<<"|-----------------------------------------|"<<endl<<endl;
    cin>>broj;
    cin.ignore(); // crash nakon sto se upise broj 1 i ime s razmakom, ovo je fix
    switch (broj) {
        case 1: {
            string osoba;
            cout<<"Unesite ime osobe: ";
            getline(cin, osoba); // crash nakon sto se upise broj 1 i ime s razmakom, ovo je fix

            if (osoba.empty()) {
                cout << "Ime ne smije biti prazno!" << endl;
                break;
            }

            int brojRac = B.createAccount(osoba);
            cout << "Racun je uspjesno kreiran. Broj racuna: " << brojRac << endl;

            break;
        }
        case 2: {


            int brojRac;
            cout<< "Unesite broj racuna: ";
            cin>>brojRac;
            B.showAccount(brojRac);



            break;
        }
        case 3:
            B.listAllAccounts();
        break;
        case 4: {
            int brojRac;
            double iznos;
            cout << "Unesite broj racuna: ";
            cin >> brojRac;
            cout << "Unesite iznos za uplatu: ";
            cin >> iznos;
            B.depositToAccount(brojRac, iznos);
            break;
        }

        case 5: {
            int brojRac;
            double iznos;
            cout << "Unesite broj racuna: ";
            cin >> brojRac;
            cout << "Unesite iznos za isplatu: ";
            cin >> iznos;
            B.withdrawFromAccount(brojRac, iznos);
            break;
        }
        case 6: {
            int brojRac;
            cout << "Unesite broj racuna: ";
            cin >> brojRac;
            B.showTransactions(brojRac);
            break;

        }
        case 0:
            cout << "Hvala sto koristite nas online bankarski sustav!" << endl;
        break;
        default:
            cout << "Nepostojeca opcija." << endl;
    }
}while (broj!=0);





}
