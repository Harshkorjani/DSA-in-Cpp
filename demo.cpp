#include <iostream>
#include <string>
#include <utility>  // for std::pair
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode** children;
    bool isTerminal;
    string contactName;

    TrieNode(char data) : data(data), isTerminal(false), contactName("") {
        children = new TrieNode*[10]{}; // Use {} to initialize with nullptr
    }

    ~TrieNode() {
        delete[] children;
    }
};

class PhoneBookTrie {
    TrieNode* root;

public:
    PhoneBookTrie() : root(new TrieNode('\0')) {}

    void insertContact(const string& phoneNumber, const string& contactName) {
        insertContact(root, phoneNumber, contactName);
    }

    pair<bool, string> searchContact(const string& phoneNumber) {
        return searchContact(root, phoneNumber);
    }

    void removeContact(const string& phoneNumber) {
        removeContact(root, phoneNumber);
    }

private:
    void insertContact(TrieNode* root, const string& phoneNumber, const string& contactName) {
        if (phoneNumber.empty()) {
            root->isTerminal = true;
            root->contactName = contactName;
            return;
        }

        int index = phoneNumber[0] - '0';
        TrieNode*& child = root->children[index];
        if (!child) {
            child = new TrieNode(phoneNumber[0]);
        }

        insertContact(child, phoneNumber.substr(1), contactName);
    }

    pair<bool, string> searchContact(TrieNode* root, const string& phoneNumber) {
        if (phoneNumber.empty()) {
            return {root->isTerminal, root->contactName};
        }

        int index = phoneNumber[0] - '0';
        TrieNode* child = root->children[index];
        return (child) ? searchContact(child, phoneNumber.substr(1)) : make_pair(false, "");
    }

    void removeContact(TrieNode* root, const string& phoneNumber) {
    if (phoneNumber.empty()) {
        root->isTerminal = false;
        root->contactName = "";
        return;
    }

    int index = phoneNumber[0] - '0';
    TrieNode* child = root->children[index];
    if (child) {
        removeContact(child, phoneNumber.substr(1));

        // Check if the child has no terminal data and no children
        if (!child->isTerminal) {
            for (int i = 0; i < 10; i++) {
                if (child->children[i]) {
                    return;
                }
            }
            // No children, delete the child
            delete child;
            root->children[index] = nullptr;
        }
    }
}

};

int main() {
    PhoneBookTrie phoneBook;
    int choice;
    int n;
    string contactN, name;

    cout << "Enter the number of contacts you want to save: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter phone number and contact name: ";
        cin >> contactN >> name;
        phoneBook.insertContact(contactN, name);
    }

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Remove Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    

        switch(choice) {
            case 1:
                cout << "Enter phone number and contact name: ";
                cin >> contactN >> name;
                phoneBook.insertContact(contactN, name);
                break;

            case 2:
                cout << "Enter phone number to search: ";
                cin >> contactN;
                std::pair<bool,string> result = phoneBook.searchContact(contactN);
                if (result.first) {
                    cout << "Contact found: " << result.second << endl;
                } else {
                    cout << "Contact not found." << endl;
                }
                break;

            case 3:
                cout << "Enter phone number to remove: ";
                cin >> contactN;
                phoneBook.removeContact(contactN);
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}