/*
 *  Essaies d'implémentations d'itérateur alla STL
 *  voir:
 *    http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
 *    https://openclassrooms.com/courses/programmez-avec-le-langage-c/iterateurs-et-foncteurs
 *    http://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
 */

#include <iostream>
using std::cout;
using std::endl;

class mIter;

class mContainer{
public:

    mContainer(){
          for(int i=0;i<10;i++){
              o1[i]=i;
              o2[i]=static_cast<double>(i+10)*2.18765875;
              o3[i]=static_cast<char>(i+97);
          }
    };

    typedef mIter iterator;
    friend class mIter;

    mIter begin();
    //iterator begin(){ iterator it(this); return it.begin(); }
    iterator end();




//private:
    int o1[10];
    double o2[10];
    char o3[10];
};


class mIter{
private:
    mContainer &_container;
    int _position;
public:
    friend class mIter;
    mIter(mContainer&contain)
        :_container(contain),_position(0){
    }

    mIter begin(){_position=0; return *this;}
    mIter end(){_position=10; return *this;}

    int first(){return _container.o1[_position];}
    double second(){return _container.o2[_position];}
    char third(){return _container.o3[_position];}

    mIter &operator ++(){
        ++_position;
        return *this;
    }

    mIter operator++ (int){
        mIter clone(*this);
        ++_position;
        return clone;
    }

    bool operator !=(const mIter &other)const{
        return this->_position!=other._position;
    }
};

mIter mContainer::begin(){ mIter it(*this); return it.begin(); }
mContainer::iterator mContainer::end(){ mContainer::iterator it(*this); return it.end(); }

int main(){
    mContainer container;

 //   std::cout<<container.o1[0];

       cout<< "Create an iterator"<<endl<<endl;
       mIter iter(container);

       cout<< "begin()"<<endl;
       mIter it=iter.begin();
       cout<<"first: "<<it.first();
       cout<<"  second: "<<it.second();
       cout<<"  third: "<<it.third();
       cout<<endl<<endl;


       cout<< "end() ... out-of-bound"<<endl;
       mIter it1=iter.end();
       cout<<"first: "<<it1.first();
       cout<<"  second: "<<it1.second();
       cout<<"  third: "<<it1.third();
       cout<<endl<<endl;

       cout<< "operator ++()"<<endl;
       mIter it2=iter.begin();
       ++it2;
       cout<<"first: "<<it2.first();
       cout<<"  second: "<<it2.second();
       cout<<"  third: "<<it2.third();
       cout<<endl<<endl;

       cout<< "operator ++(int)"<<endl;
       mIter it3=iter.begin();
       mIter it4=it3++;

       cout<<"first: "<<it4.first();
       cout<<"  second: "<<it4.second();
       cout<<"  third: "<<it4.third();
       cout<<endl;

       cout<<"first: "<<it3.first();
       cout<<"  second: "<<it3.second();
       cout<<"  third: "<<it3.third();
       cout<<endl<<endl;




       cout<< "for"<<endl;

        for(mIter i=iter.begin();i!=iter.end();i++){
            cout<<"first: "<<i.first();
            cout<<"  second: "<<i.second();
            cout<<"  third: "<<i.third();
            cout<<endl;
        }
        cout<<endl<<endl;


        cout<< "for using container's begin/end"<<endl;

         for(mIter i=container.begin();i!=container.end();i++){
             cout<<"first: "<<i.first();
             cout<<"  second: "<<i.second();
             cout<<"  third: "<<i.third();
             cout<<endl;
         }
         cout<<endl<<endl;

}
