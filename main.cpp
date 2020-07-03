//
//  main.cpp
//  AiSD_11
//
//  Created by Piotr Sularz on 09/01/2020.
//  Copyright © 2020 Piotr Sularz. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class HashTable1{
    private:
        string* t;
        int capacity;
        int ht_size; //ilosc aktulnie przechowywanych
    public:
    HashTable1(int c){    //konstruktor tworzący pustą tablicę o pojemności c
        t=new string[c];
        capacity=c;
        ht_size=0;
    }
    int hashF(string s){    //funkcja haszująca dla ciągu s
        int k = capacity;
        int a = 7;
        int n = (int)s.length();
        int wynik = 0;
        for(int i=0;i<n;i++){
            wynik+=pow( a,n-1-i)*(s.at(i)-64);
        }
        wynik = wynik%k;
        return wynik;
    }
    void insert(string s){    //wstawienie ciągu s
        if(ht_size<capacity){
            int pozycja = hashF(s);
            if(t[pozycja] ==""){
                t[pozycja]=s;
            }
            else{
                while (t[pozycja]!="") {
                    pozycja++;
                    if(pozycja==capacity){
                        pozycja=0;
                    }
                }
                t[pozycja]=s;
            }
            ht_size++;
        }
    }
    string search(string s){//wyszukuje i zwraca s
        string slowo = "";
        int pozycja = hashF(s);
        while(t[pozycja]!=s){
            pozycja++;
            if(pozycja==capacity){
                pozycja=0;
            }
        }
        slowo = t[pozycja];
        return slowo;
    }
    
    friend ostream& operator<<(ostream& out, HashTable1& ht){ //wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól
        for(int i=0;i<ht.capacity;i++){
            out<<i+1<<": "<<ht.t[i]<<"\n";
        }
        return out;
    }
};

int naiwnyWyszaj(string T,string P,int n,int m){
    int i=0;
    while(i<n-m+1){
        int j = 0;
        int k=i;
        while(P[j]==T[k]){
            if(j==m-1){
                cout<<"Znaleziono na pozycji: "<<i<<"\n";
                break;
            }
            j++;
            k++;
        }
        i++;
    }
    return i;
}

int bayeraMoora(string T,string P,int n,int m){
    int i = 0;
    int s = 1;
    while(i<n-m+1){
        int j=m-1;
        while(P[j]==T[i+j-1] && j>0){
            j--;
        }
        cout<<i;
        if(j==0){
            cout<<"Znaleziono na pozycji: "<<i-1<<"\n";
        }
        else if(j<=m-1){
            if(j!=m-1 && P[j+1]==T[i+j-1]){
                s=1;
            }
            else{
                for(int k=j-1;k>0;k--){
                    if(P[k]==T[i+j-1]){
                        s=j-k;
                    }
                }
            }
        }
        else{
            s=j;
        }
        i+=s;
    }
    return i;
}

void Last(int* tab, string w, int Min)
{
    for (int i = 0; i < sizeof(tab); i++) tab[i] = -1;
    for (int i = 0; i < w.size(); i++)
    {
        tab[((int)w[i]) - Min] = i;
    }
}
 
int main(int argc, const char * argv[]) {
    HashTable1 hashTable(41);
    hashTable.insert("Julia");
    hashTable.insert("Zuzanna");
    hashTable.insert("Zofia");
    hashTable.insert("Lena");
    hashTable.insert("Maja");
    hashTable.insert("Hanna");
    hashTable.insert("Amelia");
    hashTable.insert("Maria");
    hashTable.insert("Aleksandra");
    hashTable.insert("Oliwia");
    hashTable.insert("Natali");
    hashTable.insert("Wiktoria");
    hashTable.insert("Emilia");
    hashTable.insert("Antonina");
    hashTable.insert("Laura");
    hashTable.insert("Pola");
    hashTable.insert("Iga");
    hashTable.insert("Anna");
    hashTable.insert("Liliana");
    hashTable.insert("Antoni");
    hashTable.insert("Jakub");
    hashTable.insert("Jan");
    hashTable.insert("Szymon");
    hashTable.insert("Franciszek");
    hashTable.insert("Filip");
    hashTable.insert("Aleksander");
    hashTable.insert("Mikolaj");
    hashTable.insert("Wijciech");
    hashTable.insert("Kacper");
    hashTable.insert("Adam");
    hashTable.insert("Michael");
    hashTable.insert("Marcel");
    hashTable.insert("Stanislaw");
    hashTable.insert("Wiktor");
    hashTable.insert("Piotr");
    hashTable.insert("Igor");
    hashTable.insert("Leon");
    hashTable.insert("Nikodem");
    hashTable.insert("Mateusz");
    hashTable.insert("Dariusz");
    cout<<hashTable;
    cout<<hashTable.search("Adam")<<"\n";
    string tekst = "534544543587965715450";
    string wzorzec = "3587";
    
    naiwnyWyszaj(tekst,wzorzec,(int)tekst.length(),(int)wzorzec.length());
    bayeraMoora(tekst,wzorzec,(int)tekst.length(),(int)wzorzec.length());
    return 0;
}
