/*
File:    proj2.cpp
Project: CMSC 202 Project 2, Fall 2016
Author:  Austin Bailey
Date:    10/16/16
Section: 101
E-mail:  baustin1@umbc.edu

This file takes these vectors of Pokemon objects
and asks the user what to do with them. Depending on the users answer, they can see the pokedex,
see their collection of Pokemon, find new Pokemon, battle Pokemon, and train their Pokemon. Once done,
the user can exit and their collection is saved to a text file.
*/

#include "proj2.h"

int main () {
  //seeds the random numbers
  srand(time(NULL));
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

void getPokeDex(vector<Pokemon> & pokeDex){
  fstream inputStream;
  int num, minCP, maxCP, rarity;
  string name;
  inputStream.open("pokeDex.txt");
  for (int i = 0; i < POKECOUNT; i++) {
    inputStream >> num >> name >> minCP >> maxCP >> rarity;
    //creates a new Pokemon object for all 151 pokemon in pokeDex.txt
    Pokemon newPoke(num, name, minCP, maxCP, rarity);
    //pushes it into the vector of Pokemon objects
    pokeDex.push_back(newPoke);
  }
  inputStream.close();
}

void getMyCollection(vector<MyPokemon> & myCollection){
  fstream inputStream, anotherStream;
  int num, cp, hp, rarity, count;
  int countOfItems = 0;
  string name, tempWord;
  inputStream.open("myCollection.txt");
  anotherStream.open("myCollection.txt");
  //goes through myCollection.txt and counts amount of objects
  while (anotherStream >> tempWord) {
    countOfItems++;
  }
  //uses amount of objects to determine how many MyPokemon objects are created
  count = (countOfItems / 5);
  for (int i = 0; i < count; i++) {
    inputStream >> num >> name >> cp >> hp >> rarity;
    MyPokemon newMyPoke(num, name, cp, hp, rarity);
    myCollection.push_back(newMyPoke);
  }
  inputStream.close();
  anotherStream.close();
}

void printPokeDex(vector <Pokemon> & pokeDex){
  //iterates through pokeDex vector and prints out the name and number of each Pokemon object
  for(int i = 0; i < (int)pokeDex.size(); i++) {
    cout << pokeDex.at(i).GetNum() << " " << pokeDex.at(i).GetName() << endl;
  }
}

void printMyCollection(vector <MyPokemon> & myCollection){
  //iterates through myCollection vector and prints out all aspects of the MyPokemon objects
  for(int i = 0; i < (int)myCollection.size(); i++) {
    cout << i << "." << " " << myCollection.at(i).GetNum() << " " << myCollection.at(i).GetName() << " " << myCollection.at(i).GetCP() << " " << myCollection.at(i).GetHP() << " " << myCollection.at(i).GetRarity() << endl;;
  }
}

void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int choice, randomValue = 0;
  cout << "What type of Pokemon would you like to try and catch?:" << endl;
  cout << "1. Very Common (Very High Probability)" << endl;
  cout << "2. Common (High Probability)" << endl;
  cout << "3. Uncommon (Normal Probability)" << endl;
  cout << "4. Rare (Low Probability)" << endl;
  cout << "5. Ultra Rare (Extremely Low Probability)" << endl;
  cin >> choice;
  //depending on choice, checks to see if the randomValue is sufficient for finding a pokemon
  switch(choice) {
  case 1:
    //sets randomValue to an integer between 1 and 100
    randomValue = rand() % 100 + 1;
    if (randomValue <= 65) {
      foundPokemon(choice, pokeDex, myCollection);
    } else {
      cout << "Sorry. You found nothing." << endl;
    }
    break;
  case 2:
    randomValue = rand() % 100 + 1;
    if (randomValue <= 45) {
      foundPokemon(choice, pokeDex, myCollection);
    } else {
      cout << "Sorry. You found nothing." << endl;
    }
    break;
  case 3:
    randomValue = rand() % 100 + 1;
    if (randomValue <= 25) {
      foundPokemon(choice, pokeDex, myCollection);
    } else {
      cout << "Sorry. You found nothing." << endl;
    }
    break;
  case 4:
    randomValue = rand() % 100 + 1;
    if (randomValue <= 10) {
      foundPokemon(choice, pokeDex, myCollection);
    } else {
      cout << "Sorry. You found nothing." << endl;
    }
    break;
  case 5:
    randomValue = rand() % 100 + 1;
    if (randomValue == 1) {
      foundPokemon(choice, pokeDex, myCollection);
    } else {
      cout << "Sorry. You found nothing." << endl;
    }
    break;
  default:
    break;
  }
}

