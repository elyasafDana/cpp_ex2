//elidnana@gmail.com
#ifndef SQUAREMAT_H
#define SQUAREMAT_H

#include <iostream>

namespace pro {
    class Mat {
    private:
        int size;
        double** mat;

    public:
    
        Mat(int size);
        ~Mat();

        double*  operator[](int num);
        double*  operator[](int num) const;
        
        void initialize(double num);
        void printMat();
        int getSize() const;
        double getVal(int x,int y) const ;
        void setVal(int x,int y,int value); 
        Mat& operator=(const Mat& other);
        Mat  operator+(const Mat other);
        Mat(const Mat& other) ;
        Mat operator-(const Mat other);
        void  operator-();
        Mat& operator*( const Mat other);
        Mat operator*( int num);
        Mat operator%( const Mat m );
        Mat  operator%( int m );
        Mat  operator/( int m );
        Mat  operator^(int num );
        Mat  operator++();
        Mat&  operator++(int bla);
        Mat  operator--();
        Mat&  operator--(int bla);
        Mat&  operator~();
        bool operator==(const Mat other);
        bool  operator!=(const Mat other);
        bool  operator<(const Mat other);
        bool  operator>(const Mat other);
        bool  operator>=(const Mat other);
        bool  operator<=(const Mat other);
        Mat&  operator+=(const Mat other);
        Mat& operator-=(const Mat& other);
        Mat&  operator*=(const Mat other);
        Mat&  operator*=(int num);
        Mat&  operator%=(const Mat other);
        Mat&  operator%=(int num);
        Mat&  operator/=(int num);
        //friend  std::ostream& operator<<(std::ostream& os,const Mat& mat);


         
    };
    std::ostream& operator<<(std::ostream& os,const Mat& mat);
    Mat  operator*( int num, const Mat m );
        /*
    Mat  operator*( int num, const Mat m ){
        int size=m.getSize();
        int sum=0;
        Mat temp(size);
        for(int j=0;j<size;j++){
            for(int i=0;i<size;i++){
                
                temp.setVal(i,j,num*(m.getVal(i,j)));
            }
            
        }
        return temp;
    
    }*/
}

#endif // SQUAREMAT_H
