#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Queue_Node{
        public:
                string id;
                int layer_no;
                Queue_Node *next;
                Queue_Node(string id , int layer_no){
                        this->id = id;
                        this->layer_no = layer_no;
                        next = nullptr;
                }

};

class Queue{
        private:
                Queue_Node* top;
                Queue_Node* rear;
        public:
                Queue(){
                        top = rear = nullptr;
                }

                bool isEmpty(){
                        if(top == nullptr){
                                return true;
                        }
                }

                void Enqueue(string id , int layer_no){
                        Queue_Node* newNode = new Queue_Node (id , layer_no);
                        if(top == nullptr){
                                top = rear = newNode;
                                return;
                        }

                        rear->next = newNode;
                        rear = newNode;

                }

                Queue_Node* Dequeue(){
                        if(isEmpty()){
                                return nullptr;
                        }

                        Queue_Node* temp = top;
                        top = top->next;
                        return temp;

                }

};


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

                //inserts game into the tree

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

                //displays details
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
                int games_played = 0;
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
                        cout <<name <<"\t"<<Player_ID<<"\t"<<phoneNo<<"\t"<<Email<<"\t"<<Password<<"\t"<<games_played;
                        cout << "\nGames Played:\n";
                        GamesPlayed->Display();
                        cout<<endl;
                }

                //separates string into variables and stores int the tree

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
                                                        ++games_played;
                                                        Id = hours = achievements = "";
                                                }
                                               
                                
                                        ++i; //incrementing to skip ','
                                        token = ""; //Emptying the string after insertion
                                }
                                
                                        ++i;
                        }
                }


                Games_PLayed_Class* search(Games_PLayed_Class *root , long long id){
                        if(root == nullptr){ //if reaches leaf nodes then it means the node was not present 
                                return nullptr;}
        
                        cout << root->Game_Id << endl;

                        if(id == stoll(root->Game_Id)){
                                return root;
                        }

                        if(id < stoll(root->Game_Id)){
                                return  search(root->left,id);
                        }
                        else
                                return  search(root->right,id);


                }

                void search_game(long long id){
                        cout << id << endl;
                     
                        Games_PLayed_Class *game = search(GamesPlayed->root,id);
                        
                         if(game == nullptr){
                                cout << "\nNo the player has not played this game";
                                return ;
                       }
                                cout << "\nYes the player has played this game: \n";
                                game->info();
                }

};


class Tree{
        private:
                Player* playerRoot;
                Games * gamesRoot;
                Queue* q;
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
                //Variables for random func
                unsigned int seed = 232503; 
                const unsigned int n1 = 1664525;  
                const unsigned int n2 = 1013904223; 
                const unsigned int n3 = 4294967295; 

        public:
                Tree(){
                        playerRoot = nullptr;
                        gamesRoot = nullptr;
                        make_Player_tree();
                        make_Game_tree();
                }
 
                //Players Tree insertion:

                 //separates string into variables and stores int the tree

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


                //inserts players into the tree
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

                unsigned int getRand(){
                        seed = (n1 * seed + n2) % n3; 
                        return seed; 
                }

                //makes the intial player tree

                void make_Player_tree(){
                        string info;
                        fstream  obj("Players.txt");
                        while(getline(obj , info)){
                                int randNum = getRand() % 1001;
                                if (randNum <= 130){
                                        continue;
                                }
                                separate_player_data(info);
                                playerRoot = insert(playerRoot, stoll(id));
                        }
                        cout << "\nPlayer Tree Created!\n";
                        obj.close();
                           
                }

                //Functions to serach for player
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

                void searchPlayer(string id){
                       Player* p = search(playerRoot,stoll(id));
                       if(p == nullptr){
                                cout<<"\nNo player with id: "<<id<<" in the tree.";
                                return;
                       }
                       cout << endl;
                       p->info();
                }

                //Functions to delete a player
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

                //fucntions to find top N players 
                Player* top_player(Player *root ,Player *topPlayer , int prevMax){ 
                        if(root == nullptr){
                                return topPlayer;
                        }

                        if(root->games_played >= topPlayer->games_played && root->games_played < prevMax ){ //to print in descending order
                                topPlayer = root;
                        }
                        
                        topPlayer = top_player(root->left , topPlayer , prevMax);
                        topPlayer = top_player(root->right , topPlayer , prevMax);

                        return topPlayer;

                }

