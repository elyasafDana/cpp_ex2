//elidnana@gmail.com
#include <iostream>
#include <math.h>
#include "Mat.h"                    
using namespace pro;
using namespace std;
    
    
    
                
        Mat::Mat(int num){
            size=num;
             mat= new double*[num];

            for(int i=0;i<num;i++){
                mat[i]= new double[num];
            }
        }

        Mat::Mat(const Mat& other) {
            size = other.size;
            mat = new double*[size];  // הקצאת זיכרון חדש
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];  // הקצאת שורות לכל שורה
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = other.mat[i][j];  // העתקת הנתונים
                }
            }
        }

        Mat::~Mat(){
            for (int i = 0; i < size; i++) {
                delete[] mat[i];
            }
            delete[] mat;
            //mat = nullptr;
        }

        double* Mat:: operator[](int num){
            return mat[num];
        }
        double* Mat:: operator[](int num) const{
            return mat[num];
        }


        void Mat::  initialize(double value) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    mat[i][j] = value;
                }
            }
        }

        int Mat::getSize() const {
            return size;
        }

       double Mat:: getVal(int x,int y) const{
            return mat[x][y];
        }
        
        void Mat:: setVal(int x,int y,int value) {
            mat[x][y]=value;
        }
        
        void Mat:: printMat() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    std::cout << mat[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        Mat& Mat::operator=(const Mat& other) {
            if (this == &other)
                return *this;
        
            // שחרור קודם
            for (int i = 0; i < size; ++i) {
                delete[] mat[i];
            }
            delete[] mat;
        
            // העתקה חדשה
            size = other.size;
            mat = new double*[size];
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        
            return *this;
        }

        Mat Mat:: operator+( const Mat other){

            if (other.getSize()!=this->getSize())
            {
                ////
            }
            
            Mat temp= Mat(other.getSize());
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    //cout<<other.getVal(i,j)<<"+"<<mat[i][j]<<endl;
                    temp[i][j]=other[i][j]+mat[i][j];
                    //temp.setVal( i,j,other.getVal(i,j)+mat[i][j]);
                }
                
            }
            
            return temp;
        }

        Mat Mat:: operator-( const Mat other){
            if (other.getSize()!=this->getSize())
            {
                ////
            }
            int size=other.getSize();
            Mat temp(size);
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    temp[i][j]=mat[i][j]-other[i][j];
                    //temp.setVal(i,j,other.getVal(i,j)-this->getVal(i,j));
                }
            }
            return temp;
        
        }

        void Mat:: operator-(){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    mat[i][j]=-mat[i][j];
                    //this->setVal(i,j,-this->getVal(i,j));
                }
            }
        }



        Mat& Mat:: operator*( const Mat other){
            if (other.getSize()!=this->getSize())
            {
                ////
            }
            int size=other.getSize();
            double sum=0;
            Mat temp(size);
            for(int m=0;m<size;m++){
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        sum=sum+other[m][j]*mat[i][j];
                        //sum=sum+other.getVal(m,j)*(this->getVal(i,j));
                    }
                    temp[m][i]=sum;
                    //temp.setVal(m,i,sum);
                    sum=0;
                }
                
            }
            *this=temp;
            return *this;
        
        }

        Mat Mat:: operator*( int num){
            int size=this->getSize();
            double sum=0;
            Mat temp(size);
            for(int j=0;j<size;j++){
                for(int i=0;i<size;i++){
                    temp[i][j]=num*mat[i][j];
                    //temp.setVal(i,j,num*(this->getVal(i,j)));
                }
                
            }
            return temp;
        
        }


        Mat Mat:: operator%( const Mat m ){
            int size=this->getSize();
            Mat temp(size);
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    temp[i][j]=mat[i][j]*m[i][j];
                    //temp.setVal(i,j,(this->getVal(i,j))*(m.getVal(i,j)));
                }
                
            }
            return temp;
        
        }


        Mat Mat:: operator%( int m ){
            int size=this->getSize();
            Mat temp(size);
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){

                    //temp.setVal(i,j,(this->getVal(i,j))%m);
                    temp[i][j]=fmod(mat[i][j],(double)m);
                }
                
            }
            return temp;
        
        }

        Mat Mat:: operator/( int m ){
            int size=this->getSize();
            Mat temp(size);
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    temp[i][j]=mat[i][j]/m;
                    //temp.setVal(i,j,(this->getVal(i,j))/m);
                }
                
            }
            return temp;
        
        }

        Mat Mat:: operator^(int num ){
            //int size=this->getSize();
            Mat temp(size);
            temp.initialize(0);
            for(int i=0;i<size;i++){
                temp[i][i]=1;
                //temp.setVal(i,i,1);
            }
            
            for(int i=0;i<num;i++){
                if(i==0){
                    temp=*this;
                }else{
                    temp=temp*(*this);
                }
            }
            return temp;
        }

        Mat Mat:: operator++(){
            double value=0;
            Mat temp=*this;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    value=mat[i][j];
                    mat[i][j]=++value;
                    //value=this->getVal(i,j);
                    //this->setVal(i,j,++value);
                }
            }
            return *this;
        }

        Mat& Mat:: operator++(int bla){
            double value=0;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    value=mat[i][j];
                    mat[i][j]=++value;

                    //value=this->getVal(i,j);
                    //this->setVal(i,j,++value);
                }
            }
            return *this;
        }


        Mat Mat:: operator--(){
            double value=0;
            Mat temp=*this;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    value=mat[i][j];
                    mat[i][j]=--value;
                    //value=this->getVal(i,j);
                    //this->setVal(i,j,--value);
                }
            }
            return *this;
        }

        Mat& Mat:: operator--(int bla){
            double value=0;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    value=mat[i][j];
                    mat[i][j]=--value;
                    //value=this->getVal(i,j);
                    //this->setVal(i,j,--value);
                }
            }
            return *this;
        }

        Mat& Mat:: operator~(){
            Mat temp(size);
            double value=0;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    value=mat[i][j];
                    temp[i][j]=value;
                    //value=this->getVal(i,j);
                    //temp.setVal(j,i,value);
                }
            }
            *this=temp;
            return *this;
        }

        double sum(const Mat m){
            double sum=0;
            int size=m.getSize();
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    sum=sum+m[i][j];
                }
            }
            return sum;

        }


        bool Mat:: operator==(const Mat other){
            return sum(other)== sum(*this) ;
            }

            bool Mat:: operator!=(const Mat other){
                
                return !(sum(other)== sum(*this));
                
                }


                bool Mat:: operator<(const Mat other){
                    
                    return (sum(*this)< sum(other));
                    
                    }

                    bool Mat:: operator>(const Mat other){
                       
                        return (sum(*this)> sum(other));
                        
                        }



                        bool Mat:: operator<=(const Mat other){
                            double mySum=0;
                            double otherSum=0;
                
                            for(int i=0;i<size;i++){
                                for(int j=0;j<size;j++){
                                    mySum=mySum+mat[i][j];
                                    otherSum=otherSum+other[i][j];
                                }
                            }
                            return !(sum(*this)>sum(other));
                            
                            }

                            bool Mat:: operator>=(const Mat other){
                                double mySum=0;
                                double otherSum=0;
                    
                                for(int i=0;i<size;i++){
                                    for(int j=0;j<size;j++){
                                        mySum=mySum+mat[i][j];
                                        otherSum=otherSum+other[i][j];
                                    }
                                }
                                return !(sum(*this)< sum(other));
                            
                                }


                                Mat& Mat:: operator+=(const Mat other){
                                    *this=*this+other;
                                    return *this;
                                
                                    }

                                Mat& Mat:: operator-=(const Mat& other){
                                        *this=*this-other;
                                        return *this;
                                    
                                    }

                                Mat& Mat:: operator*=(const Mat other){
                                        *this=*this*other;
                                        return *this;
                                    
                                   }
                                 Mat& Mat:: operator*=(int num){
                                    *this=*this*num;
                                    return *this;
                                
                               }

                               Mat& Mat:: operator%=(const Mat other){
                                *this=*this%other;
                                return *this;
                            
                           }
                           Mat& Mat:: operator%=(int num){
                            *this=*this%num;
                            return *this;
                        
                       }

                       Mat& Mat:: operator/=(int num){
                        *this=*this/num;
                        return *this;
                    
                   }

                   std::ostream& pro::operator<<(std::ostream& os,const Mat& mat){
                    int size=mat.getSize();
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            os << mat[i][j] << " ";
                        }
                        os << std::endl;
                    }
                    return os;

                   }

                   Mat pro:: operator*( int num, const Mat m ){
                    int size=m.getSize();
                    double sum=0;
                    Mat temp(size);
                    for(int j=0;j<size;j++){
                        for(int i=0;i<size;i++){
                            temp[i][j]=num*m[i][j];
                            //temp.setVal(i,j,num*(m.getVal(i,j)));
                        }
                        
                    }
                    return temp;
                
                }

            
                                //mat2+=mat1, =-, =*, =/, =%

        

        
        
        




/*
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
    */