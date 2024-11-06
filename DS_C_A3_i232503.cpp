#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Games_PLayed_Class{
         public:
                Games_PLayed_Class *root = nullptr;
                string Game_Id;
                double hoursPlayed;
                long long achievements_Unlocked;
                Games_PLayed_Class * left;
                Games_PLayed_Class * right;

                Games_PLayed_Class(string id, double hours , int achievements){
                        Game_Id = id;
                        hoursPlayed = hours;
                        achievements_Unlocked = achievements;
                        left = right = nullptr;
                }

                Games_PLayed_Class* insertGame(Games_PLayed_Class* root , long long Id , double h , long long a  ){
                         if(root == nullptr){
                                return new Games_PLayed_Class(to_string(Id),h,a);
                        }
                        if(Id < stoll(root->Game_Id)){
                               root->left =  insertGame(root->left,Id,h,a);
                        }

                        if(Id > stoll(root->Game_Id)){
                               root->right =  insertGame(root->right,Id,h,a);
                        }

                        
                        return root;

                }

                void insert(string Id, double hours,long long achievements){
                        Games_PLayed_Class* newNode = new Games_PLayed_Class(Id,hours,achievements);
                        root = insertGame(root,stoll(Id),hours,achievements);
                }

                void info(){
                        cout << "Game_Id: "<<Game_Id << "\tHours Played: " << hoursPlayed << "\tAchievements Unloacked: " << achievements_Unlocked << endl;
                }

                void display(Games_PLayed_Class *root){
                        if(root == nullptr){
                                return;
                        }
                        root->info();
                        display(root->left);
                        display(root->right);
                }

                void Display(){
                        display(root);
                }

};

class Games{
         public:
                string Game_Id;
                string name;
                string developer;
                string publisher;
                double file_size_in_GBs;
                long downloads;
                Games *left;
                Games *right;

                Games(string gameId, string gameName, string gameDeveloper, string gamePublisher, double fileSize, long gameDownloads) {
                        Game_Id = gameId;
                        name = gameName;
                        developer = gameDeveloper;
                        publisher = gamePublisher;
                        file_size_in_GBs = fileSize;
                        downloads = gameDownloads;
                        right = left = nullptr;
                }

                void info(){
                        cout << Game_Id <<"\t"<< name <<"\t"<< developer <<"\t "<<publisher <<"\t"<< file_size_in_GBs <<"\t"<< downloads <<endl;
                }
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
                Games_PLayed_Class *GamesPlayed = new Games_PLayed_Class("", 0.0f, 0);
               
                Player(string playerID, string playerName, string phone, string email,string password,string games) {
                        Player_ID = playerID;
                        name = playerName;
                        phoneNo = phone;
                        Email = email;
                        Password = password;
                        this->games = games;
                        left = right = nullptr;
                        separateGameInfo();
                }

                void info(){
                        cout <<name <<endl<<Player_ID<<endl<<phoneNo<<endl<<Email<<endl<<Password<<"\nGames Played: \n";
                        GamesPlayed->Display();
                        cout<<endl<<endl;
                }

                void separateGameInfo(){
                        string Id;
                        string hours;
                        string achievements;
                        string token = "";
                        int i=0;
                        while(games[i] != '\0'){
                                token += games[i];
                                if(games[i+1] == ','){
                                                if(Id == "\0"){
                                                        Id = token;
                                                }
                                                else if(hours == "\0"){
                                                        hours= token;
                                                }
                                                else if(achievements== "\0"){
                                                        achievements = token;

                                                        //Makes the node when the 3 values are filled
                                                        GamesPlayed->insert(Id,stod(hours),stoll(achievements));
                                                        Id = hours = achievements = "";
                                                }
                                               
                                
                                        ++i; //incrementing to skip ','
                                        token = ""; //Emptying the string after insertion
                                }
                                
                                        ++i;
                        }
                }

};


