#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Question {
    string question;
    string options[4];
    int correctAnswer;
};

void displayMenu();
//The startQuiz function takes Question (array of questions, answers and right answer), int (number of questions), string(names of Players 1 and 2) and bool (whether there is 1 or 2 players playing) as parameters
void startQuiz(Question[],int, string, string, bool);
int getValidInput(int, int);

Question celebrityQuestions[] = {
    {"Which celebrity has a PhD in neuroscience?", {"1. Mayim Bialik", "2. Natalie Portman", "3. Emma Watson", "4. Angelina Jolie"}, 1},
    {"Which actor is also a licensed pilot?", {"1. Tom Cruise", "2. Brad Pitt", "3. Morgan Freeman", "4. Harrison Ford"}, 4},
    {"Which musician can solve a Rubik's Cube in under a minute?", {"1. Shawn Mendes", "2. Ed Sheeran", "3. Justin Bieber", "4. Harry Styles"}, 3},
    {"Which celebrity was once a firefighter?", {"1. Steve Buscemi", "2. Robert De Niro", "3. Al Pacino", "4. Bruce Willis"}, 1},
    {"Which actor worked as a lion tamer before becoming famous?", {"1. Hugh Jackman", "2. Christopher Walken", "3. Keanu Reeves", "4. Johnny Depp"}, 2},
    {"Which pop star is the godmother of both of Elton John's sons?", {"1. Rihanna", "2. Beyonce", "3. Katy Perry", "4. Lady Gaga"}, 4},
    {"Which artist made history in 2020 as the youngest winner of the Grammy's four main categories?", {"1. Billie Eilish", "2. Sabrina Carpenter", "3. Olivia Rodrigo", "4. Rosalia"}, 1},
    {"How are Julia Roberts and Emma Roberts related?", {"1. Sisters", "2. Mother & Daughter", "3. Aunt & Niece", "4. Not really related"}, 3},
    {"Which name is not one of Kim Kardashian and Kanye West children?", {"1. Saint", "2. East", "3. Chicago", "4. Psalm"}, 2},
    {"Which personality is Hailey Bieber's father?", {"1. Stephen Baldwin", "2. Alec Baldwin", "3. Chris Baldwin", "4. George Baldwin"}, 1}
};

Question seriesQuestions[] = {
    {"Which actor played Walter White in Breaking Bad?", {"1. Bryan Cranston", "2. Aaron Paul", "3. Bob Odenkirk", "4. Dean Norris"}, 1},
    {"In Friends, what is the name of Ross's second wife?", {"1. Carol", "2. Rachel", "3. Emily", "4. Janice"}, 3},
    {"Which series features the character Tyrion Lannister?", {"1. The Witcher", "2. Game of Thrones", "3. Vikings", "4. The Mandalorian"}, 2},
    {"Which actor portrays Sherlock Holmes in the BBC series?", {"1. Jonny Lee Miller", "2. Benedict Cumberbatch", "3. Robert Downey Jr.", "4. Henry Cavill"}, 2},
    {"What is the name of the coffee shop in Friends?", {"1. Central Perk", "2. Café Roma", "3. Java Junction", "4. Coffee Hub"}, 1},
    {"What is the name of the leading male role in Mentalist?", {"1. Simon Baker", "2. Denis Abott", "3. Sam Bosco", "4. Patrick Jane"}, 4},
    {"Who plays Eleven in Stranger Things?", {"1. Kiera Knightley", "2. Sabrina Carpenter", "3. Millie Bobby Brown", "4. Jenna Ortega"}, 3},
    {"Which actress played Meredith Grey in Grey's Anatomy?", {"1. Chandra Wilson", "2. Ellen Pompeo", "3. Katherine Heigl", "4. Sandra Oh"}, 2},
    {"Which character did not appeared in The Big Bang Theory?", {"1. Léonard Hofstadter", "2. Amy Farrah Fowler", "3. Howard Wolowitz", "4. Sara Champolion"}, 4},
    {"Whom did Barney end up marrying in How I Met Your Mother?", {"1. Ashley", "2. Penny", "3. Robin", "4. Victoria"}, 3}
};