                void displayTop(Player *root , int max){
                        if(root == nullptr){
                                return;
                        }
                        if(root->games_played == max){
                        root->info();
                        }
                        displayTop(root->left , max);
                        displayTop(root->right , max);

                }


                void find_top_player(int n){
                        int prevMax = 1000000;
                        while(n != 0){
                                Player* top = top_player(playerRoot , playerRoot , prevMax);
                                int maxValue = top->games_played;
                                prevMax = maxValue;
                               // cout << maxValue << endl;
                                cout << "\nTop Player "<<n<<" : \n";
                                displayTop(playerRoot , maxValue);
                                --n;
                        }
                        prevMax = 1000000; //resetting
                }

                void deletePlayer(string id){
                        Player *p = search(playerRoot , stoll(id));
                        if(p == nullptr){
                                cout <<"\nNo player with this id.\n";
                                return;
                        }
                       playerRoot = deleteNode(playerRoot,stoll(id));
                       cout << "Deleted!";
                }

                //Fucntions to display path for a player
                void display_player(Player *root , string id , int* found ){
                        if(*found == 1){
                                return;
                        }
                        if (root == nullptr) {
                                return; 
                        }
                        root->info();
                        if(root->Player_ID == id){
                                *found = 1;
                                return;
                        }
                        display_player(root->left , id , found);
                        display_player(root->right , id , found);
                }


                void Player_Display(string id){
                        Player *p = search(playerRoot , stoll(id));
                        if(p == nullptr){
                                cout <<"\nNo player with this id.\n";
                                return;
                        }
                        int found = 0;
                        display_player(playerRoot, id , &found);
                }
             
                //Funcitons to check if a player has played a game
                void has_played(long long player_id , long long game_id){
                        Player* p = search(playerRoot,player_id);
                        if(p == nullptr){
                                cout<<"\nNo player with id: "<<id<<" in the tree.";
                                return;
                        }
                        p-> search_game(game_id);
                }

                //Saves player data into a csv file
                
                void save_player_data(Player* root , fstream &obj){
                        if(root == nullptr){
                                return;
                        }
                        obj << root->Player_ID << "," << root->name << "," << root->phoneNo << ","
                        << root->Email << "," << root->Password << "," << root->games_played << ",";
                        Games_PLayed_Class* gameRoot = root->GamesPlayed->root;
                        save_game_data(gameRoot, obj);
                        obj << "\n";

                        save_player_data(root->left, obj);
                        save_player_data(root->right, obj);

                }
                //Saves games_played data into  a csv file
                void save_game_data(Games_PLayed_Class* root, fstream &obj) {
                        if (root == nullptr) {
                                return;
                        }
                        obj << root->Game_Id << "," << root->hoursPlayed << "," << root->achievements_Unlocked << "," ;
                        save_game_data(root->left, obj);
                        save_game_data(root->right, obj);
                        }

                void savePlayerData(){
                        fstream obj;
                        obj.open("Saved_Players.csv" , ios::out);
                        obj << "Player_ID,Name,Phone,Email,Password,Games_Played\n";
                        save_player_data(playerRoot , obj);
                        obj.close();
                        cout << "Player data has been saved successfully to Saved_Players.csv.\n";
                }

