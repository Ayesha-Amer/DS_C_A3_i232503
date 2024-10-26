#include<iostream>
#include <fstream>
#include <string>
#include<ctime>
using namespace std;

class Games_PLayed_Class{
        public:
                string Game_Id;
                float hoursPlayed;
                int achievements_Unlocked;

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

class Player{
        public:
                string Player_ID;
                string name;
                string phoneNo;
                string Email;
                string Password;
                Player *left;
                Player *right;
                string games;
                Games_PLayed_Class GamesPlayed;

                Player(string playerID, string playerName, string phone, string email,string password,string games) {
                        Player_ID = playerID;
                        name = playerName;
                        phoneNo = phone;
                        Email = email;
                        Password = password;
                        this->games = games;
                        left = right = nullptr;
                }

                void info(){
                        cout <<name <<endl<<Player_ID<<endl<<phoneNo<<endl<<Email<<endl<<Password<<endl<<endl;
                }

             //   void separateGameInfo(){

              //  }

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
                                                        data += token + ",";
                                                }
                                        ++i;
                                        token = "";
                                }
                                
                                        ++i;
                         }
                }


                Player* insert(Player*root , long long id){
                        if(root == nullptr){
                                return new Player(to_string(id),name,phno,email,password,data);
                        }
                        if(id < stoll(root->Player_ID)){
                               root->left =  insert(root->left,id);
                        }

                        else if(id > stoll(root->Player_ID)){
                               root->right =  insert(root->right,id);
                        }

                        else{
                                cout << "Primary key of the object being inserted already exists.";
                        }

                        return root;
                }

                void insertPlayer(){
                        string player = getInfo();
                        separateData(player);
                    //    cout << name << "\t" << id << endl;
                        playerRoot = insert(playerRoot,stoll(id));         
                }

                Player* search(Player*root , long long id){
                        if(root == nullptr){ //if reaches leaf nodes then it means the node was not present 
                                return nullptr;}
        

                        if(id == stoll(root->Player_ID)){
                                return root;
                        }

                        if(id < stoll(root->Player_ID)){
                                return  search(root->left,id);
                        }
                        else
                                 return  search(root->right,id);

                }

                void searchPLayer(string id){
                       Player* p = search(playerRoot,stoll(id));
                       if(p == nullptr){
                                cout<<"\nNo player with id: "<<id<<" in the tree.";
                                return;
                       }
                       p->info();
                }

                Player* findMax(Player *root){
                        while(root->right != nullptr){
                                root = root->right; //searching for max in left sub tree
                        }
                        return root;
                }

                Player* deleteNode(Player*root , long long id){
                        if(root == nullptr){ //if reaches leaf nodes
                                return root; 
                        }

                        //Searching the node in left and right trees.
                        if(id < stoll(root->Player_ID)){
                                root->left = deleteNode(root->left,id);
                        }

                        else if(id > stoll(root->Player_ID)){
                                root->right = deleteNode(root->right,id);
                        }

                        else{
                                if(root->left == nullptr){      //If there is no left child it will take value of right child
                                        Player *temp = root->right;
                                        delete root; //Delete the root and take valur of right child
                                        return temp;
                                }
                                if(root->right == nullptr){      //If there is no right child it will take value of left child
                                        Player *temp = root->left;
                                        delete root; //Delete the root and take value of left child
                                        return temp;
                                }

                        //If the node has 2 child then consider the predecessor deletion which is replacing it by the max id in the left tree:
                        Player* temp = findMax(root->left);
                        root->Player_ID = temp->Player_ID;
                        root->left = deleteNode(root->left,stoll(temp->Player_ID)); //Callling the func again to delete the right node properly 
                        }
                return root;
                }

                void deletePlayer(string id){
                       playerRoot = deleteNode(playerRoot,stoll(id));
                }
                
                void display(Player *root){
                        if(root == nullptr){
                                return;
                        }
                        root->info();
                        display(root->left);
                        display(root->right);
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
        obj.Display();
        obj.searchPLayer("4038366928");
        cout << "\nDeleting:\n";
        obj.deletePlayer("4038366928");
        obj.Display();
        return 0;
}