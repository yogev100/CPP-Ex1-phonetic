#include "PhoneticFinder.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

namespace phonetic {
	string find(string text, string word) {
        int count=0;
        for (int i = 0; i < text.length(); i++)
        {
            if(text[i]==' '){
                count++;
            }
        }

        string temp[count+1];
        count=0;
        int k=0;
        for(int i=0;i<text.length();i++){
            if(text[i]!=' '){
                count++;
            }
            else {
                temp[k]=text.substr(i-count,count);
                count=0;
                k++;
            }
            if(i==text.length()-1){
                temp[k]=text.substr(i-count+1,count+1);
                k++;
            }
        }
        
	    for (string a:temp){
            if(a.length()==word.length()){
                int k=0;
                while(k<a.length()){
                    if(a[k]==word[k]+32||a[k]==word[k]-32){
                        k++;
                    }
                    else if(a[k]=='v'||a[k]=='w'){
                        if(word[k]=='v'||word[k]=='w'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='b'||a[k]=='f'||a[k]=='p'){
                        if(word[k]=='b'||word[k]=='f'||word[k]=='p'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='g'||a[k]=='j'){
                        if(word[k]=='g'||word[k]=='j'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='c'||a[k]=='k'||a[k]=='q'){
                        if(word[k]=='c'||word[k]=='k'||word[k]=='q'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='s'||a[k]=='z'){
                        if(word[k]=='s'||word[k]=='z'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='d'||a[k]=='t'){
                        if(word[k]=='d'||word[k]=='t'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='o'||a[k]=='u'){
                        if(word[k]=='o'||word[k]=='u'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='i'||a[k]=='y'){
                        if(word[k]=='i'||word[k]=='y'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        if(a[k]==word[k]){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                }
                if(k==word.length()){
                    return a;
                }
	        }
        }
        throw std::invalid_argument("the word "+word+" dont exist");
    }
    
}




