#include <iostream>
#include <string>

using namespace std;

struct Record{
    string nama;
    string nisn;
    float nilai;
    Record(string NISN, string NAMA, float NILAI){
        nama = NAMA;
        nisn = NISN;
        nilai = NILAI;
    }
    //Null constructor
    Record(){

    }
};

void printRecord(Record arrOfRecord[], int recordSize){
    for (int i = 0; i < recordSize; i++) {
        cout<< arrOfRecord[i].nisn << " " << arrOfRecord[i].nama << " " << arrOfRecord[i].nilai << "\n";
    }
    
}

void insertionSort(Record arrOfRecord[], int arrSize){
    int i, j;
    Record key;  
    for (i = 1; i < arrSize; i++) {  
        key = arrOfRecord[i]; 
        j = i - 1;  
  
        while (j >= 0 && arrOfRecord[j].nama > key.nama) {  
            arrOfRecord[j + 1] = arrOfRecord[j];  
            j = j - 1;  
        }  
        arrOfRecord[j + 1] = key;
    }  
}

int main(){
    Record records[6] = {
        Record("9960312699", "Handi Ramadhan", 90),
        Record("9963959682", "Rio", 75),
        Record("9950310962", "Ronaldo", 70),
        Record("9970272750", "Achmad", 60),
        Record("9952382180", "Alivia", 90),
        Record("9965653989", "Arief", 80)
    };

    printRecord(records, 6);
    cout<< "\nSORT\n";
        insertionSort(records, 6);
    printRecord(records, 6);


}