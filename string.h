#include <cstddef>
#include <iostream>
class string{
private:
    char* begin;
    size_t length;
public:
    //constructor
    string():begin(nullptr),length(0){};
    string(const string & obj):length(obj.length){
        begin = new char[length+1];
        for (int i = 0; i < length; i++)
        {
            begin[i] = obj.begin[i];
        }
        begin[length] = '\0';
    };
    string(const char * obj){
        int i = 0;
        for (;obj[i] != '\0';i++){
        }
        length = i;
        begin = new char[length+1];
        for (int i = 0; i < length; i++){
            *(begin+i) = *(obj + i);
        }
    };
    string(const size_t leng,const char ch):length(leng){
        begin = new char[length+1];
        for (int i = 0; i < length; i++)
        {
            begin[i] = ch;
        };
        begin[length] = '\0';
    };
    //deconstructor
    ~string(){
        delete[] begin;
        std::cout << "deconstructed successfully" << std::endl;
    };
    int getlength(){
        return length;
    };
    bool isEmpty(){
        return !length;
    };
    const char* c_str(){
        return begin;
    };
    friend std::ostream& operator<< (std::ostream& ostr,string& str){
        ostr << str.c_str();
        return ostr;
    };
    //friend std::istream& operator>> (std::istream& istr,string& str){}
    friend bool operator== (string& str1,string& str2){
        if(str1.begin == str2.begin){
            return true;
        }else if(str1.length != str2.length){
            return false;
        }else{
            return str1.isSame(str2,str1.length);
        }
    };
    friend bool operator!= (string& str1,string& str2){
        if(str1.begin == str2.begin){
            return false;
        }else if(str1.length != str2.length){
            return true;
        }else{
            return !str1.isSame(str2,str1.length);
        }
    };
    bool operator< (string& str2){
        return length < str2.length;
    };
    bool operator<= (string& str2){
        return length <= str2.length;
    };
    bool operator> (string& str2){
        return length > str2.length;
    };
    bool operator>= (string& str2){
        return length >= str2.length;
    };
    char& operator[] (int index){
        return begin[index];
    };
    bool isSame(const string& str2,int length){
        for(int i = 0;i < length;i++){
            if(begin[i] != str2.begin[i]){
                return false;
            }
        }
        return true;
    };
    string& substr(int posi,int len){
        char * temp = new char[len+1];
        if(posi+len >= length){
            return *(new string());
        }else{
            for (int i = posi; i <= posi+len-1; i++){
                temp[i-posi] = begin[i];
            }
            temp[len] = '\0';
            return *(new string(temp));
        }
    };
    string& append(char ch){
        char * temp = new char[length+2];
        for(int i = 0;i < length;i++){
            temp[i] = begin[i];
        };
        temp[length] = ch;
        temp[length + 1] = '\0';
        return *(new string(temp));
    };
    string& insert(int posi,const string &str){
        int templ = str.length + length;
        char * temp = new char[templ+1];
        bool isAhead = false;
        for (int i = 0; i < templ; i++)
        {
            if(i == posi){
                temp[posi] = begin[posi];
                for(int j = posi+1;j <= posi + str.length;j++){
                    temp[j] = (str.begin[j-posi-1]);
                }
                i += posi+str.length;
                isAhead = !isAhead;
            }else{
                if(isAhead){
                    temp[i] = begin[(i-(str.length))];
                }else{
                    temp[i] = begin[i];
                }
            }
        }
        temp[templ] = '\0';
        return *(new string(temp));
    };
    string& erase(int posi,int len){
        bool isAhead = false;
        char * temp = new char[length-len+1];
        for(int i = 0;i < length;i++){
            if(i == posi){
                temp[posi] = begin[posi];
                i += len;
                isAhead = !isAhead;
            }else{
                if(isAhead){
                    temp[i-len] = begin[i];
                }else{
                temp[i] = begin[i];
                }
            }
        }
        return *(new string(temp));
    };
    int find_first_of(const char * str,int index=0){
        int leng = 0;
        while(!(str[leng]=='\0')){
            leng++;
        };
        for(int i = index;i < length;i++){
            for (int j = 0; j < leng ; i++)
            {
            if(begin[i] == str[j]){
                return i;
            }
            }
        }
        return -1;
    }
    int find_first_of(char ch,int index=0){
        for(int i = index;i < length;i++){
            if(begin[i] == ch){
                return i;
            }
        }
        return -1;
    }
    int find_first_of(string & strs,int index=0){
        const char * str = strs.c_str();
        int leng = 0;
        while(!(str[leng]=='\0')){
            leng++;
        };
        for(int i = index;i < length;i++){
            for (int j = 0; j < leng ; i++)
            {
            if(begin[i] == str[j]){
                return i;
            }
            }
        }
        return -1;
    };
    static void swap(string &str1,string &str2){
        const char * temp;
        temp = str1.c_str();
        
    }
};