Question movieQuestions[] = {
    {"Who directed the movie 'Inception'?", {"1. Christopher Nolan", "2. Steven Spielberg", "3. Quentin Tarantino", "4. James Cameron"}, 1},
    {"Which movie won the Best Picture Oscar in 2025?", {"1. Conclave", "2. Emilia Pérez", "3. Anora", "4. The Brutalist"}, 3},
    {"Who played Jack Dawson in Titanic?", {"1. Brad Pitt", "2. Leonardo DiCaprio", "3. Tom Cruise", "4. Johnny Depp"}, 2},
    {"Which movie features the famous line 'I am your father'?", {"1. The Matrix", "2. Star Wars: The Empire Strikes Back", "3. Lord of the Rings", "4. Avengers"}, 2},
    {"Which film franchise features a character named Ethan Hunt?", {"1. James Bond", "2. Mission Impossible", "3. Fast & Furious", "4. Bourne Identity"}, 2},
    {"Which actor played the role of Iron Man in the Marvel Cinematic Universe?", {"1. Mark Ruffalo", "2. Chris Evans", "3. Sebastian Stan", "4. Robert Downer Jr."}, 4},
    {"In which film are George Clooney, Matt Damon and Brad Pitt together?", {"1. Fight Club", "2. Se7en", "3. Ocean's Eleven", "4. Inglorious Bastards"}, 3},
    {"Who is not an EGOT winner (Emmy, Grammy, Oscar, Tony)?", {"1. Audrey Hepburn", "2. Whoopi Goldberg", "3. Maggie Smith", "4. Viola Davis"}, 3},
    {"Which actor has never won an oscar ?", {"1. Ralph Fiennes", "2. Ben Affleck", "3. Cilian Murphy", "4. Adrian Brody"}, 1},
    {"Who played Professor X in the X-men films?", {"1. Michael Fassbender", "2. Hugh Jackman", "3. James Marsden", "4. James McAvoy"}, 4}
};

Question politicsQuestions[] = {
    {"Who was the 44th President of the United States?", {"1. George W. Bush", "2. Barack Obama", "3. Donald Trump", "4. Bill Clinton"}, 2},
    {"Which British Prime Minister served the longest in the 20th century?", {"1. Winston Churchill", "2. Margaret Thatcher", "3. Tony Blair", "4. Harold Wilson"}, 2},
    {"Who was the first President of the United States?", {"1. Thomas Jefferson", "2. John Adams", "3. George Washington", "4. Abraham Lincoln"}, 3},
    {"Which country has the largest democracy in the world?", {"1. USA", "2. India", "3. Canada", "4. Brazil"}, 2},
    {"Who was the first female Chancellor of Germany?", {"1. Angela Merkel", "2. Theresa May", "3. Golda Meir", "4. Margaret Thatcher"}, 1},
    {"Which celebrity became the governor of California?", {"1. Chris Pratt", "2. Dwayne Johnson", "3. Al Pacino", "4. Arnold Schwarzenegger"}, 4},
    {"Which country had the first ever female President?", {"1. Mexico", "2. France", "3. Ireland", "4. Iceland"}, 4},
    {"Which country was the last to join the EU?", {"1. Croatia", "2. Poland", "3. France", "4. Switzerland"}, 1},
    {"Who is the current prime minister of Ireland?", {"1. Andrew Scott", "2. Daniel O'Connell", "3. Micheál Martin", "4. Simon Harris"}, 3},
    {"Who is the current King of Spain?", {"1. Felipe VI", "2. Juan Carlos I", "3. Alfonso II", "4. Juan Pablo IV"}, 1}
};

