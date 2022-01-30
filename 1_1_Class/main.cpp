#include <iostream>

using namespace std;

class Person {
    string f;
    string i;
    string o;
    int age;
    int average_score;
    public:
    Person(string ff, int aage, int a_s, string ii = "", string oo = "") { 
        f = ff; 
        i = ii;
        o = oo;
        age = aage;
        average_score = a_s;
    }
    Person(const Person & p) {
        f = p.f; 
        i = p.i;
        o = p.o;
        age = p.age;
        average_score = p.average_score;
    }
    void print() {cout << f << "\t" << i << "\t" << o << "\t" << age << "\t" << average_score << endl;}
    int get_age() {return age;}
    int get_average_score() {return average_score;}
};

void sort_age( Person** p, size_t s) {
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - i - 1; j++) {
            if ((*(p + j))->get_age() > (*(p + j + 1))->get_age()) {
                // меняем элементы местами
                Person pp = *p[j];
                *p[j] = *p[j + 1];
                *p[j + 1] = pp;
            }
        }
    }
}

void sort_average( Person** p, size_t s) {
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - i - 1; j++) {
            if ((*(p + j))->get_average_score() > (*(p + j + 1))->get_average_score()) {
                // меняем элементы местами
                Person pp = *p[j];
                *p[j] = *p[j + 1];
                *p[j + 1] = pp;
            }
        }
    }
}

int main(int argc, char** argv)
{  
    cout << "Hello World!\n";

    srand(time(nullptr));

    // fill
    Person** persons = new Person*[10];

    for (size_t i = 0; i < 10; i++)
    {
        Person* p = new Person(std::string(1, static_cast<char>('a'+i)), rand() % 100, rand() % 100);
        persons[i] = p;
    }
    
    for(size_t i = 0; i < 10; i++) {
        persons[i]->print();
    }

    cout << "Sort by age\n";
    sort_age(persons, 10);

    for(size_t i = 0; i < 10; i++) {
        persons[i]->print();
    }
    
    cout << "Sort by average score\n";
    sort_average(persons, 10);

    for(size_t i = 0; i < 10; i++) {
        persons[i]->print();
    }

    for(size_t i = 0; i < 10; i++){
        delete persons[i];
    }
    delete [] persons;
    return 0;
}