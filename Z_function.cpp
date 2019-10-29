#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
#include <exception>
#include <sstream>

using namespace std;



vector<int> Z_function(const string& str){
    vector<int> zf(0,str.size());
    int Left = 0 ,Right = 0;
    for(int i = 1; i < str.size();++i){
        if(i > Right){
            zf[i] = 0;
        }
        else{
            zf[i] = max(0,min(zf[i - Left],Right - i + 1 ));
        }
        while( i + zf[i] < str.size() && str[i + zf[i]] == str[zf[i]]){
            ++zf[i];
        }
        if(i + zf[i] - 1 > Right ){
            Left = i;
            Right = i + zf[i] - 1;
        }
    }
    return zf;
}


template<typename Q>
ostream& operator<<(ostream& os,const vector<Q>& q){
    os << "{";
    bool first = true;
    for(const auto& element:q){
        if(!first){
            os << ", ";
        }
        first = false;
        os << element;
    }
    return os << "}";
}

template<class Q,class R>
void AssertEqual(const Q& q,const R& r, const string& hint){
     
    if(q != r){
        ostringstream os;
        os <<"Assertion Failed : " << q <<"!= "<< r << " Hint : " << hint;
        throw runtime_error(os.str());
    }
}



void TestZfunction(){
    {
        const string& word = "qw";
        const vector<int> expected = {0};
        AssertEqual(Z_function(word),expected,"Test with a and b");
    }
}

class TestRunner{
public:
    template<class TestFunc>
    void RunTest(TestFunc func,const string& test_name){
        try{
            func();
            cerr << test_name << "OK " << endl;
        }
        catch(runtime_error& ex){
            ++fail_count;
            cerr << test_name << " failed : " << ex.what() << endl;
            
        }
    }
    ~TestRunner(){
        if(fail_count != 0){
            cerr << fail_count << "tests failed. The program terminated";
            exit(1);
        }
    }
    
private:
    int fail_count = 0;
};

void TestAll(){
    TestRunner tr;
    tr.RunTest(TestZfunction,"TestZfunction");
}


int main()
{
    TestAll();

    return 0;
}
