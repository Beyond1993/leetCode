#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:


    string sortString(string str){
        for(int i=1;i<str.length();i++){
            if(str[i-1] > str[i]){
                char tmp = str[i];
                int j = i-1;
                while(str[j]>tmp){
                    str[j+1] = str[j];
                    j--;
                }

                str[j+1] = tmp;
            }
        }

        return str;
    }
    vector<vector<string > > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        multimap<string,string> stringMap;
        for(int i=0;i<strs.size();i++){
            string key = sortString(strs[i]);
            stringMap.insert(multimap<string,string>::value_type(key,strs[i]));
        }

         multimap<string,string>::iterator it,beg,stop ,jt;


        for(it = stringMap.begin();it != stringMap.end();it = ++stop){
                beg = stringMap.lower_bound((*it).first);
                stop = stringMap.upper_bound((*it).first);

                vector<string> tmp;

                for(jt=beg;jt != stop ;jt++){
                   // cout<<(*jt).second<<" ";
                    tmp.push_back((*jt).second);
                }
                sort(tmp.begin(),tmp.end());

                res.push_back(tmp);
                //sort(res.begin(),res.end());

               // cout<<endl;

//                for(int k=0; k<tmp.size(); k++){
//                    cout<<tmp[k]<<" ";
//                }

                //cout<<endl;

                if(stop == stringMap.end()) break;

        }

        //cout<<sort("eat")<<endl;
        return res;
    }
};

int main(){

    string input[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> in(6);
    for(int i=0;i<6;i++){
        in[i] = input[i];
    }

    vector<vector<string > > out;
    Solution s;
    out = s.groupAnagrams(in);
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
