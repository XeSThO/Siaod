#include <vector>
#include <iostream>
#include <locale.h>
#include <algorithm>
using namespace std;
int main(){   
    setlocale(LC_ALL,"Russian");
    vector <char> L1 (0,0);
    vector <char> L2 (0,0);
    vector <char> L (0,0);
    char s1 = ' '   , s2 = ' ' ;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    for (unsigned int c=0; c<10; ++c){
        cout << "Введите символы и цифры для списка L1, для завершения ввода используйте знак '.' " << ' ' << endl;
        while (cin >> s1){
            L1.push_back(s1);
            if (s1 == '.'){
                L1.pop_back();
                break;
            }  
        }
        cout << endl;
        cout << "Список первый:" << ',' << endl;
            for (unsigned int i=0; i < L1.size(); ++i){
                cout << L1 [i] << ' ';
            } 
            cout << endl << endl;
        cout << "Введите символы и цифры для списка L2, для завершения ввода используйте знак '.' "<< endl;
        while (cin >> s2){
            L2.push_back(s2);
            if (s2 == '.'){
                L2.pop_back();
                break;
            }  
        }
        cout << endl;
        cout << "Список второй:" << ',' << endl;
        for (unsigned int i=0; i < L2.size(); ++i){
            cout << L2 [i] << ' ';
        } 
        cout << endl;
        for (unsigned int i = 0; i < L1.size(); ++i){
            for (unsigned int j = 0; j < L2.size(); ++j){
                if (L2[j]==L1[i]){
                    L.push_back(L1[i]);
                }  
            } 
        } 
        cout << endl;
        sort(L.begin(), L.end());
            vector<char>::iterator t;
                t=unique (L.begin(), L.end ());
                    L.resize(t - L.begin());
        if (L.size() > 0){
            cout << "Элементы, сожержащиеся в обоих списках L:"<< endl;
            for (unsigned int i=0; i < L.size(); ++i){
                cout << L [i] << ' ';
            } 
            cout << endl;
        }  
        else    
            cout << "Совпадающие элементы отсутствуют." << ' ' << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl << endl;
        L1.clear();
        L2.clear();
        L.clear();
        return 0;
    }
}