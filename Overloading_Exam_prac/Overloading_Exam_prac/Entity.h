template <typename T>
class entity
{
public:
    T size;
    T num;
   
    entity(T s) :size(s) {}
    //entity(T a,T b) : num(a > b){}
    entity<T> operator++(){return entity(++this->size);}
    entity<T> operator--(){return entity(--this->size);}
    //entity<T> operator>(T a, T b){return entity(a > b);}
     //bool operator<(const entity& a){return entity(this->num < a.num);}
   // bool operator<(const T LResult, const T RResult)
   //  {
   //      return LResult->num>RResult->num;
   //  }
    

};



