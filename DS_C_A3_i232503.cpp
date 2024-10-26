#include<iostream>
#include <fstream>
#include <string>
#include<ctime>
using namespace std;

class Player{
        public:
                string Player_ID;
                string name;
                string phoneNo;
                string Email;
                string Password;
              //  Games_PLayed_Class GamesPlayed;

};

class Games_PLayed_Class{
        public:
                string Game_Id;
                float hoursPlayed;
                int achievements_Unclocked;

};

class Games{
        public:
                string Game_Id;
                string name;
                string developer;
                string publisher;
                float file_size_in_GBs;
                int downloads;

};

class Tree{
        private:
                Player* playerRoot;
                Games * gamesRoot;
        public:
                Tree(){
                        playerRoot = nullptr;
                        gamesRoot = nullptr;
                }
 

                string getInfo(){
                        int randNum = rand() % 1001;
                        cout << randNum << endl<<endl;
                        if (randNum <= 130) { // (last 2 digits of your roll number × 10 + 100)
                                return "";
                        }
                        int curr = 0;
                        string info;
                        fstream  obj("Players.txt");
                        while(getline(obj , info)){
                                ++curr;
                                if(curr == randNum){
                                        obj.close();
                                        return info;
                                }
                        }

                        obj.close();
                        return "";
                
                }

                Player* insert(Player*root , int ID){
                        int i = 0;
                        while(i<8){
                        string player = getInfo();
                        cout << player;
                        cout <<"\n\n\n";
                        ++i;
                        }
                         return root;
                }

};

int main(){
        srand(232503);
        Tree obj;
        obj.insert(nullptr , 3);
        return 0;
}