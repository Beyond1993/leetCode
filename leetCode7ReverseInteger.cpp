#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>>
using namespace std;

class Solution {
public:
    int reverse(int x) {
				int result  = 0;
		if(x>=0){
			char  str[25];
			//itoa(x,str,10);
			sprintf(str,"%d",x);
			string test ,temp ;
			test.append(str);
			for(int i=0;i<test.length();i++){
				temp.push_back(test[test.length() -1-i]);
			}
				const char * c = temp.c_str();
				result = myAtoi(c);

	    } else{
			int postive = 0 - x;
			char  str[25];
			//itoa(postive,str,10);
			sprintf(str,"%d",postive);
			string test ,temp ;
			test.append(str);
			for(int i=0;i<test.length();i++){
				temp.push_back(test[test.length() -1-i]);
			}
			//	const char * c = temp.c_str();
				result = myAtoi(temp);
				result = 0 -result;
		  }
	if(result > (pow(2,31) -1) || result < -pow(2,31) ){
		result = 0;
	}
	return result;
	}
	
	int myAtoi(string str) {

        long long result = 0;//define long long first!!
        int n = str.length();
        int times  = n ;
        if(str[0]=='-') times = n - 1;
        for(int i=0;i<times;i++){
            //cout<<str[i]<<endl;
            result = result + ( str[n-1 -i] - 48 )* pow(10,i);
        }
        if(str[0] == '-') result = 0 - result;

        if(result > (pow(2,31) -1) || result < -pow(2,31) ){
            result = 0;
        }
        return (int)result;
    }
};


int main(){

    while(true){
	int a ;
	cin>>a;
	//cout<<-pow(2,31);
	Solution s;
	cout<<s.reverse(a)<<endl;
	}
	char pause;
	cin>>pause;
	return 0;
}