Question musicQuestions[] = {
    {"What is Michael Jackson's nickname?",{"1. The King of Rock", "2. The King of Pop", "3. The Prince of Pop", "4. The God of Music"}, 2},
    {"Which artist is known for the song 'Like a Virgin'?",{"1. Madonna", "2. Beyoncé", "3. Lady Gaga", "4. Rihanna"}, 1},
    {"Which band released the album 'The Dark Side of the Moon'?", {"1. The Beatles", "2. Pink Floyd", "3. Led Zeppelin", "4. The Rolling Stones"}, 2},
    {"Which artist released the album 'Thriller'?",{"1. Michael Jackson", "2. Prince", "3. Madonna", "4. Whitney Houston"}, 1},
    {"Which band is known for the song 'Bohemian Rhapsody'?",{"1. Queen", "2. The Beatles", "3. Led Zeppelin", "4. The Rolling Stones"}, 1},
    {"Which artist is known for the song 'Shape of You'?",{"1. Shawn Mendes", "2. Justin Bieber", "3. Ed Sheeran", "4. Bruno Mars"}, 3},
    {"Which band released the album 'Abbey Road'?",{"1. The Rolling Stones", "2. Pink Floyd", "3. Led Zeppelin", "4. The Beatles"}, 4},
    {"Which artist is known for the song 'Rolling in the Deep'?",{"1. Beyoncé", "2. Adele", "3. Lady Gaga", "4. Rihanna"}, 2},
    {"Which band is known for the song 'Hotel California'?",{"1. Eagles", "2. Fleetwood Mac", "3. The Doors", "4. The Who"}, 1},
    {"Which artist is known for the song 'Billie Jean'?",{"1. Prince", "2. Michael Jackson", "3. Madonna", "4. Whitney Houston"}, 2}
};