                //Function to edit a players entry
                void edit_player_entry(string id) {
                        int choice;
                        string newEntry = "";

                        Player* p = search(playerRoot, stoll(id)); 

                        if (p == nullptr) {
                        cout << "Player with ID " << id << " not found." << endl;
                        return;
                        }

                        cout << "Editing Player Entry for Player ID: " << id << endl;
                        cout << "1. Edit Player Name" << endl;
                        cout << "2. Edit Player Phone Number" << endl;
                        cout << "3. Edit Player Email" << endl;
                        cout << "4. Edit Player Password" << endl;
                        cout << "5. Edit Player ID" << endl;
                        cout << "6. Exit" << endl;

                        cout << "Enter your choice (1-6): ";
                        cin >> choice;

                        switch (choice) {
                                case 1:
                                        cout << "Enter new player name: ";
                                        cin.ignore();  // To clear the input buffer
                                        getline(cin, newEntry);
                                        p->name = newEntry;
                                break;

                                case 2:
                                        cout << "Enter new player phone number: ";
                                        cin.ignore();  // To clear the input buffer
                                        getline(cin, newEntry);
                                        p->phoneNo = newEntry;
                                break;

                                case 3:
                                        cout << "Enter new player email: ";
                                        cin.ignore();  // To clear the input buffer
                                        getline(cin, newEntry);
                                        p->Email = newEntry;
                                break;

                                case 4:
                                        cout << "Enter new player password: ";
                                        cin.ignore();  // To clear the input buffer
                                        getline(cin, newEntry);
                                        p->Password = newEntry;
                                break;

                                case 5:
                                        //for id deletes the node and re-inserts it
                                        cout << "Enter new Player ID: ";
                                        cin >> newEntry;
                                        p->Player_ID= newEntry;
                                        playerRoot = deleteNode(playerRoot, stoll(id));
                                        playerRoot = insert(playerRoot, stoll(p->Player_ID));  
                                break;

                                case 6:
                                         cout << "Exiting edit menu." << endl;
                                break;

                                default:
                                         cout << "Invalid choice. Please select a number between 1 and 6." << endl;
                                break;
                        }
                        cout << "\nAfter changes:\n";
                        p->info();  
                }  

                //function to insert a player
                void insertPlayerData() {
                        string id, name, phoneNo, email, password;

                        cout << "Enter ID: ";
                        cin >> id;
                        cin.ignore();

                        if(!(search(playerRoot,stoll(id))== nullptr)){
                                cout << "\nPlayer with this id is already present.";
                                return;
                        }

                        cout << "Enter Name: ";
                        getline(cin, name);

                        cout << "Enter Phone Number: ";
                        getline(cin, phoneNo);

                        cout << "Enter Email: ";
                        getline(cin, email);

                        cout << "Enter Password: ";
                        getline(cin, password);

                        Player* newPlayer = new Player(id, name, phoneNo, email, password, "");
                        playerRoot = insert(playerRoot, stoll(id));
                        cout << "Player inserted ." << endl;
                        newPlayer->info(); 
                }


                //Games Tree implementation:

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


