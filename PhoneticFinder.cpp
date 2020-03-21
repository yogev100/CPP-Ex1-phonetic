#include "PhoneticFinder.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

namespace phonetic {
string find(string text, string word) {
        int count=0;
        string* temp=buildStrArr(text,&count);

	    for (int i=0;i<count;i++){
            string a=temp[i];
            if(a.length()==word.length()){
                int k=0;
                while(k<a.length()){
                    if(a[k]==word[k]+32||a[k]==word[k]-32){
                        k++;
                    }
                    else if(a[k]=='v'||a[k]=='w'||a[k]=='V'||a[k]=='W'){
                        if(word[k]=='v'||word[k]=='w'||word[k]=='V'||word[k]=='W'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='b'||a[k]=='f'||a[k]=='p'||a[k]=='B'||a[k]=='F'||a[k]=='P'){
                        if(word[k]=='b'||word[k]=='f'||word[k]=='p'||word[k]=='B'||word[k]=='F'||word[k]=='P'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='g'||a[k]=='j'||a[k]=='G'||a[k]=='J'){
                        if(word[k]=='g'||word[k]=='j'||word[k]=='G'||word[k]=='J'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='c'||a[k]=='k'||a[k]=='q'||a[k]=='C'||a[k]=='K'||a[k]=='Q'){
                        if(word[k]=='c'||word[k]=='k'||word[k]=='q'||word[k]=='C'||word[k]=='K'||word[k]=='Q'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='s'||a[k]=='z'||a[k]=='S'||a[k]=='Z'){
                        if(word[k]=='s'||word[k]=='z'||word[k]=='S'||word[k]=='Z'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='d'||a[k]=='t'||a[k]=='D'||a[k]=='T'){
                        if(word[k]=='d'||word[k]=='t'||word[k]=='D'||word[k]=='T'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='o'||a[k]=='u'||a[k]=='O'||a[k]=='U'){
                        if(word[k]=='o'||word[k]=='u'||word[k]=='O'||word[k]=='U'){
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(a[k]=='i'||a[k]=='y'||a[k]=='I'||a[k]=='Y'){
                        if(word[k]=='i'||word[k]=='y'||word[k]=='I'||word[k]=='Y'){
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
                    delete[] temp;
                    return a;
                }
	        }
        }
        delete[] temp;
        throw std::invalid_argument("the word "+word+" dont exist");
    }
    
    string* buildStrArr(string text,int* n){
        int count=0;
        for (int i = 0; i < text.length(); i++)
        {
            if(text[i]==' '){
                count++;
            }
        }

        string* temp=new string[count+1];
        *n=count+1;
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
        return temp;
    }  
}





