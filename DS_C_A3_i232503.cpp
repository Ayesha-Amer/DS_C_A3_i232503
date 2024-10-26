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
                Player *left;
                Player *right;
              //  Games_PLayed_Class GamesPlayed;
                Player(string playerID, string playerName, string phone, string email,string password) {
                        Player_ID = playerID;
                        name = playerName;
                        phoneNo = phone;
                        Email = email;
                        Password = password;
                        left = right = nullptr;
                }

                void info(){
                        cout <<name <<endl<<Player_ID<<endl<<phoneNo<<endl<<Email<<endl<<Password<<endl<<endl;
                }

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
                //Variables to store information about the player
                string name ;
                string id;
                string phno;
                string  email;
                string password;
                string data = "";

        public:
                Tree(){
                        playerRoot = nullptr;
                        gamesRoot = nullptr;
                }
 

                string getInfo(){
                        int randNum = rand() % 1001;
                    //    cout << randNum << endl<<endl;
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

                void separateData(string player){
                        string token;
                        id = name = phno = email = password = data = "";
                        int i=0;
                        while(player[i] != '\0'){
                                token += player[i];
                                if(player[i+1] == ','){
                                                if(id == "\0"){
                                                        id = token;
                                                }
                                                else if(name == "\0"){
                                                        name = token;
                                                }
                                                else if(phno == "\0"){
                                                        phno = token;
                                                }
                                                else if(email == "\0"){
                                                        email = token;
                                                }
                                                else if(password == "\0"){
                                                        password = token;
                                                }
                                                else{
                                                        data += token;
                                                }
                                        ++i;
                                        token = "";
                                }
                                
                                        ++i;
                         }
                }


                Player* insert(Player*root , long long id){
                        if(root == nullptr){
                                root = new Player(to_string(id),name,phno,email,password);
                        }
                        if(id < stoll(root->Player_ID)){
                               root->left =  insert(root->left,id);
                        }

                        if(id > stoll(root->Player_ID)){
                               root->right =  insert(root->right,id);
                        }

                        return root;
                }

                void display(Player *root){
                        if(root == nullptr){
                                return;
                        }
                        root->info();
                        display(root->left);
                        display(root->right);
                }

                void insertPlayer(){
                        string player = getInfo();
                        separateData(player);
                    //    cout << name << "\t" << id << endl;
                        playerRoot = insert(playerRoot,stoll(id));         
                }

                void Display(){
                        display(playerRoot);
                }

};

int main(){
        srand(232503);
        Tree obj;
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
           obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
        obj.insertPlayer();
          
        
        obj.Display();
        return 0;
}