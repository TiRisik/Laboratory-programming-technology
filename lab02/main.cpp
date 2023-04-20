#include <iostream>
#include <vector>
using namespace std;

class MathVector{

private:

    vector<int> math_vector;

public:

    MathVector(vector<int> a){
        math_vector = a;
    }

    void PrintVector(){
        for (int i = 0; i < math_vector.size(); i++)
            cout<<math_vector[i]<<' ';
        cout<<' '<<endl;
    }

    MathVector operator += (MathVector& r) {
        MathVector res = r;
        for (int i = 0; i != math_vector.size(); i++)
            math_vector[i] += res.math_vector[i];
        return math_vector;
    }

    MathVector operator -= (MathVector& r) {
        MathVector res = r;
        int size_vector;
        if (res.math_vector.size() < math_vector.size()) size_vector = res.math_vector.size();
        else size_vector = math_vector.size();
        for (int i = 0; i != size_vector; i++)
            math_vector[i] -= res.math_vector[i];
        return math_vector;
    }

    int operator * (MathVector& r) {
        MathVector res = r;
        int scalar = 0;
        int size_vector;
        if (res.math_vector.size() < math_vector.size()) size_vector = res.math_vector.size();
        else size_vector = math_vector.size();
        for (int i = 0; i != size_vector; i++)
            scalar += math_vector[i] * res.math_vector[i];
        return scalar;
    }

    MathVector operator *= (int a) {
        for (int i = 0; i != math_vector.size(); i++)
            math_vector[i] *= a;
        return math_vector;
    }

    MathVector operator / (int a) {
        for (int i = 0; i != math_vector.size(); i++)
            math_vector[i] = math_vector[i] / a;
        return math_vector;
    }

};

int main(){
    vector<int> ivector = {1, 2, 3};
    vector<int> ivector1 = {5, 10, 15, 20};
    MathVector m(ivector);
    MathVector m1(ivector1);
    cout<<"vector 1: ";
    m.PrintVector();
    cout<<"vector 2: ";
    m1.PrintVector();
    m *= 4;
    cout<<"vector 1 * 4: ";
    m.PrintVector();
    int scalar = m * m1;
    cout<<"vector 1 * vector 2: "<<scalar<<endl;
    m1 -= m;
    cout<<"vector 2 - vector 1: ";
    m1.PrintVector();
    m += m1;
    cout<<"vector 1 + vector 2: ";
    m.PrintVector();
    m / 4;
    cout<<"vector 1 / 4: ";
    m.PrintVector();
    return 0;
}
