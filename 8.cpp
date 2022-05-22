#include <iostream> 
#include <stack>

using namespace std;

int main() {
    int n;
    int x;

    stack<int> s; // Объявление структуры стек

    cout << "Enter n : " ;
    cin >> n; // Вводим n с клавиатуры
    
    for (int i = 0; i < n; i++) {
        
        cout << "Enter x : ";
        cin >> x; // Вводим x с клавиатуры
        
        if (i == 0) {
            s.push(x); 
        }
        if (i > 0) {
            if (x > s.top()) {
                s.push(x); 
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}