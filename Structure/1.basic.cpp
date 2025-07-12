#include<iostream>
using namespace std;

struct adrs{
    string city;
    int zip, house_num;

    adrs(){ // default constructor
        city = "N/A";
        house_num = -1;
        zip = -1;
    }

    adrs(string _city, int hnum, int zip_code){ //paramaterised constructor
        city = _city;
        house_num = hnum;
        zip = zip_code;
    }

    void print(){
        cout << "Addresss : ";
        cout << "City: " << city << ", House number : " << house_num << ", Zip Code : " << zip << '\n';
    }
};

struct student_info{
    string name;
    int age;
    float cg;
    adrs Address;

    void print(){
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "cg: " << cg << endl;
    }
};


int main(){
    int n, zzip, hhouse_num;  cin >> n;
    string ccity;
    student_info data[5];

    for(int i=0;i<n;i++){
        cin >> data[i].name >> data[i].age >> data[i].cg;
        
        // cin >> data[i].Address.city;
        // cin >> data[i].Address.house_num;
        // cin >> data[i].Address.zip;

        cin >> ccity >> hhouse_num >> zzip;
        data[i].Address = adrs(ccity, hhouse_num, zzip);
    }


    int mx_cg = -1.0, mn_cg = 5.0, index_mx = -1, index_mn = -1;

    for(int i=0;i<n;i++){

        if(data[i].cg > mx_cg){
            index_mx = i;
            mx_cg = data[i].cg;
        }
        
        if(data[i].cg < mn_cg){
            index_mn = i;
            mn_cg = data[i].cg;
        }
    }

    cout << "topr info : \n";
    data[index_mx].print();
    data[index_mx].Address.print();

    cout << endl;

    cout << "rpot info : \n";
    data[index_mn].print();
    data[index_mn].Address.print();

    return 0;
}