void foundPokemon(int rarity, vector <Pokemon> & pokeDex, 
		 vector<MyPokemon> & myCollection ){
  int selectedPoke = 0;
  int positionOfSelectedPoke = 0;
  int countOfRarePoke = 0;
  int randomCP = 0;
  int pokeHP = 0;
  //counts the amount of Pokemon with the set rarity
  for (int i = 0; i < (int)pokeDex.size(); i++) {
    if (pokeDex.at(i).GetRarity() == rarity) {
      countOfRarePoke++;
    }
  }
  //randomly selects one of the Pokemon with the set rarity
  selectedPoke = rand() % countOfRarePoke + 1;
  //resets the count for another iteration
  countOfRarePoke = 0;
  for (int j = 0; j < (int)pokeDex.size(); j++) {
    if (pokeDex.at(j).GetRarity() == rarity) {
      countOfRarePoke++;
      //checks to see if the current Pokemon is the randomly selected one
      if (countOfRarePoke == selectedPoke) {
	//gets the actual position of the random Pokemon
	positionOfSelectedPoke = j;
      }
    }
  }
  cout << "You found a " << pokeDex.at(positionOfSelectedPoke).GetName() << "!" << endl;
  randomCP = rand() % pokeDex.at(positionOfSelectedPoke).GetCPMax() + pokeDex.at(positionOfSelectedPoke).GetCPMin();
  //sets the Pokemon hp
  pokeHP = randomCP / 10;
  //adds the newly found Pokemon to myCollection vector of MyPokemon objects
  MyPokemon newAddedPoke(pokeDex.at(positionOfSelectedPoke).GetNum(), pokeDex.at(positionOfSelectedPoke).GetName(), randomCP, pokeHP, rarity);
  myCollection.push_back(newAddedPoke);
}

void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 6);
  
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      if ((int)myCollection.size() >= 1) {
	battlePokemon(pokeDex, myCollection);
      } else {
	cout << "You need to catch some Pokemon before battling." << endl;
      }
      break;
    case 5:
      if ((int)myCollection.size() >= 1) {
	trainPokemon(pokeDex, myCollection);
      } else {
	cout << "Catch some Pokemon to train." << endl;
      }
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}
 void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int randomPoke, randomCP, choosePoke;
   for(int i = 0; i < (int)myCollection.size(); i++) {
     cout << i << "." << " " << myCollection.at(i).GetNum() << " " << myCollection.at(i).GetName() << " " << myCollection.at(i).GetCP() << " " << myCollection.at(i).GetHP() << " " << myCollection.at(i).GetRarity() << endl;
   }
   //selects a random Pokemon to fight
   randomPoke = rand() % MAX_POKEMON + MIN_POKEMON;
   //sets its cp dependent on what the random Pokemon was
   randomCP = rand() % pokeDex.at(randomPoke).GetCPMax() + pokeDex.at(randomPoke).GetCPMin();
   cout << "You are going to fight a " << pokeDex.at(randomPoke).GetName() << endl;
   cout << "The enemy has a CP of " << randomCP << endl;
   cout << "Which of your pokemon would you like to use?: " << endl;
   cin >> choosePoke;
   //checks to make sure the user is selecting a valid Pokemon
   if (choosePoke >= 0 && choosePoke <= ((int)myCollection.size()-1)) {
     if (randomCP > myCollection.at(choosePoke).GetCP()) {
       cout << "Sorry, you lose the battle." << endl;
     } else if (randomCP < myCollection.at(choosePoke).GetCP()) {
       cout << "You won!!" << endl;
     } else if (randomCP == myCollection.at(choosePoke).GetCP()) {
       cout << "It's a tie." << endl;
     }
   } else {
   }
}

 void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int choosePoke;
   cout << "Which of your pokemon would you like to use?: " << endl;
   for (int i = 0; i < (int)myCollection.size(); i++) {
     cout << i << "." << " " << myCollection.at(i).GetNum() << " " << myCollection.at(i).GetName() << " " << myCollection.at(i).GetCP() << " " << myCollection.at(i).GetHP() << " " << myCollection.at(i).GetRarity() << endl;
   }
   cin >> choosePoke;
   if (choosePoke >= 0 && choosePoke <= ((int)myCollection.size()-1)) {
     //trains the Pokemon by adding 10 cp to its cp count
     myCollection.at(choosePoke).Train();
     if (myCollection.at(choosePoke).GetCP() >= pokeDex.at(myCollection.at(choosePoke).GetNum()).GetCPMax()) {
       myCollection.at(choosePoke).SetCP(pokeDex.at(myCollection.at(choosePoke).GetNum()).GetCPMax());
       cout << "Your " << myCollection.at(choosePoke).GetName() << " is fully trained." << endl;
     } else {
       cout << "Your " << myCollection.at(choosePoke).GetName() << " trained." << endl;
       cout << "Your CP is now " << myCollection.at(choosePoke).GetCP() << "." << endl;
     }
   } else {
   }
}

 void exitPokemon(vector<MyPokemon> & myCollection){
   saveMyCollection(myCollection);
 }

void saveMyCollection(vector<MyPokemon> & myCollection){
  fstream outputStream;
  outputStream.open("myCollection.txt");
  //outputs each object in myCollection vector to myCollection.txt
  for (int i = 0; i < (int)myCollection.size(); i++) {
    outputStream << myCollection.at(i).GetNum() << " " << myCollection.at(i).GetName() << " " << myCollection.at(i).GetCP() << " " << myCollection.at(i).GetHP() << " " << myCollection.at(i).GetRarity() << "\n";
  }
  outputStream.close();
  cout << "File saved." << endl;
  cout << "Thank you for playing UMBC Pokemon." << endl;
}
