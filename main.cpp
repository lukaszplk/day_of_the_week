#include<iostream>
#include<string>
using namespace std;

class Days_name{
    public:
        
        int day=1, month=1, year=1810;
    
    int years(string date){
        int tmp=0, offset=0;
        for(int i=6;i<10;i++){
            tmp = 10*tmp + (int(date[i])-48);
        }
        
        for(int i=this->year;i<=tmp;i++){
            if((i%4==0 && i%100!=0) || i%400==0){
                offset++;
            }
        }

        tmp = tmp - this->year;
        tmp = tmp*365 + offset;

        return tmp;
    }

    int months(string date){
        int tmp=0, m=0;
        for(int i=3;i<5;i++){
            tmp = 10*tmp + (int(date[i])-48);
        }
        tmp =  tmp - this->month;
        for(int i=0;i<tmp;i++){
            
            if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11){
                m+=31;
            }else if(i==3 || i==5 || i==8 || i==10 ){
                m+=30;
            }else if(i==1){
                m+=28;
            }
        }


        return m;
    }

    int days(string date){
        int tmp=0;
        for(int i=0;i<2;i++){
            tmp = 10*tmp + (int(date[i])-48);
        }

        return tmp - this->day;
    }

    int calc_days(string date){
        
        return this->days(date) + this->months(date) + this->years(date);
    }
};

int main(){
    Days_name counter;
    int day;
    string str;

    

    while(cin>>str){
        day = counter.calc_days(str)%7;
        int year=0;

        for(int i=6;i<10;i++){
            year = 10*year + (int(str[i])-48);
        }

        if((year%4==0 && year%100!=0) || year%400==0){
            if(int(str[3])-48==0 && int(str[4])-48==2 && (int(str[0])-48)*10 + int(str[1]-48) > 29){
                cout<<"ERROR"<<endl;
                continue;
            }
        }else{
            if(int(str[3])-48==0 && int(str[4])-48==2 && (int(str[0])-48)*10 + int(str[1]-48) > 28){
                cout<<"ERROR"<<endl;
                continue;
            }
        }

        if((int(str[0])-48)*10 + int(str[1]-48) > 31 || (int(str[3])-48)*10 + int(str[4]-48) > 12){
            cout<<"ERROR"<<endl;
            continue;
        }

        if((int(str[0])-48)*10 + int(str[1]-48) <= 0 || (int(str[3])-48)*10 + int(str[4]-48) <= 0 || year <= 0){
            cout<<"ERROR"<<endl;
            continue;
        }

        if(((int(str[3])-48)*10 + int(str[4]-48) == 4) || ((int(str[3])-48)*10 + int(str[4]-48) == 6) || ((int(str[3])-48)*10 + int(str[4]-48) == 9) || ((int(str[3])-48)*10 + int(str[4]-48) == 11)){
            if((int(str[0])-48)*10 + int(str[1]-48) > 30){
               cout<<"ERROR"<<endl;
                continue; 
            }
        }

        if(day==0){
            cout<<"PN"<<endl;
        }else if(day==1){
            cout<<"WT"<<endl;
        }else if(day==2){
            cout<<"SR"<<endl;
        }else if(day==3){
            cout<<"CZ"<<endl;
        }else if(day==4){
            cout<<"PT"<<endl;
        }else if(day==5){
            cout<<"SB"<<endl;
        }else if(day==6){
            cout<<"ND"<<endl;
        }
    }
}