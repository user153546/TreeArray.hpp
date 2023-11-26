#include"TreeArray.hpp"
int main(){
    TreeArray<int> t;
    t.push_back(1);
    t.size();
    t.query(0);
    t.query(0, 0);
    t[0];
    t.show();
    t.show(0);
    t.updata(0, 1);
    t.clear();
}