Question AllQuestions[] = {
    {"Which celebrity has a PhD in neuroscience?", {"1. Mayim Bialik", "2. Natalie Portman", "3. Emma Watson", "4. Angelina Jolie"}, 1},
    {"Which actor is also a licensed pilot?", {"1. Tom Cruise", "2. Brad Pitt", "3. Morgan Freeman", "4. Harrison Ford"}, 4},
    {"Which musician can solve a Rubik's Cube in under a minute?", {"1. Shawn Mendes", "2. Ed Sheeran", "3. Justin Bieber", "4. Harry Styles"}, 3},
    {"Which celebrity was once a firefighter?", {"1. Steve Buscemi", "2. Robert De Niro", "3. Al Pacino", "4. Bruce Willis"}, 1},
    {"Which actor worked as a lion tamer before becoming famous?", {"1. Hugh Jackman", "2. Christopher Walken", "3. Keanu Reeves", "4. Johnny Depp"}, 2},
    {"Which pop star is the godmother of both of Elton John's sons?", {"1. Rihanna", "2. Beyonce", "3. Katy Perry", "4. Lady Gaga"}, 4},
    {"Which artist made history in 2020 as the youngest winner of the Grammy's four main categories?", {"1. Billie Eilish", "2. Sabrina Carpenter", "3. Olivia Rodrigo", "4. Rosalia"}, 1},
    {"How are Julia Roberts and Emma Roberts related?", {"1. Sisters", "2. Mother & Daughter", "3. Aunt & Niece", "4. Not really related"}, 3},
    {"Which name is not one of Kim Kardashian and Kanye West children?", {"1. Saint", "2. East", "3. Chicago", "4. Psalm"}, 2},
    {"Which personality is Hailey Bieber's father?", {"1. Stephen Baldwin", "2. Alec Baldwin", "3. Chris Baldwin", "4. George Baldwin"}, 1},
    {"Which actor played Walter White in Breaking Bad?", {"1. Bryan Cranston", "2. Aaron Paul", "3. Bob Odenkirk", "4. Dean Norris"}, 1},
    {"In Friends, what is the name of Ross's second wife?", {"1. Carol", "2. Rachel", "3. Emily", "4. Janice"}, 3},
    {"Which series features the character Tyrion Lannister?", {"1. The Witcher", "2. Game of Thrones", "3. Vikings", "4. The Mandalorian"}, 2},
    {"Which actor portrays Sherlock Holmes in the BBC series?", {"1. Jonny Lee Miller", "2. Benedict Cumberbatch", "3. Robert Downey Jr.", "4. Henry Cavill"}, 2},
    {"What is the name of the coffee shop in Friends?", {"1. Central Perk", "2. Café Roma", "3. Java Junction", "4. Coffee Hub"}, 1},
    {"What is the name of the leading male role in Mentalist?", {"1. Simon Baker", "2. Denis Abott", "3. Sam Bosco", "4. Patrick Jane"}, 4},
    {"Who plays Eleven in Stranger Things?", {"1. Kiera Knightley", "2. Sabrina Carpenter", "3. Millie Bobby Brown", "4. Jenna Ortega"}, 3},
    {"Which actress played Meredith Grey in Grey's Anatomy?", {"1. Chandra Wilson", "2. Ellen Pompeo", "3. Katherine Heigl", "4. Sandra Oh"}, 2},
    {"Which character did not appeared in The Big Bang Theory?", {"1. Léonard Hofstadter", "2. Amy Farrah Fowler", "3. Howard Wolowitz", "4. Sara Champolion"}, 4},
    {"Whom did Barney end up marrying in How I Met Your Mother?", {"1. Ashley", "2. Penny", "3. Robin", "4. Victoria"}, 3},
    {"Who directed the movie 'Inception'?", {"1. Christopher Nolan", "2. Steven Spielberg", "3. Quentin Tarantino", "4. James Cameron"}, 1},
    {"Which movie won the Best Picture Oscar in 2025?", {"1. Conclave", "2. Emilia Pérez", "3. Anora", "4. The Brutalist"}, 3},
    {"Who played Jack Dawson in Titanic?", {"1. Brad Pitt", "2. Leonardo DiCaprio", "3. Tom Cruise", "4. Johnny Depp"}, 2},
    {"Which movie features the famous line 'I am your father'?", {"1. The Matrix", "2. Star Wars: The Empire Strikes Back", "3. Lord of the Rings", "4. Avengers"}, 2},
    {"Which film franchise features a character named Ethan Hunt?", {"1. James Bond", "2. Mission Impossible", "3. Fast & Furious", "4. Bourne Identity"}, 2},
    {"Which actor played the role of Iron Man in the Marvel Cinematic Universe?", {"1. Mark Ruffalo", "2. Chris Evans", "3. Sebastian Stan", "4. Robert Downer Jr."}, 4},
    {"In which film are George Clooney, Matt Damon and Brad Pitt together?", {"1. Fight Club", "2. Se7en", "3. Ocean's Eleven", "4. Inglorious Bastards"}, 3},
    {"Who is not an EGOT winner (Emmy, Grammy, Oscar, Tony)?", {"1. Audrey Hepburn", "2. Whoopi Goldberg", "3. Maggie Smith", "4. Viola Davis"}, 3},
    {"Which actor has never won an oscar ?", {"1. Ralph Fiennes", "2. Ben Affleck", "3. Cilian Murphy", "4. Adrian Brody"}, 1},
    {"Who played Professor X in the X-men films?", {"1. Michael Fassbender", "2. Hugh Jackman", "3. James Marsden", "4. James McAvoy"}, 4},
    {"Who was the 44th President of the United States?", {"1. George W. Bush", "2. Barack Obama", "3. Donald Trump", "4. Bill Clinton"}, 2},
    {"Which British Prime Minister served the longest in the 20th century?", {"1. Winston Churchill", "2. Margaret Thatcher", "3. Tony Blair", "4. Harold Wilson"}, 2},
    {"Who was the first President of the United States?", {"1. Thomas Jefferson", "2. John Adams", "3. George Washington", "4. Abraham Lincoln"}, 3},
    {"Which country has the largest democracy in the world?", {"1. USA", "2. India", "3. Canada", "4. Brazil"}, 2},
    {"Who was the first female Chancellor of Germany?", {"1. Angela Merkel", "2. Theresa May", "3. Golda Meir", "4. Margaret Thatcher"}, 1},
    {"Which celebrity became the governor of California?", {"1. Chris Pratt", "2. Dwayne Johnson", "3. Al Pacino", "4. Arnold Schwarzenegger"}, 4},
    {"Which country had the first ever female President?", {"1. Mexico", "2. France", "3. Ireland", "4. Iceland"}, 4},
    {"Which country was the last to join the EU?", {"1. Croatia", "2. Poland", "3. France", "4. Switzerland"}, 1},
    {"Who is the current prime minister of Ireland?", {"1. Andrew Scott", "2. Daniel O'Connell", "3. Micheál Martin", "4. Simon Harris"}, 3},
    {"Who is the current King of Spain?", {"1. Felipe VI", "2. Juan Carlos I", "3. Alfonso II", "4. Juan Pablo IV"}, 1},
    {"What is Michael Jackson's nickname?",{"1. The King of Rock", "2. The King of Pop", "3. The Prince of Pop", "4. The God of Music"}, 2},
    {"Which artist is known for the song 'Like a Virgin'?",{"1. Madonna", "2. Beyoncé", "3. Lady Gaga", "4. Rihanna"}, 1},
    {"Which band released the album 'The Dark Side of the Moon'?", {"1. The Beatles", "2. Pink Floyd", "3. Led Zeppelin", "4. The Rolling Stones"}, 2},
    {"Which artist released the album 'Thriller'?",{"1. Michael Jackson", "2. Prince", "3. Madonna", "4. Whitney Houston"}, 1},
    {"Which band is known for the song 'Bohemian Rhapsody'?",{"1. Queen", "2. The Beatles", "3. Led Zeppelin", "4. The Rolling Stones"}, 1},
    {"Which artist is known for the song 'Shape of You'?",{"1. Shawn Mendes", "2. Justin Bieber", "3. Ed Sheeran", "4. Bruno Mars"}, 3},
    {"Which band released the album 'Abbey Road'?",{"1. The Rolling Stones", "2. Pink Floyd", "3. Led Zeppelin", "4. The Beatles"}, 4},
    {"Which artist is known for the song 'Rolling in the Deep'?",{"1. Beyoncé", "2. Adele", "3. Lady Gaga", "4. Rihanna"}, 2},
    {"Which band is known for the song 'Hotel California'?",{"1. Eagles", "2. Fleetwood Mac", "3. The Doors", "4. The Who"}, 1},
    {"Which artist is known for the song 'Billie Jean'?",{"1. Prince", "2. Michael Jackson", "3. Madonna", "4. Whitney Houston"}, 2}
};

