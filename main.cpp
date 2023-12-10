#include <iostream>
#include <cmath>
using namespace std;
class Zoo {
private:
    char* name;
    char* country;
    char** animals;
    int* time;
    int ticket;
    int number_of_animals;
public:
    Zoo() {
        name = "Не указано";
        country = "Не указано";
        animals = nullptr;
        time = nullptr;
        ticket = 0;
        number_of_animals = 0;
    }
    Zoo(char* name,char* country,char** animals, int* time,int ticket,int number_of_animals) {//Конструктор с параметрами
        this-> name = name;
        this-> country = country;
        this-> animals = animals;
        this-> time = time;
        this-> ticket = ticket;
        this-> number_of_animals = number_of_animals;
    }
    Zoo(const Zoo &other) {
        name = other.name;
        country = other.country;
        animals = other.animals;
        time = other.time;
        ticket = other.ticket;
        number_of_animals = other.number_of_animals;
    }

    ~Zoo() {
        delete[] name;
        delete[] country;
        delete[] animals;
        delete[] time;
    }

    void printName(){
        cout << "Name: " << name << endl;
    }
    void printCountry(){
        cout << "Country: " << country << endl;
    }
    void printAnimals(){
        cout << "Animals: ";
        for (int i =0;i<number_of_animals;i++)
            cout << animals[i] << "\t";
        cout<<endl;
    }
    void printTime(){
        cout<<"Working time: ";

        if (time[0]==0)
            cout << "00";
        if (time[0]<10 && time[0]!=0)
            cout << "0" <<time[0];
        if (time[0]>9)
            cout << time[0];

        cout<<":";

        if (time[1]==0)
            cout << "00";
        if (time[1]<10 && time[1]!=0)
            cout << "0" <<time[1];
        if (time[1]>9)
            cout << time[1];

        cout<<"-";

        if (time[2]==0)
            cout << "00";
        if (time[2]<10 && time[2]!=0)
            cout << "0" <<time[2];
        if (time[2]>9)
            cout << time[2];

        cout<<":";

        if (time[3]==0)
            cout << "00";
        if (time[3]<10 && time[3]!=0)
            cout << "0" <<time[3];
        if (time[3]>9)
            cout << time[3];

        cout<<endl;
    }
    void printTicket(){
        cout << "Ticket price: " << ticket << endl;
    }
    void printNumber(){
        cout << "Number of animals: " << number_of_animals << endl;
    }
    void printAll() {
        cout << "Name: " << name << endl;
        cout << "Country: " << country << endl;
        cout << "Animals: ";
        for (int i =0;i<number_of_animals;i++)
            cout << animals[i] << "\t";
        cout << "Working hours: " << time << endl;
        cout << "Ticket price: " <<time[0]<<":"<<time[1]<<"-"<<time[2]<<":"<<time[3] << endl;
        cout << "Number of animals: " << number_of_animals << endl;
    }




    void readName(char* name2){
        name = name2;
    }
    void readCountry(char* country2){
        country = country2;
    }
    void readAnimals(char** animals2){
        animals = animals2;
    }
    void readTime(int* time2){
        time = time2;
    }
    void readTicket(int ticket2){
        ticket = ticket2;
    }
    void readNumber(int number2){
        number_of_animals = number2;
    }
    void readAll(char* name2,char* country2,char** animals2,int* time2,int ticket2,int number2) {
        name = name2;
        country = country2;
        animals = animals2;
        time = time2;
        ticket = ticket2;
        number_of_animals = number2;
    }

    //LAB 6
    int animals_time(int n) {
        int a1 = time[0]*60 + time[1];
        int a2 = time[2]*60 + time[3];
        int a3 = a2 - a1;
        return floor(a3/n);
    }

    char** spisokZooCoef(Zoo* zoos,int m){
        char** zooNames = new char*[m];
        float* zooCoef = new float[m];

        for (int i =0;i<m;i++){
            zooNames[i]=zoos[i].name;
            zooCoef[i]=(zoos[i].ticket/zoos[i].number_of_animals);
        }
        int n = m;
        while(n--){
            int flag=0;
            for (int j = 0;j <n;j++){
                if(zooCoef[j] > zooCoef[j+1]){
                    swap(zooCoef[j],zooCoef[j+1]);
                    swap(zooNames[j],zooNames[j+1]);
                    flag=1;
                }
            }
            if (flag==0)
                break;
        }
        return zooNames;
    }


    char** spisokZooCountry(Zoo* zoos,int m,char* X){
        char** spisok = new char*[m];

        int c = 0;
        for (int i = 0;i<m;i++){
            if (zoos[i].country == X){
                spisok[i]=zoos[i].name;
                c++;
            }
            if (zoos[i].country != X)
                spisok[i]="0";
        }
        char** resultat = new char*[c];
        int k = 0;
        for (int j = 0;j<m;j++){
            if (spisok[j]!="0"){
                resultat[j-k]=spisok[j];
            }
            else
                k++;
        }
        return resultat;
    }





};
int main() {
    Zoo first;

    char** animalSecond = new char*[2];
    animalSecond[0]="bear";
    animalSecond[1]="wolf";
    int* timeSecond = new int[4];
    timeSecond[0]=12;
    timeSecond[1]=0;
    timeSecond[2]=19;
    timeSecond[3]=30;
    Zoo second("Moskovskiy","Russia",animalSecond,timeSecond,25,2 );

    Zoo third(second);

    third.readName("Leningradskiy zoopark");
    third.readCountry("Russia");
    third.readTicket(30);
    third.readNumber(4);
    char** animalThird = new char*[4];
    animalThird[0]="snake";
    animalThird[1]="lion";
    animalThird[2]="elephant";
    animalThird[3]="fox";
    int* timeThird = new int[4];
    timeThird[0]=9;
    timeThird[1]=0;
    timeThird[2]=20;
    timeThird[3]=45;
    third.readAnimals(animalThird);
    third.readTime(timeThird);

    third.printName();
    third.printCountry();
    third.printAnimals();
    third.printTime();
    third.printTicket();
    third.printNumber();

    cout<<endl;


    //Lab6
    //1
    int a = third.animals_time(3);
    cout << a << endl;

    cout<<endl;


    //2
    char** animalFourth = new char*[1];
    animalFourth[0]="rhinoceros";
    int* timeFourth = new int[4];
    timeFourth[0]=6;
    timeFourth[1]=0;
    timeFourth[2]=23;
    timeFourth[3]=0;
    Zoo fourth("San Diego zoo","USA",animalFourth,timeFourth,100,1 );
    Zoo* zoos = new Zoo[3];
    zoos[0]=second;
    zoos[1]=fourth;
    zoos[2]=third;


    char** b = third.spisokZooCoef(zoos,3);
    for (int i = 0;i<3;i++)
        cout<<b[i]<<endl;

    cout<<endl;

    //3
    char** c = third.spisokZooCountry(zoos,3,"Russia");
    for (int i = 0; i < 3;i++)
        cout<<c[i]<<endl;





}