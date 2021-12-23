#include <bits/stdc++.h>
using namespace std;

int n;
const int max_sz = 1e5;
double arr[max_sz][3];

void translate(double a, double b){
    for(int i = 0; i < n; i++){
        arr[i][0] += a;
        arr[i][1] += b;
    }
}

void rotate(double degree){
    double newArray[n][3];
    memset(newArray, 0, sizeof(newArray));
    double matrix[3][3];
    double radiant = M_PI / 180 * degree;

    matrix[0][0] = cos(radiant), matrix[0][1] = sin(radiant), matrix[0][2] = 0;
    matrix[1][0] = -sin(radiant), matrix[1][1] = cos(radiant), matrix[1][2] = 0;
    matrix[2][0] = 0, matrix[2][1] = 0, matrix[2][2] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newArray[i][j] += arr[i][k] * matrix[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = newArray[i][j];
        }
    }
}

void scale(double a, double b){
    for(int i = 0; i < n; i++){
        arr[i][0] *= a;
        arr[i][1] *= b;
    }
}

int main() {
    freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    cout << "Enter the X and Y coordinates of each vertix" << endl;
    for(int i = 0; i < n; i++){
        double x, y; cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = 1;
    }
    cout << "1- Translation" << endl;
    cout << "2- Scaling" << endl;
    cout << "3- Rotation" << endl;
    double choice; cin >> choice;
    while(true){
        if(choice == 1){
            cout << "Please enter the values that you want to translate by: ";
            double a, b; cin >> a >> b;
            translate(a, b);
            break;
        }else if(choice == 2){
            cout << "Please enter the values that you want to scale by: ";
            double a, b; cin >> a >> b;
            scale(a, b);
            break;
        }else if(choice == 3){
            cout << "Please enter the degree you want to rotate by in the anticlockwise direction: ";
            double a; cin >> a;
            rotate(a);
            break;
        }else{
            cout << "Please enter a valid choice" << endl;
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}