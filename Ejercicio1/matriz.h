//
// Created by rodrigo.cespedes on 7/06/2019.
//


#include <vector>
#include <iomanip>
using namespace std;

template <typename T>
class matriz {
public:
    vector<vector<T>> matrix;
    int x;
    int y;

   void print(){
        for(int i=0; i<x;i++) {
            for (int j = 0; j < y; j++)
                cout <<setw(5)<< matrix[i][j];
            cout<<endl;
        }
       cout<<endl;
    }
    matriz() = default;

    matriz(int x_, int y_) : matrix{x_},x{x_},y{y_} {
        for (auto &fila : matrix) {
            fila.resize(y);
        }
    }

    matriz(int x_, int y_, const T &value) :
            matrix{x_},
            x{x_},
            y{y_} {
        for (auto &fila : matrix) {
            fila.resize(y, value);
        }
    }

    bool verify(const matriz<T> m1){
        if(x== m1.x)
            if(y==m1.y) {
                return true;
            }
        else{
            return false;
        }
    }

    void change(int x, int y, const T &value) {
        matrix[x][y] = value;
    }


    int sizex() { return x; };

    int sizey() { return y; };


    vector<T>& operator[](size_t fila)
    {
        return matrix[fila];
    }

    const std::vector<T>& operator[](size_t fila) const
    {
        return matrix[fila];
    }


    void operator+=(const matriz<T>& m1) {

            for(int i=0;i<x;i++)
                for(int j=0;j<y;j++)
                    this->matrix[i][j]+=m1[i][j];

    }


    matriz<T> operator+(const matriz<T>& m1){
        matriz<T> aux(x,y,0);
        if(x== m1.x)
            if(y==m1.y) {
                for (int i = 0; i < x; i++)
                    for (int j = 0; j < y; j++)
                        aux[i][j] = this->matrix[i][j] + m1[i][j];
            }

        else{
            cout<<"ERROR, no se puede sumar"<<endl;
        }



        return aux;
    }



};
