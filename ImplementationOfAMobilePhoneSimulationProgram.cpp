#include <iostream>
#include <vector>
#include <string>

class PhoneNumber {
    std::string code = "+7";
public:
    std::string phoneNumber;
    std::string fullPhoneNumber;
    void setPhoneNumber() {
        std::cout << "Input the phone number without +7: \n";
        std::cout << "+7 ";
        std::cin >> phoneNumber;
        while (phoneNumber.length() != 10) {
            std::cout << "The phone number must consist of 10 digits.\nInput again: ";
            std::cout << "+7 ";            
            std::cin >> phoneNumber;
        }
        fullPhoneNumber = code + phoneNumber;
    }
    std::string getPhoneNumber() {
        return fullPhoneNumber;
    }
};

class Contact {
    std::string name;
    std::string number;
public:
    void setContact() {
        std::string nameEntered;
        std::cout << "Input name: ";
        std::cin >> name;
        PhoneNumber phoneNumber;
        phoneNumber.setPhoneNumber();
        number = phoneNumber.getPhoneNumber();
    }
    std::string getName() {
        return name;
    }
    std::string getNumber() {
        return number;
    }
};

class Phone {
    std::vector<Contact> addressBook;
public:
    void add() {
        Contact contact;
        contact.setContact();
        addressBook.emplace_back(contact);
        std::cout << "Contact added.\n";
    }
    std::string inputContactOrNumber() {
        std::string userInput;
        std::cout << "Input the contact's name or phone number: ";
        std::cin >> userInput;
        if (userInput[0] == '+' && userInput[1] == '7') {
            while (userInput.length() != 12) {
                std::cout << "The phone number must consist of 10 digits.\nInput again: ";
                std::cout << "+7";            
                std::cin >> userInput;
                userInput = "+7" + userInput;
            }
        }
        return userInput;
    }
    void call() {
        std::string contactOrNumber = inputContactOrNumber();
        if (contactOrNumber[0] == '+' && contactOrNumber[1] == '7') {
            for (int i = 0; i < addressBook.size(); i++) {
                if (contactOrNumber == addressBook[i].getNumber()) {
                    std::cout << "CALL " << addressBook[i].getName() << ": " << contactOrNumber << std::endl;
                    break;
                } else if ((i == addressBook.size() - 1) && (contactOrNumber != addressBook[i].getNumber()))
                    std::cout << "CALL " << contactOrNumber << std::endl;
            }
        } else {
            for (int i = 0; i < addressBook.size(); i++) {
                if (contactOrNumber == addressBook[i].getName()) {
                    std::cout << "CALL " << addressBook[i].getName() << ": " << addressBook[i].getNumber() << std::endl;
                    break;
                } else if ((i == addressBook.size() - 1) && (contactOrNumber != addressBook[i].getName()))
                    std::cout << "There is no such contact..." << std::endl;
            }                  
        }
    }
    
    void sms() {
        std::string contactOrNumber = inputContactOrNumber();
        std::string SMS;
        if (contactOrNumber[0] == '+' && contactOrNumber[1] == '7') {
            for (int i = 0; i < addressBook.size(); i++) {
                if (contactOrNumber == addressBook[i].getNumber()) {
                    std::cout << "SMS for " << addressBook[i].getName() << " number " << contactOrNumber << std::endl;
                    std::cout << "Input SMS:\n";
                    std::cin >> SMS;
                    std::cout << "SMS sent.\n";
                    break;
                } else if ((i == addressBook.size() - 1) && (contactOrNumber != addressBook[i].getNumber())) {
                    std::cout << "SMS for number " << contactOrNumber << std::endl;
                    std::cout << "Input SMS:\n";
                    std::cin >> SMS;
                    std::cout << "SMS sent.\n";
                }
            }
        } else {
            for (int i = 0; i < addressBook.size(); i++) {
                if (contactOrNumber == addressBook[i].getName()) {
                    std::cout << "SMS for " << addressBook[i].getName() << " number " << addressBook[i].getNumber() << std::endl;
                    std::cout << "Input SMS:\n";
                    std::cin >> SMS;
                    std::cout << "SMS sent.\n";
                    break;
                } else if ((i == addressBook.size() - 1) && (contactOrNumber != addressBook[i].getName()))
                    std::cout << "There is no such contact..." << std::endl;
            }
        }
    }
};
  
int main() {
    std::cout << "\t\t******************************************************\n"
              << "\t\t*   Implementation of a mobile phone simulation      *\n"
              << "\t\t*                       program                      *\n"
              << "\t\t* -------------------------------------------------- *\n"
              << "\t\t* Commands for working with the mobile phone:        *\n"
              << "\t\t* \"add\" - adds a new contact to the address book;    *\n"
              << "\t\t* \"call\" - calling a contact;                        *\n"
              << "\t\t* \"sms\" - send a message.                            *\n"
              << "\t\t* To exit the programm, enter \"exit\"                 *\n"
              << "\t\t******************************************************\n";

    std::string command;

    Phone* phone = new Phone();

    while (command != "exit") {
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "add")
            phone->add();
        else if (command == "call")
            phone->call();
        else if (command == "sms")
            phone->sms();
        else if (command != "exit")
            std::cout << "Invalid command name. Input again.\n";
    }
    std::cout << "Exiting the programm...";
    delete phone;
    phone = nullptr;
}