//startRandomQuiz allows the player(s) to play with questions from different subtopics and allows them to choose the number of questions
void startRandomQuiz(string player1, string player2, bool twoPlayers) {
    int numQuestions;
    cout << "How many questions do you want to play with? (1 - 50): ";
    numQuestions = getValidInput(1, 50); //50 questions in total so input number can not exceed 50
    
    //Array to store the index of the used questions
    bool usedQuestions[50] = {false}; 
    
    Question selectedQuestions[numQuestions];

    //loop to select all the questions that will be asked
    for (int i = 0; i < numQuestions; ++i) {
        int randomIndex;
        //Loop to ensure that the index has not already been selected
        do {
            randomIndex = rand() % 50;  
        } while (usedQuestions[randomIndex]);

        usedQuestions[randomIndex] = true;
        
        selectedQuestions[i] = AllQuestions[randomIndex];
    }

    // Start the quiz with the randomly selected questions
    startQuiz(selectedQuestions, numQuestions, player1, player2, twoPlayers);
}

int main() {
    displayMenu();
    return 0;
}

//displayMenuMenu function allows the smooth running of the program
void displayMenu() {
    int choiceMode;
    string player1, player2;

    //First, user select the number of players (1 or 2)
    cout << "\033[36mSelect mode:\033[0m\n1. Single Player\n2. Two Players\n\033[36mEnter your choice: \033[0m";
    choiceMode = getValidInput(1, 2);

    cout << "\033[33mEnter Player 1 name: \033[0m";
    cin >> player1;
    cout <<"Welcome, "<<player1<<" !\n";

    bool twoPlayers = (choiceMode == 2);
    if (twoPlayers) {
        cout << "\033[33mEnter Player 2 name: \033[0m";
        cin >> player2;
        cout <<"Welcome, "<<player2<<" !\n";
    }
    
    //Switch to choose the different subtopics
    int choice;
    do {
        cout << "\n\033[35mSelect your topic:\033[0m\n";
        cout << "1. Celebrity Fun Facts\n";
        cout << "2. TV Series\n";
        cout << "3. Movies\n";
        cout << "4. Politics\n";
        cout << "5. Music\n";
        cout << "6. Random subject\n"; //Added option : generate a random number between 1 and 5
        cout << "7. Random questions (all subjects)\n"; //Added option : player(s) answer to Random questions from various subtopics
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        
        choice = getValidInput(1, 8);

        switch (choice) {
            case 1:
                startQuiz(celebrityQuestions, 10, player1, player2, twoPlayers);
                break;
            case 2:
                startQuiz(seriesQuestions, 10, player1, player2, twoPlayers);
                break;
            case 3:
                startQuiz(movieQuestions, 10, player1, player2, twoPlayers);
                break;
            case 4:
                startQuiz(politicsQuestions,10, player1, player2, twoPlayers);
                break;
            case 5:
                startQuiz(musicQuestions, 10,player1, player2, twoPlayers);
                break;
            case 6:
                cout<<"\nIt will be... ";
                int randomNum;
                randomNum= rand() % 5 + 1; //rand() % 5 + 1 ensure that the random number is an integer between 1 and 5
                switch (randomNum){
                    case 1:
                        cout<<"Celebrity Fun Facts !";
                        startQuiz(celebrityQuestions, 10,player1, player2, twoPlayers);
                        break;
                    case 2:
                        cout<<"TV Series !";
                        startQuiz(seriesQuestions, 10,player1, player2, twoPlayers);
                        break;
                    case 3:
                        cout<<"Movies !";
                        startQuiz(movieQuestions, 10,player1, player2, twoPlayers);
                        break;
                    case 4:
                        cout<<"Politics !";
                        startQuiz(politicsQuestions, 10,player1, player2, twoPlayers);
                        break;
                    case 5:
                        cout<<"Music !";
                        startQuiz(musicQuestions, 10,player1, player2, twoPlayers);
                        break;
                }
                break;
            case 7: 
                startRandomQuiz(player1, player2, twoPlayers);            
                break;
            case 8:
                cout << "Thank you for playing!\n";
                break;
        }
    } while (choice != 8);
}

