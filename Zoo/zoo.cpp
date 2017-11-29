#include <iostream>
#include <string>

using namespace std;

class Animal{
    private:
        char* name;
        char* kind;
        int age;
        int numberOfPaws;
        int health;
        bool isShow;

    public:
        Animal (){
            name = new char[20];
            kind = new char[20];
            age = 0;
            numberOfPaws = 0;
            health = 0;
            isShow = false;
        }

        void add(){
            cout << endl ;
            cout << "Animal name:   ";
            cin >> name;
            cout << "kind:   ";
            cin >> kind;
            cout << "age:   ";
            cin >> age;
            cout << "numberOfPaws:   ";
            cin >> numberOfPaws;
            cout << "health:   ";
            cin >> health;
            cout << "Is animal at the exhibition?(1/0)"<<endl;
            cin >> isShow;
        }

        void show(){
            cout <<"| ";
            cout.width (11);
            cout << name << "  ||";
            cout.width (11);
            cout << kind << "  ||";
            cout.width (11);
            cout << age << "  ||";
            cout.width (11);
            cout << numberOfPaws << "   ||";
            cout.width (11);
            cout << health << "  ||";
            cout.width (11);
            if(isShow == 1){
                cout<<"Animal at the show  |" << endl;
            }
            if(isShow == 0){
                cout<<"Animal at the aviary  |" << endl;
            }
            cout << "===================================================================================================" << endl;
        }
};

class Zoo{
    private:
        Animal arrayAnimals[50];
        int numberOfAnimals;
        int deleteIndexOfAnimal;
        int editIndexOfAnimal;
    public:
        Zoo(){
            numberOfAnimals = 0;
            deleteIndexOfAnimal = 0;
        }

        void showAnimals(){
            cout << endl << "===================================================================================================" << endl <<"| " ;
            printf("%15s%15s%15s%15s%15s%15s", "Animal name  ||" , "kind  ||", "age  ||" , "numberOfPaws  ||" , "health  ||", "exhibition or avail |");
            cout << endl << "===================================================================================================" << endl;

            for (short j = 1; j <= numberOfAnimals; j++ ){
                arrayAnimals[j].show();
            }
        }

        void addAnimal(){
            numberOfAnimals++;
            arrayAnimals[numberOfAnimals].add();
        }

        void deleteAnimal(){
            cout << "What animal do you want to delete? Select an index" << endl;
            cin >> deleteIndexOfAnimal;
            if (deleteIndexOfAnimal <= numberOfAnimals) {
                while (deleteIndexOfAnimal < numberOfAnimals) {
                    arrayAnimals[deleteIndexOfAnimal] = arrayAnimals[deleteIndexOfAnimal + 1];
                    deleteIndexOfAnimal++;
                }
                numberOfAnimals--;
            }
        }

        void editAnimal(){
            cout << "What animal do you want to edit? Select an index" << endl;
            cin >> editIndexOfAnimal;
            arrayAnimals[editIndexOfAnimal].add();
        }
};

class Manager{
    public:
        int selector;
        Zoo zooManager;
        void manager(){
            do{
                cout << "1: Add animal \n" << "2: Look information about animals\n" << "3: Edit animal\n" << "4: Delete animal\n" << "5: Exit \n\n";

                do{
                    cout << "your choose:   " ;
                    cin >> selector ;
                    if (selector < 1 || selector > 5){
                        cout << "Wrong choose...Try again \n" << endl;
                    }
                }while (selector < 1 || selector > 5);

                switch (selector){
                    case 1:
                        zooManager.addAnimal();
                        break;

                    case 2:
                        zooManager.showAnimals();
                        break;

                    case 3:
                        zooManager.editAnimal();
                        break;

                    case 4:
                        zooManager.deleteAnimal();
                        break;
                }

            }while (selector != 5);
        }
};

int main (){
    Manager m;
    m.manager();
}