                //Inserts game into the tree
                Games* insert_Game(Games *root , long long id ){
                        if(root == nullptr){
                             //   cout << Game_Id <<"\t"<< game_name <<"\t"<< developer <<"\t "<<publisher <<"\t"<< file_size_in_GBs <<"\t"<< downloads <<endl;
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
                //Makes the initial game tree
                void make_Game_tree(){
                        string info;
                        fstream obj("Games.txt");
                        while (getline(obj, info)) {
                                separate_game_data(info);
                                gamesRoot = insert_Game(gamesRoot , stol(Game_Id));
                                }
                        cout << "\nGame tree created.\n";
                       obj.close();

                }

                //Functions to serach for a game
                Games* searchG(Games*root , long long id){
                        if(root == nullptr){ //if reaches leaf nodes then it means the node was not present 
                                cout << id << endl;
                                return nullptr;}
        

                        if(id == stoll(root->Game_Id)){
                                cout << id << endl;
                                return root;
                        }

                        if(id < stoll(root->Game_Id)){
                                return  searchG(root->left,id);
                        }
                        else
                                 return  searchG(root->right,id);

                }

                void search_Game(string id){
                       Games* g = searchG(gamesRoot,stoll(id));
                       if(g == nullptr){
                                cout<<"\nNo Game with id: "<<id<<" in the tree.";
                                return;
                       }
                       g->info();
                }

                //Fucntions to delete a game
                Games* findMax(Games *root){
                        while(root->right != nullptr){
                                root = root->right; //searching for max in left sub tree
                        }
                        return root;
                }

                Games* delete_Games_Node(Games*root , long long id){
                        if(root == nullptr){ //if reaches leaf nodes
                                return root; 
                        }

                        //Searching the node in left and right trees.
                        if(id < stoll(root->Game_Id)){
                                root->left = delete_Games_Node(root->left,id);
                        }

                        else if(id > stoll(root->Game_Id)){
                                root->right = delete_Games_Node(root->right,id);
                        }

                        else{
                                if(root->left == nullptr){      //If there is no left child it will take value of right child
                                        Games *temp = root->right;
                                        delete root; //Delete the root and take valur of right child
                                        return temp;
                                }
                                if(root->right == nullptr){      //If there is no right child it will take value of left child
                                        Games *temp = root->left;
                                        delete root; //Delete the root and take value of left child
                                        return temp;
                                }

                        //If the node has 2 child then consider the predecessor deletion which is replacing it by the max id in the left tree:
                        Games* temp = findMax(root->left);
                        root->Game_Id = temp->Game_Id;
                        root->left = delete_Games_Node(root->left,stoll(temp->Game_Id)); //Callling the func again to delete the left node properly 
                        }
                return root;
                }

                void deleteGame(string id){
                        Games* g = searchG(gamesRoot,stoll(id));
                        if(g == nullptr){
                                cout << "\nNo game with this id.\n";
                                return;
                        }
                        gamesRoot = delete_Games_Node(gamesRoot,stoll(id));
                }

                //fucntion to save data into csv
                void save_game_data(Games* root, fstream &obj) {
                        if (root == nullptr) {
                                return;
                        }

                        obj << root->Game_Id << "," << root->name << "," << root->developer << ","
                                << root->publisher << "," << root->file_size_in_GBs << "," << root->downloads << "\n";

                        save_game_data(root->left, obj);
                        save_game_data(root->right, obj);
}

                void saveGameData() {
                        fstream obj;
                                obj.open("Saved_Games.csv", ios::out);
                                obj << "Game_ID,Name,Developer,Publisher,File_Size_GBs,Downloads\n";
                                save_game_data(gamesRoot, obj);
                                obj.close();
                                cout << "Game data has been saved successfully to Saved_Games.csv.\n";
                }

                //fucntions to display path for a game

                void game_display(Games *root ,  string id , int* found){
                        if(*found == 1){
                                return;
                        }
                        if (root == nullptr) {
                                return; 
                        }
                        root->info();
                        if(root->Game_Id== id){
                                *found = 1;
                                return;
                        }
                        game_display(root->left,id,found);
                        game_display(root->right,id,found);
                        
                       return;
                }

                void GameDisplay(string id){
                        Games* g = searchG(gamesRoot,stoll(id));
                        if(g == nullptr){
                                cout << "\nNo game with this id.\n";
                                return;
                        }
                        int found = 0;
                        game_display(gamesRoot,id,&found);
                      
                }

                //fucntion to edit a game entry
                void edit_game_entry(string id) {
                        int choice;
                        string newEntry = "";
                        Games *g = searchG(gamesRoot , stoll(id));
                        
                        cout << "Editing Game Entry for Game ID: " << id << endl;
                        cout << "Please select the attribute you want to edit:" << endl;
                        cout << "1. Edit Game Name" << endl;
                        cout << "2. Edit Developer" << endl;
                        cout << "3. Edit Publisher" << endl;
                        cout << "4. Edit File Size (in GBs)" << endl;
                        cout << "5. Edit Downloads" << endl;
                        cout << "6. Edit Game Id" << endl;
                        cout << "7. Exit" << endl;

                        cout << "Enter your choice (1-6): ";
                        cin >> choice;
                        switch (choice) {
                                case 1:
                                        cout << "Enter new game name: " << endl;
                                        cin >> newEntry;
                                        g->name = newEntry;
                                        break;
                                case 2:
                                        cout << "Enter new developer name: " << endl;
                                        cin >> newEntry;
                                        g->developer = newEntry;
                                        break;
                                case 3:
                                        cout << "Enter new publisher name: " << endl;
                                        cin >> newEntry;
                                        g->publisher = newEntry;
                                        break;
                                case 4:
                                        cout << "Enter new File Size: " << endl;
                                        cin >> newEntry;
                                        g->file_size_in_GBs = stod(newEntry);
                                        break;
                                case 5:
                                        cout << "Enter new no. of downloads: " << endl;
                                        cin >> newEntry;
                                        g->downloads = stoll(newEntry);
                                        break;
                                case 6:

                                        //incase of id deletes the node and re-inserts with the new id
                                        cout << "Enter new game id: " << endl;
                                        cin >> newEntry;
                                        g->Game_Id = newEntry;
                                        deleteGame(g->Game_Id);
                                        gamesRoot = insert_Game(gamesRoot, stoll(g->Game_Id));  
                                        cout << "Game ID updated to: " << g->Game_Id << endl;
                                        break;

                                case 7:
                                        cout << "Exiting edit menu." << endl;
                                        break;
                                default:
                                        cout << "Invalid choice. Please select a number between 1 and 6." << endl;
                                        break;
                        }
                        cout << "\nAfter changes:\n";
                        g->info();
                }
                
                //function to insert a new game into the tree
                void insertGameData() {
                        string id, name, developer, publisher, fileSize, downloads;

                        cout << "\nEnter Game ID: ";
                        cin >> id;
                        
                        if (!(searchG(gamesRoot, stoll(id))== nullptr)){
                                cout << "\nGame with this id is already present.\n";
                                return;
                        }

                        cout << "Enter Name: ";
                        getline(cin, name);

                        cout << "Enter developer name: ";
                        getline(cin, developer);

                        cout << "Enter publisher name: ";
                        getline(cin, publisher);

                        cout << "Enter fileSize: ";
                        getline(cin, fileSize);

                        cout << "Enter downloads: ";
                        getline(cin, downloads);

                        Games* newGame = new Games(id, name, developer, publisher, stod(fileSize), stoll(downloads));
                        gamesRoot = insert_Game(gamesRoot, stoll(id));
                        cout << "Game inserted ." << endl;
                        newGame->info();
                       
                      
                }



};
int main() {
        Tree obj;
        int choice;
        string id;
        int n;
       
        while (true) {
                cout << "\nMenu:\n";
                cout << "1. Insert Player\n";
                cout << "2. Delete Player\n";
                cout << "3. Search Player\n";
                cout << "4. Insert Game\n";
                cout << "5. Delete Game\n";
                cout << "6. Search Game\n";
                cout << "7. Find Top N Players\n";
                cout << "8. Check if Player has Played a Game\n";
                cout << "9. Display path of a player\n";
                cout << "10. Display path of a game\n";
                cout << "11. Save game data in csv\n";
                cout << "12. Save player data in csv \n";
                cout << "13. Edit Player Entry\n";
                cout << "14. Edit Game entry\n";
                cout << "15. Exit\n";

                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                        case 1:
                                obj.insertPlayerData();
                        break;

                        case 2:
                                cout << "Enter player ID to delete: ";
                                cin >> id;
                                obj.deletePlayer(id);
                        break;

                        case 3:
                                cout << "Enter player ID to search: ";
                                cin >> id;
                                obj.searchPlayer(id);
                        break;

                        case 4:
                                obj.insertGameData();
                        break;

                        case 5:
                                cout << "Enter game ID to delete: ";
                                cin >> id;
                                obj.deleteGame(id);
                        break;

                        case 6:
                                cout << "Enter game ID to search: ";
                                cin >> id;
                                obj.search_Game(id);
                        break;

                        case 7:
                                cout << "Enter the number of top players to find: ";
                                cin >> n;
                                obj.find_top_player(n);
                        break;

                        case 8:
                                long long player_id, game_id;
                                cout << "Enter player ID: ";
                                cin >> player_id;
                                cout << "Enter game ID: ";
                                cin >> game_id;
                                obj.has_played(player_id, game_id);
                        break;

                        case 9:
                                cout << "\nEnter player id: ";
                                cin >> id;
                                obj.Player_Display(id);
                        break;
                        case 10:
                                cout << "\nEnter game id: ";
                                cin >> id;
                                obj.GameDisplay(id);
                        break;
                        case 11:
                                obj.savePlayerData();
                        break;
                        case 12:
                                obj.saveGameData();
                        break;
                        case 13:
                                cout << "\nEnter player id: ";
                                cin >> id;
                                obj.edit_player_entry(id);

                        break;
                        case 14:
                                cout << "\nEnter game id: ";
                                cin >> id;
                                obj.edit_game_entry(id);

                        break;
                        case 15:
                                cout << "Exiting.";
                                return 0;
                        break;
                        default:
                        cout << "Invalid choice. Please try again." << endl;
                }
        }
return 0;
}

    