//startQuiz function allows the user to answer smoothly to the quizz
void startQuiz(Question questions[], int numQuestions, string player1, string player2, bool twoPlayers) {
    int score1 = 0, score2 = 0;
    int nbQuestion1 = 0, nbQuestion2 = 0;

    for (size_t i = 0; i < numQuestions; i++) {
        cout << "\n\033[34m" << i + 1 << ". " << questions[i].question << "\n\033[0m";
        for (const string &option : questions[i].options) {
            cout << option << "\n";
        }

        if (!twoPlayers || i % 2 == 0) {
            cout << "\n" << player1 << ", it's your turn!\nPlease choose an option between 1 and 4: ";
            int answer1 = getValidInput(1, 4);
            nbQuestion1++;
            if (answer1 == questions[i].correctAnswer) {
                cout << "\033[32mCorrect!\033[0m\n";
                score1++;
            } else {
                cout << "\033[31mSorry... The correct answer was " << questions[i].correctAnswer << ".\033[0m\n";
            }
        } else {
            cout << "\n" << player2 << ", it's your turn!\nPlease choose an option between 1 and 4: ";
            int answer2 = getValidInput(1, 4);
            nbQuestion2++;
            if (answer2 == questions[i].correctAnswer) {
                cout << "\033[32mCorrect!\033[0m\n";
                score2++;
            } else {
                cout << "\033[31mSorry... The correct answer was " << questions[i].correctAnswer << ".\033[0m\n";
            }
        }
    }
    
    //At the end of the game, scores are displayed
    cout << "\n\033[33mFinal Scores:\033[0m\n";
    float nbRight1 = (float) score1 / nbQuestion1;
    float mark1 = nbRight1 * 100;

    cout << player1 << ": " << score1 << "/" << nbQuestion1 << "\n";

    if (mark1 > 60) {
        cout << "Congrats " << player1 << ", you passed!\n";
    } 
    else if (mark1<=60) {
        cout << "Sorry " << player1 << ", you failed...\n";
    }

    if (twoPlayers) {
        float nbRight2 = (float) score2 / nbQuestion2;
        float mark2 = nbRight2 * 100;
        cout << player2 << ": " << score2 << "/" << nbQuestion2 << "\n";
    
    if (mark2 > 60) {
        cout << "Congrats " << player2 << ", you passed!\n";
    } 
    else {
        cout << "Sorry " << player2 << ", you failed...\n";
    }

    if (mark1 > mark2) {
        cout << "\033[32m" << player1 << " wins!\033[0m Sorry " << player2 << ", better luck next time!" << "\n";
    } 
    else if (mark2 > mark1) {
        cout << "\033[32m" << player2 << " wins!\033[0m Sorry " << player1 << ", better luck next time!" << "\n";
    } 
    else {
        cout << "\033[33mIt's a tie, you both win!\033[0m\n";
    }
}


}

//Function to ensure the users enters a valid number in the list of valid options (1-2; 1-8)
int getValidInput(int min, int max) {
    int input;
    //Loop to ask the user until he enters a valid number
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[31mInvalid input. Please enter a number between " << min << " and " << max << ": \033[0m";
        } else {
            break;
        }
    }
    return input;
}
