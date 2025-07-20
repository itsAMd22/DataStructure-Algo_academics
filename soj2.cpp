#include<iostream>
using namespace std;


struct amd{
    // string name;
    // long long id;
    // float cgpa;
    // int iq;
    string fruit_name;
    int price_per_kg;
    float fruits_weight;
}a[10];


int main(){
    // // 1. factorial
    // long long n, ans = 1;    
    // cin >> n;
    // while(n > 0){
    //     ans *= n--;
    // }
    // cout << ans << endl;    
    
    // // 2. sum of array elements
    // int n;  cin >> n;
    // int a[n], sum = 0;
    // for(int i=0;i<n;i++){
    //     cin >> a[i];
    //     sum += a[i];
    // }
    // cout << sum;

    // //3. insertion
    // int n, index, value;  cin >> n;
    // int a[n+1];
    // for(int i=0;i<n;i++)    cin >> a[i];
    // cin >> index >> value;
    // for(int i=n;i>index;i--)   a[i] = a[i-1];
    // a[index] = value;
    // for(int i=0;i<=n;i++)   cout << a[i] <<  " ";

    // //4. deletion
    // int n, index;  cin >> n;
    // int a[n];
    // for(int i=0;i<n;i++)    cin >> a[i];
    // cin >> index;
    // for(int i=index;i<n-1;i++)   a[i] = a[i+1];
    // for(int i=0;i<n-1;i++)   cout << a[i] <<  " ";

    // //5. Bubble + bin
    // int n;  cin >> n;
    // int a[n];
    // for(int i=0;i<n;i++)    cin >> a[i];
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-1-i;j++){
    //         if(a[j] > a[j+1])   swap(a[j], a[j+1]);
    //     }
    // }
    // for(int i=0;i<n;i++)    cout << a[i] << " ";    cout << endl;
    // int target; cin >> target;
    // int lo = 0, hi = n, mid, found = 0;
    // while(lo <= hi){
    //     mid = ((lo+hi)>>1);
    //     if(a[mid] == target){
    //         found = 1;
    //         break;
    //     }else if(a[mid] > target)   hi = mid - 1;
    //     else    lo = mid + 1;
    // }

    // cout << (found == 1 ?  "found" : "Not found");


    // //6. identity matrix checking
    // int r,c;    cin >> r >> c;
    // int a[r][c], amd = 1;
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cin >> a[i][j];
    //     }
    // }
    // if(r != c)  amd = 0;
    // else{
    //     for(int i=0;i<r;i++){
    //         for(int j=0;j<c;j++){
    //             if((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0)){
    //                 amd = 0;
    //                 break;
    //             }
    //         }
    //         if(amd == 0)    break;
    //     }
    // }
    // cout << (amd == 1 ? "Yes"  : "No");


    // //7. transpose
    // int r,c;    cin >> r >> c;
    // int a[r][c], amd = 1;
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cin >> a[i][j];
    //     }
    // }
    // for(int i=0;i<c;i++){
    //     for(int j=0;j<r;j++)    cout << a[j][i] << " "; cout << endl;
    // }
    

    // //8. summation of each rows and columns;

    // int r,c;    cin >> r >> c;
    // int a[r][c], amd = 1, rsum, csum;
    // for(int i=0;i<r;i++){
    //     rsum = 0;
    //     for(int j=0;j<c;j++){
    //         cin >> a[i][j];
    //         rsum += a[i][j];
    //     }
    //     cout << "row " << i << " -> " << rsum << endl;
    // }


    // for(int i=0;i<c;i++){
    //     csum = 0;
    //     for(int j=0;j<r;j++)    csum += a[j][i];
    //     cout << "column " << i << " -> " << csum << endl;
    // }
    
    // //9. multiplication of matrix

    // int r1, r2, c1, c2;    
    // cin >> r1 >> c1;
    // int a[r1][c1];
    // for(int i=0;i<r1;i++){
    //     for(int j=0;j<c1;j++)   cin >> a[i][j];
    // }
    // cin >> r2 >> c2;
    // int b[r2][c2];
    // for(int i=0;i<r2;i++){
    //     for(int j=0;j<c2;j++)   cin >> b[i][j];
    // }

    // if(c1 != r2)    cout << "operation not possible\n";
    // else{
    //     int c[r1][c2];
    //     for(int i=0;i<r1;i++){
    //         for(int j=0;j<c2;j++){
    //             c[i][j] = 0;
    //             for(int k=0;k<c1;k++)   c[i][j] += (a[i][k] * b[k][j]);
    //         }
    //     }

    //     for(int i=0;i<r1;i++){
    //         for(int j=0;j<c2;j++){
    //             cout << c[i][j] << " ";
    //         }cout << endl;
    //     }
    // }
    
    // //10. palindromity check
    // int flag = 0;
    // string a,b="";
    // cin >> a;
    // for(int i=a.size()-1;i>=0;i--)  b += a[i];
    // for(int i=0;i<a.size();i++){
    //     if(tolower(a[i]) != tolower(b[i])){
    //         flag = 1;
    //         break;
    //     }
    // }


    // cout << (flag == 0 ? "Yes" : "No");

    // // 11. print all the vowerls, consonants and special characters seperately

    // string s;   getline(cin, s);
    // int sz = s.size(), flag = 0;
    // char c;
    // cout << "Vowels : ";
    // for(int i=0;i<sz;i++){
    //     if(!isalpha(s[i]))  continue;
    //     c = tolower(s[i]);
    //     if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    //         cout << s[i] << ", ";
    //         flag = 1;
    //     }
    // }
    // cout << (flag == 0 ? "None\n" : "\n");

    // flag = 0;
    // cout << "Consonants : ";
    // for(int i=0;i<sz;i++){
    //     if(!isalpha(s[i]))  continue;
    //     c = tolower(s[i]);
    //     if(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')){
    //         cout << s[i] << ", ";
    //         flag = 1;
    //     }
    // }
    // cout << (flag == 0 ? "None\n" : "\n");

    // flag = 0;
    // cout << "Special Characters : ";
    // for(int i=0;i<sz;i++){
    //     if(isalpha(s[i]) || isdigit(s[i]) || s[i] == ' ')  continue;
    //     cout << s[i] << ", ";
    //     flag = 1;
    // }
    // cout << (flag == 0 ? "None\n" : "\n");


    // //12. @d string of 5 words, print vowels of each

    // string a[5];
    // char c;
    // int flag;
    // for(int i=0;i<5;i++)    cin >> a[i];
    // for(int i=0;i<5;i++){
    //     cout << a[i] << ": ";
    //     flag = 0;
    //     for(int j=0;j<a[i].size();j++){
    //         c = tolower(a[i][j]);
    //         if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'){
    //             cout << a[i][j] << " ";
    //             flag = 1;
    //         }
    //     }
    //     cout << (flag == 0 ? "None\n" : "\n");
    // }

    // //13. printing an array using pointer
    // int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // int *ptr = &a[0];
    // for(int i=0;i<10;i++){
    //     cout << *(ptr + i) << " ";
    // }


    // for(int i=0;i<10;i++){
    //     cin >> a[i].id >> a[i].name >> a[i].cgpa >> a[i].iq;
    // }
    // for(int i=0;i<10;i++){
    //     cout << "Student " << i + 1 << ":\n";
    //     cout << "ID: " << a[i].id << endl;
    //     cout << "Name: " << a[i].name << endl;
    //     cout << "CGPA: " << a[i].cgpa << endl;
    //     cout << "IQ: " << a[i].iq << endl << endl;
    // }


    for(int i=0;i<10;i++){
        cin >> a[i].fruit_name >> a[i].price_per_kg >> a[i].fruits_weight;
    }

    int mx_index, mn_index;
    float mx = 0, mn = 100000000.0, cost;
    for(int i=0;i<10;i++){
        cost = a[i].fruits_weight * a[i].price_per_kg;
        if(cost > mx){
            mx = cost;
            mx_index = i;
        }
        if(cost < mn){
            mn = cost;
            mn_index = i;
        }
    }

    cout << "Maximum Cost: " << a[mx_index].fruit_name << endl;
    cout << "Minimum Cost: " << a[mn_index].fruit_name << endl;
    return 0;



} 
