#include <iostream>
#include <string>

using namespace std ;

class Animal
{
    private:
        string name;
        int age;
        int numberOfPaws;
        int health;
        string kind;

    public:
        string _name;

        Animal (){
            name = _name;
            kind = " ";
            age = 0;
            numberOfPaws = 0;
            health = 0;
        }

        void addAnimal(){
            cout << endl ;
            cout << "Animal name:   "; 
            cin >> _name;
            cout << "kind:   "; 
            cin >> kind;
            cout << "age:   ";
            cin >> age;
            cout << "numberOfPaws:   ";
            cin >> numberOfPaws;
            cout << "health:   ";
            cin >> health;
        }

        void showAnimals(){
            cout <<"| ";
            cout.width (11);
            cout << _name << "  ||";
            cout.width (11);
            cout << kind << "  ||";
            cout.width (11);
            cout << age << "  ||";
            cout.width (11);
            cout << numberOfPaws << "   ||";
            cout.width (11);
            cout << health << "   |";
            cout << endl << "==============================================================================" << endl ;
        }

        void deleteAnimal(){
            _name = " ";
            kind = " ";
            age = 0;
            numberOfPaws = 0;
            health = 0;
        }

        void editInformationAboutAnimal(){
            int selector;

            cout << "What information do you want edit: \n";
            cout << "1 - name\n";
            cout << "2 - kind\n";
            cout << "3 - age\n";
            cout << "4 - numberOfPaws\n";
            cout << "5 - health\n";
            cout << "6 - exit to menu\n\n";

            do{
                cout << "your choose:   " ;
                cin >> selector;

                switch(selector){
                    case 1:
                        cout << "Enter new name: ";
                        cin >> _name;
                        break;

                    case 2:
                        cout << "Enter new kind: ";
                        cin >> kind;
                        break;

                    case 3:
                        cout << "Enter new age: ";
                        cin >> age;
                        break;

                    case 4:
                        cout << "Enter new numberOfPaws: ";
                        cin >> numberOfPaws;
                        break;

                    case 5:
                        cout << "Enter new health: ";
                        cin >> health;
                        break;
                }
            }while(selector != 6);

        }
};

class Zoo : public Animal{
    public:
        Zoo() : Animal(){

        }

        ~Zoo(){

        }
};

int main (){
    int selector;
    int i = -1;
    string deleteAnimal;
    string editAnimal;
    Zoo animals[20];

    do{
        cout << "1: Add animal \n" << "2: look animals\n" << "3: look information about animals\n" << "4: edit information\n" << "5: delete\n" << "6: Exit \n\n";

        do{
            cout << "your choose:   " ;
            cin >> selector ;
            if (selector < 1 || selector > 6){
                cout << "Wrong choose...Try again \n" << endl;
            }
        }while (selector < 1 || selector > 6);

        switch (selector){
            case 1:
                i++ ;
                animals[i].addAnimal() ;
                break;

            case 2:
                if (i == -1){
                  cout << "There is nothing to show..." << endl ;
                  break;
                }

                cout << endl << "==============================================================================" << endl <<"| " ;
                printf("%15s%15s%15s%15s%15s", "Animal name  ||" , "kind  ||", "age  ||" , "numberOfPaws  ||" , "health  |");
                cout << endl << "==============================================================================" << endl;

                for (short j = 0; j <= i; j++ ){
                    animals[j].showAnimals();
                }
                break;

            case 3:
                if (i == -1){
                    cout << "There is nothing to show..." << endl ;
                    break;
                }

            for (int j = 0; j <= i; j++ ){
               cout << animals[j]._name << endl;
            }
            break;

            case 4:
                if (i == -1){
                    cout << "There is nothing to edit..." << endl ;
                    break;
                }

                cout << "What animal do you want edit(enter name): ";
                cin >> editAnimal;

                for (int j = 0; j <= i; j++ ){
                    if(animals[j]._name == editAnimal){
                        cout << endl << "==============================================================================" << endl <<"| " ;
                        printf("%15s%15s%15s%15s%15s", "Animal name  ||" , "kind  ||", "age  ||" , "numberOfPaws  ||" , "health  |");
                        cout << endl << "==============================================================================" << endl;
                        animals[j].showAnimals();
                        animals[j].editInformationAboutAnimal();
                    }
                }
                break;

            case 5:
                if (i == -1){
                    cout << "There is nothing to delete..." << endl ;
                    break;
                }

                cout << "What animal do you want delete(enter name): ";
                cin >> deleteAnimal;

                for (short j = 0; j <= i; j++ ){
                    if(animals[j]._name == deleteAnimal){
                        animals[j].deleteAnimal();
                    }
                }
                break;

            case 6:
                return 0;
        }

    }while (selector != 6 );
}