class Tree{
        private:
                Player* playerRoot;
                Games * gamesRoot;
                //Variables to store information about the player
                string player_name ;
                string id;
                string phno;
                string  email;
                string password;
                string data = "";
                //Variables to store information about a game:
                string Game_Id;
                string game_name;
                string developer;
                string publisher;
                string file_size_in_GBs;
                string downloads;

        public:
                Tree(){
                        playerRoot = nullptr;
                        gamesRoot = nullptr;
                        make_Player_tree();
                        make_Game_tree();
                }
 
                void separate_player_data(string player){
                        string token;
                        id = player_name = phno = email = password = data = "";
                        int i=0;
                        while(player[i] != '\0'){
                                token += player[i];
                                if(player[i+1] == ','){
                                                if(id == "\0"){
                                                        id = token;
                                                }
                                                else if(player_name == "\0"){
                                                        player_name = token;
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
                                        ++i; //incrementing to skip ','
                                        token = ""; //Emptying the string after insertion
                                }
                                
                                        ++i;
                         }
                }

                void separate_game_data(string games){
                        Game_Id = "";
                        game_name = "";
                        developer = "";
                        publisher = "";
                        file_size_in_GBs = "";
                        downloads = "";
                        string token = "";

                        int i=0;

                        while(games[i] != '\0'){
                                token += games[i];
                                if(games[i+1] == ','){
                                                if(Game_Id == "\0"){
                                                        Game_Id = token;
                                                }
                                                else if(game_name == "\0"){
                                                        game_name = token;
                                                }
                                                else if(developer == "\0"){
                                                        developer = token;
                                                }
                                                else if(publisher == "\0"){
                                                        publisher = token;
                                                }
                                                else if(file_size_in_GBs == "\0"){
                                                        file_size_in_GBs = token;
                                                }
                                
                                        ++i; //incrementing to skip ','
                                        token = ""; //Emptying the string after insertion
                                }
                                
                                        ++i;
                        }
                        downloads= token;
                        
                }


                Player* insert(Player*root , long long id){
                        if(root == nullptr){
                                return new Player(to_string(id),player_name,phno,email,password,data);
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

                Games* insert_Game(Games *root , int id ){
                        if(root == nullptr){
                                //cout << Game_Id <<"\t"<< game_name <<"\t"<< developer <<"\t "<<publisher <<"\t"<< file_size_in_GBs <<"\t"<< downloads <<endl;
                                return new Games (Game_Id , game_name , developer , publisher , stod(file_size_in_GBs) , stol(downloads));
                        }
                        if(id < stol(root->Game_Id)){
                                root->left = insert_Game(root->left , id);
                        }
                        if(id > stol(root->Game_Id)){
                                root->right = insert_Game(root->right , id);
                        }

                        return root;

                }

                void make_Game_tree(){
                        string info;
                        fstream obj("Games.txt");
                        while (getline(obj, info)) {
                                separate_game_data(info);
                                gamesRoot = insert_Game(gamesRoot , stol(Game_Id));
        
                                }

                       obj.close();

                }

                void make_Player_tree(){
                        string info;
                        fstream  obj("Players.txt");
                        while(getline(obj , info)){
                                int randNum = rand() % 1001;
                                if (randNum <= 130){
                                        continue;
                                }
                                separate_player_data(info);
                                playerRoot = insert(playerRoot, stoll(id));
                        }

                        obj.close();
                           
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
                
                void display_player(Player *root){
                        if(root == nullptr){
                                return;
                        }
                        root->info();
                        display_player(root->left);
                        display_player(root->right);
                }

                void Display(){
                        display_player(playerRoot);
                }

                void game_display(Games *root){
                        if(root == nullptr){
                                return;
                        }
                        root->info();
                        game_display(root->left);
                        game_display(root->right);
                }

                void GameDisplay(){
                        game_display(gamesRoot);
                }

};

int main(){
        srand(232503);
        Tree obj;
      //  obj.insertPlayer();
        cout << "\n\n\nNew players:\n";
       //   obj.insertPlayer();
     //   obj.insertPlayer();
       //] obj.insertPlayer();
      // obj.Display();
       obj.GameDisplay();
        return 0;
}