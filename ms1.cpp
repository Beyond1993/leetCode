#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main(){
    int tests;
    cin>>tests;
    int * n =new int[tests];
    int * p =new int[tests];
    int * w =new int[tests];
    int * h =new int[tests];
    int **a =new int*[tests];
    for(int k=0;k<tests;k++){



        cin>>n[k];
        a[k] = new int[n[k]];

        cin>>p[k];
        cin>>w[k];
        cin>>h[k];
        //cout<<n<<" "<<p<<" "<<w<<" "<<h<<endl;
        for(int i=0;i<n[k];i++){
            cin>>a[k][i];
        }
    }

    double * Size =new double[tests];
    double * all = new double[tests];
    double * numWords = new double[tests];
    for(int k=0;k<tests;k++){

        all[k] = w[k] * h[k] * p[k];
        numWords[k] = 0;
        for(int j=0;j<n[k];j++){
            numWords[k] += a[k][j];
        }

        Size[k] = floor(sqrt(all[k] / numWords[k]));

    }

    for(int k=0;k<tests;k++){
        cout<<(int)Size[k]<<endl;
    }
    return 0;
}
