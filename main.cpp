//elidnana@gmail.com
#include"Mat.h"
int main(){


    using namespace pro;
    using namespace std;
    Mat m1=Mat(3);
    Mat m2=Mat(3);
    Mat m3=Mat(3);

    

    m1.initialize(2);
    m2.initialize(2);
    m2=3*m1;
    cout<<m1<<m2;


    
    


   // m2=m2^3;
    //m2.printMat();
    m2.setVal(0,1,1);
    m2.setVal(1,0,1);
    m2.setVal(2,1,1);
    
    //m3.printMat();

    
    

    return 0;
}