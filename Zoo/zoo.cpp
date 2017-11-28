#include <iostream>
#include <string>

using namespace std;

class Animal{
    private:
        string name;
        string kind;
        int age;
        int numberOfPaws;
        int health;
        bool isShow;

    public:
        Animal (){
            name = " ";
            kind = " ";
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
            cout << health << "   ||";
            cout.width (11);
            if(isShow == 1){
                cout<<"Animal at the show"<<endl;
            }
            if(isShow == 0){
                cout<<"Animal at the aviary"<<endl;
            }
            cout << endl << "====================================================================================================" << endl ;
        }
};

class Zoo : public Animal{
    private:
        Animal arrayAnimals[50];
        int numberOfAnimals;
        int deleteIndexOfAnimal;
    public:
        Zoo(){
            numberOfAnimals = 0;
            deleteIndexOfAnimal = 0;
        }

        void showAnimals(){
            cout << endl << "====================================================================================================" << endl <<"| " ;
            printf("%15s%15s%15s%15s%15s%15s", "Animal name  ||" , "kind  ||", "age  ||" , "numberOfPaws  ||" , "health  ||", "exhibition or avail  |");
            cout << endl << "====================================================================================================" << endl;

            for (short j = 0; j < numberOfAnimals; j++ ){
                arrayAnimals[j].show();
            }
        }

        void addAnimal(){
            arrayAnimals[numberOfAnimals].add();
            numberOfAnimals++;
        }

        void deleteAnimal(){
            cout<<"Which animal you want to delete? Select its index"<<endl;
            cin >> deleteIndexOfAnimal;
            Animal newArrayAnimals[50];
            int j = 0;

            for(int i = 0; i < numberOfAnimals; i++){
                if (i != deleteIndexOfAnimal){
                    newArrayAnimals[j] = arrayAnimals[i];
                    j++;
                }
            }

            numberOfAnimals--;
            for (int i = 0; i < numberOfAnimals; i++){
                arrayAnimals[i] = newArrayAnimals[i];
            }
        }
};

class Manager{
    public:
    int selector;
        Zoo zooManager;
        void manager(){
            do{
                cout << "1: Add animal \n" << "2: Look information about animals\n" << "3: Delete animal\n" << "4: Exit \n\n";

                do{
                    cout << "your choose:   " ;
                    cin >> selector ;
                    if (selector < 1 || selector > 4){
                        cout << "Wrong choose...Try again \n" << endl;
                    }
                }while (selector < 1 || selector > 4);

                switch (selector){
                    case 1:
                        zooManager.addAnimal();
                        break;
                    case 2:
                        zooManager.showAnimals();
                        break;
                    case 3:
                        zooManager.deleteAnimal();
                        break;
                }

            }while (selector != 4);
        }
};

int main (){
    Manager m;
    m.manager();
}

