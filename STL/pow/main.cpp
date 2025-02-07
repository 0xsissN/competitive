#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double n; cin >> n;
    double e = n - 1;
    if(n == 1){
        cout << 1 << endl;
    }else {
        cout << 1 + pow(3, e) << endl ;
    }
    return 0;
}
