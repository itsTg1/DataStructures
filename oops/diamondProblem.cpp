#include <bits/stdc++.h>
using namespace std;
class a{
    public:
    int age;
    void calcD();
};
void a::calcD(){
    cout<<"juju"<<endl;
}
class b:public a{

};
class c:public a{

};
class d:public b,public c{
    friend ostream& operator <<(ostream& out,d obj);
};
ostream& operator <<(ostream& out,d obj){
        out<<obj.b::age<<endl;
        return out;
}
int main() {
    d obj1;
    cout<<obj1.b::age<<endl;
    obj1.b::calcD();
    cout<<obj1<<endl;
}
