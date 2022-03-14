#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxMistakes=8;
const string WORD_LIST[] = {
 "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
 };
const int Word_number=sizeof(WORD_LIST)/sizeof(string);
const string FIGURE[]={"  -----------------     \n"
                       "   |                    \n"
                       "   |                    \n"
                       "   |                    \n"
                       "   |                    \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |                    \n"
                       "   |                    \n"
                       "   |                    \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |               0    \n"
                       "   |                    \n"
                       "   |                    \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |               0    \n"
                       "   |              /     \n"
                       "   |                    \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |               0    \n"
                       "   |              /|    \n"
                       "   |                    \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |               0    \n"
                       "   |              /|\\  \n"
                       "   |                    \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |               0    \n"
                       "   |              /|\\  \n"
                       "   |              /     \n"
                       " __|__     \n",
                       "  -----------------     \n"
                       "   |               |    \n"
                       "   |               0    \n"
                       "   |              /|\\  \n"
                       "   |              / \\  \n"
                       " __|__     \n"};
bool check(string s,char t){
    bool c=false;
    for(int i=0;i<s.size();i++){
        if(s[i]==t){
            c=true;
            break;
        }
    }
    return c;
}
void render_game(string guessedWord,int countMistakes){
    cout<<FIGURE[countMistakes]<<endl;
    cout<<guessedWord<<endl;
    cout<<"Number of wrong guesses: "<<countMistakes<<endl;
}
string chooseWord(){
    srand(time(NULL));
    int random=rand() % Word_number;
    return WORD_LIST[random];
}
string update(string a,string b,char t){
    for(int i=0;i<b.size();i++){
        if(b[i]==t){
            a[i]=t;
        }
    }
    return a;
}
char guessWord(){
    char a;
    cout<<"please choose a letter: ";
    cin>>a;
    return a;
}
int main(){
    string secretWord=chooseWord();
    string guessedWord="";
    for(int i=0;i<secretWord.size();i++){
        guessedWord='-'+guessedWord;
    }
    int countMistakes=0;
    do{
        char guess=guessWord();
        if(check(secretWord,guess)) {
            guessedWord=update(guessedWord,secretWord,guess);
        }
        else {
            countMistakes++;
            cout<<"You are wrong!"<<endl;
        }
        render_game(guessedWord,countMistakes);
    }while((countMistakes<maxMistakes)&&(secretWord!=guessedWord));
    if(countMistakes<maxMistakes) cout<<"Congratulation! You win!";
    else cout<<"Game over!";
}