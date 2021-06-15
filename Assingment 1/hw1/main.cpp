/* CH-231-A
  A1.1(Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
using namespace std;

//class type with private and public
class Complex{
    private:
        double real;
        double imaginary;
 public:
        Complex(double real, double imaginary) {
            this->real = real;
            this->imaginary = imaginary;
        }
        int operator==(const Complex o) {
            return ((this->real == o.real) && (this->imaginary == o.imaginary));
        }
        friend ostream& operator<<(ostream &ostr, Complex &com) {
            ostr <<noshowpos<< com.real <<showpos<< com.imaginary << "i";
            return ostr;
        }
};

//template function for all data types
template <class T>
int array_search(T arr[],int size, T element){
   int i;
   for(i=0; i<size; i++){
        if(arr[i]==element){
            cout<<element<<" is in position: "<<i<<endl;
            return i;
        }
   }
   cout<<element<<" not found!"<<endl;
   return -1;
}

//main function with instances for different
//data types
int main()
{
    int arr[]={1,2,3,4,5};
    int num;
    cin>>num;
    array_search(arr,5,num);

    float arr2[]={1.4, 2.5, 3.7, 4.6, 5.5};
    float num2;
    cin>>num2;
    array_search(arr2,5,num2);

    string arr3[]={"a","b","c","d","e"};
    string c;
    cin>>c;
    array_search(arr3,5,c);

    Complex arr4[]={Complex(2,2), Complex(-2,3), Complex(5,6)};
    Complex num4(3,-1);
    array_search(arr4,3,num4);
    
    return 0;
}
